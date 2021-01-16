/**
 * @class Conversation
 *
 * A conversation is one fully contained set of entries that are displayed to communicate
 * to the player through a dynamic content presentation system.
 */
#include "Event/Conversation/Conversation.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string Conversation::kKEY_ENTRY = "entry";
const std::string Conversation::kKEY_ENTRY_ID = "id";
const std::string Conversation::kKEY_ENTRY_LEGACY = "conversation";

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Constructor function, default.
 */
Conversation::Conversation()
{
  createFirstEntry();
}

/**
 * Copy constructor, duplicates the existing source in new memory.
 * @param source object to copy
 */
Conversation::Conversation(const Conversation& source)
{
  cloneSource(source);
}

/**
 * Destructor function, cleans up any dynamically assigned memory managed in the class.
 */
Conversation::~Conversation()
{
  delete root_entry;
}

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Copy function. This duplicates (new memory) the source objects and replaces them in the
 * existing class. All existing objects will be overriden.
 * @param source object to copy
 */
void Conversation::cloneSource(const Conversation& source)
{
  delete root_entry;
  root_entry = source.root_entry->clone();
}

/**
 * Create the first entry, if one doesn't exist. The first entry should always exist, be a
 * valid object, and stored inside the root entry.
 */
void Conversation::createFirstEntry()
{
  if(root_entry->getNextEntryCount() == 0)
  {
    ConversationEntryNone first_entry;
    root_entry->setNextEntry(0, first_entry, first_entry);
  }
}

/**
 * Recursive entry fetch to traverse the tree from previous and return the entry at the index. If
 * the entry doesn't exist, this method will throw an out of range exception.
 * @param previous_entry previous conversation entry in the tree
 * @param index full tree entry address
 * @param group_max maximum group to fetch from index address. This can be used to stop the fetch
 *                  early.  For example, index.groupCount() - 1 would fetch the second last entry.
 *                  Must be less than or equal to index.groupCount()
 * @param group index of the entry address value that is currently being processed. Default 0
 * @return entry reference found at the address
 */
ConversationEntry& Conversation::getEntry(ConversationEntry& previous_entry,
                                          const ConversationEntryIndex& index,
                                          uint16_t group_max, uint16_t group) const
{
  if(group == group_max)
    return previous_entry;
  else if(group > group_max)
    throw std::invalid_argument("Entry index=" + index.toString() +
                                " get exceeded the max for group=" + std::to_string(group) +
                                ", max=" + std::to_string(group_max));

  return getEntry(previous_entry.getNextEntry(index.groupValue(group)), index,
                  group_max, group + 1);
}

/**
 * Recursive entry fetch to traverse the tree from previous and return the entry at the index. If
 * the entry doesn't exist, this method will fill in the gaps.
 * @param previous_entry previous conversation entry in the tree
 * @param index full tree entry address
 * @param group_max maximum group to fetch from index address. This can be used to stop the fetch
 *                  early.  For example, index.groupCount() - 1 would fetch the second last entry.
 *                  Must be less than or equal to index.groupCount()
 * @param group index of the entry address value that is currently being processed. Default 0
 * @return entry reference found at the address
 */
ConversationEntry& Conversation::getOrAddEntry(ConversationEntry& previous_entry,
                                               const ConversationEntryIndex& index,
                                               uint16_t group_max, uint16_t group) const
{
  if(group == group_max)
    return previous_entry;
  else if(group > group_max)
    throw std::invalid_argument("Entry index=" + index.toString() +
                                " getOrAdd exceeded the max for group=" + std::to_string(group) +
                                ", max=" + std::to_string(group_max));

  uint16_t group_index = index.groupValue(group);

  // Make sure the entry has enough next entries to fetch the group value. We can just create
  // the new entry using the filler but it needs to be a new memory reference since it will
  // be managed by the conversation entry parent
  if(group_index >= previous_entry.getNextEntryCount())
  {
    ConversationEntryNone blank_entry;
    previous_entry.setNextEntry(group_index, blank_entry, blank_entry);
  }

  return getOrAddEntry(previous_entry.getNextEntry(group_index), index, group_max, group + 1);
}

/**
 * Saves an individual conversation entry into the XML writer. This is recursive and will continue
 * through all leaf nodes before saving the entire tree.
 * @param writer saving file handler interface
 * @param index the entry index currently being saved
 * @param entry the entry object to save, if it is saveable
 */
