/**
 * @class ConversationEntry
 *
 * The conversation entry is a single node in the entry decision tree. It is the base abstract
 * definition which can easily be extended to handle various entry use cases
 */
#include "Event/Conversation/ConversationEntry.h"
using namespace core;

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Default constructor.
 */
ConversationEntry::ConversationEntry() {}

/**
 * Copy constructor, duplicates the existing source in new memory.
 * @param source object to copy
 */
ConversationEntry::ConversationEntry(const ConversationEntry& source)
{
  cloneSource(source);
}

/**
 * Destructor function, cleans up any dynamically assigned memory managed in the class.
 */
ConversationEntry::~ConversationEntry()
{
  deleteNextEntries();
}

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Copy function. This duplicates (new memory) the source objects and replaces them in the
 * existing class. All existing objects will be overriden.
 * @param source object to copy
 */
void ConversationEntry::cloneSource(const ConversationEntry& source)
{
  deleteNextEntries();
  for(auto entry : source.next_entries)
    next_entries.push_back(entry->clone());
}

/**
 * Deletes all next entry references in the list and clears it. After execution,
 * no entries will remain.
 */
void ConversationEntry::deleteNextEntries()
{
  for(auto &entry : next_entries)
    delete entry;
  next_entries.clear();
}

/**
 * Pad set of next entries up to the index using the filler. This will copy the filler
 * as many times as needed. This is up to but exclusive of the index location.
 * @param index ordered vector location for how far to fill
 * @param filler_entry padding entry to insert if there is gaps in the vector between the index
 */
void ConversationEntry::padNextEntries(uint8_t index, ConversationEntry& filler_entry)
{
  while(next_entries.size() < index)
  {
    // Copy filler entry
    ConversationEntry* new_filler_entry;
    *new_filler_entry = filler_entry;

    // Add to the back
    next_entries.push_back(new_filler_entry);
  }
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deletes a single entry following this entry at the given index in the vector. If there is no
 * entry at the index, this is a no-op.
 * @param index ordered vector location
 */
void ConversationEntry::deleteNextEntry(uint8_t index)
{
  if(index < next_entries.size())
  {
    delete next_entries.at(index);
    next_entries.erase(next_entries.begin() + index);
  }
}

/**
 * Returns a single entry following this entry at the given index in the vector.
 * @param index ordered vector location
 * @return entry reference at the given index. will throw exception if out of range
 */
ConversationEntry& ConversationEntry::getNextEntry(uint8_t index) const
{
  if(index >= next_entries.size())
    throw std::out_of_range("Conversation entry index=" + std::to_string(index) +
                            " is out of range in getNextEntry()");
  return *next_entries.at(index);
}

/**
 * Returns the number of next entries linked to this entry in the vector.
 * @return total number of next entries available
 */
uint8_t ConversationEntry::getNextEntryCount() const
{
  return next_entries.size();
}

/**
 * Inserts a single entry following this entry at the given index in the vector. It will insert
 * copies of {@param filler_entry} in between if there is gaps in the vector.
 * @param index ordered vector location, inserts at pushing the current index value back one
 * @param entry new entry reference to insert in the vector
 * @param filler_entry padding entry to insert if there is gaps in the vector between the index
 */
void ConversationEntry::insertNextEntry(uint8_t index, ConversationEntry& entry,
                                        ConversationEntry& filler_entry)
{
  // If this is inserting an index at first spot and there's only one currently in the entry,
  // push the entry deeper in the tree instead of adding it as an option
  if(index == 0 && getNextEntryCount() == 1)
  {
    entry.setNextEntry(index, getNextEntry(index), filler_entry);
    next_entries.clear();
    setNextEntry(index, entry, filler_entry);
  }
  // Otherwise, it should be just added to the existing entry
  else
  {
    padNextEntries(index, filler_entry);
    next_entries.insert(next_entries.begin() + index, &entry);
  }
}

/**
 * Sets a single entry following this entry at the given index in the vector. It will
 * insert copies of {@param filler_entry} in between if there is gaps in the vector.
 * @param index ordered vector location
 * @param entry new entry reference to insert or replace in the vector
 * @param filler_entry padding entry to insert if there is gaps in the vector between the index
 */
void ConversationEntry::setNextEntry(uint8_t index, ConversationEntry& entry,
                                     ConversationEntry& filler_entry)
{
  padNextEntries(index, filler_entry);

  // If the index is at the end, just add to the back
  if(next_entries.size() == index)
  {
    next_entries.push_back(&entry);
  }
  // Otherwise, replace the current index with the new entry
  else
  {
    entry.next_entries = next_entries[index]->next_entries;
    next_entries[index]->next_entries.clear();

    delete next_entries[index];
    next_entries[index] = &entry;
  }
}

/*=============================================================================
 * OPERATOR FUNCTIONS
 *============================================================================*/

/**
 * Copy assignment operator, duplicates the existing source in new memory.
 * @param source object to copy
 * @return copied object, new memory
 */
ConversationEntry& ConversationEntry::operator=(const ConversationEntry& source)
{
  if(&source != this)
    cloneSource(source);
  return *this;
}
