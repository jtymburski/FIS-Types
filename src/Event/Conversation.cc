/**
 * @class Conversation
 *
 * A conversation is one fully contained set of entries that are displayed to communicate
 * to the player through a dynamic content presentation system.
 */
#include "Event/Conversation.h"
using namespace core;

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
 * Create the first entry, if one doesn't exist. The first entry should always exist, be a
 * valid object, and stored inside the root entry.
 */
void Conversation::createFirstEntry()
{
  if(root_entry->getNextEntryCount() == 0)
  {
    ConversationEntry* first_entry = new ConversationEntryNone();
    root_entry->setNextEntry(0, *first_entry, *first_entry);
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
 * @param filler_entry padding to fill in the gaps if the address references non-existing entries
 * @param previous_entry previous conversation entry in the tree
 * @param index full tree entry address
 * @param group_max maximum group to fetch from index address. This can be used to stop the fetch
 *                  early.  For example, index.groupCount() - 1 would fetch the second last entry.
 *                  Must be less than or equal to index.groupCount()
 * @param group index of the entry address value that is currently being processed. Default 0
 * @return entry reference found at the address
 */
ConversationEntry& Conversation::getOrAddEntry(ConversationEntry& filler_entry,
                                               ConversationEntry& previous_entry,
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
    ConversationEntry* new_entry;
    *new_entry = filler_entry;
    previous_entry.setNextEntry(group_index, *new_entry, filler_entry);
  }

  return getOrAddEntry(filler_entry, previous_entry.getNextEntry(group_index), index,
                       group_max, group + 1);
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

  ConversationEntry* filler_entry = new ConversationEntryNone();
  ConversationEntry& previous_entry = getOrAddEntry(*filler_entry, *root_entry, index, last_group);

  previous_entry.insertNextEntry(index.groupValue(last_group), entry, *filler_entry);

  delete filler_entry;
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

  ConversationEntry* filler_entry = new ConversationEntryNone();
  ConversationEntry& previous_entry = getOrAddEntry(*filler_entry, *root_entry, index, last_group);

  previous_entry.setNextEntry(index.groupValue(last_group), entry, *filler_entry);

  delete filler_entry;
}