void Conversation::save(XmlWriter* writer, const ConversationEntryIndex& index,
                        ConversationEntry& entry) const
{
  // Save the current entry
  if(entry.isSaveable())
  {
    writer->writeElement(kKEY_ENTRY, kKEY_ENTRY_ID, index.toString());
    entry.save(writer);
    writer->jumpToParent();
  }

  // Run through connected leaf nodes
  if(entry.getNextEntryCount() > 0)
  {
    ConversationEntryIndex leaf_index = index.copyAndAddTail();
    for(uint8_t i = 0; i < entry.getNextEntryCount(); i++)
    {
      save(writer, leaf_index, entry.getNextEntry(i));
      leaf_index = leaf_index.copyAndIncrementTail();
    }
  }
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deletes a single entry at the index in the conversation tree. This will also delete all
 * sub-entries off this single entry when deleted.
 * @param index full tree entry address
 */
void Conversation::deleteEntry(const ConversationEntryIndex& index)
{
  if(hasEntry(index))
  {
    uint16_t last_group = index.groupCount() - 1;
    getEntry(*root_entry, index, last_group).deleteNextEntry(index.groupValue(last_group));

    if(index.isRoot())
      createFirstEntry();
  }
}

/**
 * Returns a single entry at the index in the conversation tree.  If the entry doesn't exist,
 * this method will throw an out of range exception.
 * @param index full tree entry address
 * @return entry reference found at the address
 */
ConversationEntry& Conversation::getEntry(const ConversationEntryIndex& index) const
{
  return getEntry(*root_entry, index, index.groupCount());
}

/**
 * Returns the top level, first conversation entry.
 * @return a single conversation entry as a starting point
 */
ConversationEntry& Conversation::getFirstEntry() const
{
  return root_entry->getNextEntry(0);
}

/**
 * Returns if a single valid entry is at the index address in the conversation tree.
 * @param index full tree entry address
 * @return TRUE if the index references a valid entry
 */
bool Conversation::hasEntry(const ConversationEntryIndex& index) const
{
  try
  {
    getEntry(index);
    return true;
  }
  // getEntry(index) could not find an entry at any step in the tree, it will throw out of range
  catch(const std::out_of_range&)
  {
    return false;
  }
}

/**
 * Inserts a single entry at the index in the conversation tree. If the entries in between do not
 * exist, this method will fill in the gaps with {@link ConversationEntryNone}.
 * @param index full tree entry address
 * @param entry new conversation node to add into the tree at the address
 */
void Conversation::insertEntry(const ConversationEntryIndex& index, ConversationEntry& entry)
{
  uint16_t last_group = index.groupCount() - 1;

  ConversationEntry& previous_entry = getOrAddEntry(*root_entry, index, last_group);

  ConversationEntryNone filler_entry;
  previous_entry.insertNextEntry(index.groupValue(last_group), entry, filler_entry);
}

/**
 * Loads conversation data from the XML entry.
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 */
void Conversation::load(XmlData data, int index)
{
  // The legacy index is using the top level of the event (<conversation>) to
  // define the entry identifier. This is to support conversion of legacy save files
  int legacy_index = index - 1;

  // Fetch the string version of the entry index
  int entry_data_index;
  std::string entry_string_id;
  if(data.getElement(index) == kKEY_ENTRY && data.getKey(index) == kKEY_ENTRY_ID)
  {
    entry_data_index = index;
    entry_string_id = data.getKeyValue(index);
  }
  else if(data.getElement(legacy_index) == kKEY_ENTRY_LEGACY &&
          data.getKey(legacy_index) == kKEY_ENTRY_ID)
  {
    entry_data_index = legacy_index;
    entry_string_id = data.getKeyValue(legacy_index);
  }

  // If its a valid index format for the entry, process it and finish the load
  if(ConversationEntryIndex::isValidString(entry_string_id))
  {
    ConversationEntryIndex entry_id(entry_string_id);

    uint16_t last_group = entry_id.groupCount() - 1;
    ConversationEntry& previous_entry = getOrAddEntry(*root_entry, entry_id, last_group);

    // Check that the current entry is a TEXT type (only current supported type). If it isn't,
    // swap it out before loading. Otherwise, just fetch the existing one.
    ConversationEntry* entry_to_load;
    uint8_t last_group_value = entry_id.groupValue(last_group);
    if(previous_entry.getNextEntryCount() <= last_group_value ||
       previous_entry.getNextEntry(last_group_value).getType() != ConversationEntryType::TEXT)
    {
      entry_to_load = new ConversationEntryText();

      ConversationEntryNone filler_entry;
      previous_entry.setNextEntry(last_group_value, *entry_to_load, filler_entry);
    }
    else
    {
      entry_to_load = &previous_entry.getNextEntry(last_group_value);
    }

    // Load the entry details
    entry_to_load->load(data, entry_data_index + 1);
  }
}

/**
 * Saves all conversation data into the XML writer.
 * @param writer saving file handler interface
 */
void Conversation::save(XmlWriter* writer) const
{
  ConversationEntryIndex first_entry_index;
  save(writer, first_entry_index, getFirstEntry());
}

/**
 * Sets a single entry at the index in the conversation tree. If the entries in between do not
 * exist, this method will fill in the gaps with {@link ConversationEntryNone}.
 * @param index full tree entry address
 * @param entry new conversation node to set into the tree at the address
 */
void Conversation::setEntry(const ConversationEntryIndex& index, ConversationEntry& entry)
{
  uint16_t last_group = index.groupCount() - 1;

  ConversationEntry& previous_entry = getOrAddEntry(*root_entry, index, last_group);

  ConversationEntryNone filler_entry;
  previous_entry.setNextEntry(index.groupValue(last_group), entry, filler_entry);
}

/*=============================================================================
 * OPERATOR FUNCTIONS
 *============================================================================*/

/**
 * Copy assignment operator, duplicates the existing source in new memory.
 * @param source object to copy
 * @return copied object, new memory
 */
Conversation& Conversation::operator=(const Conversation& source)
{
  if(&source != this)
    cloneSource(source);
  return *this;
}
