/**
 * @class ConversationEntry
 *
 * The conversation entry is a single node in the entry decision tree. It is the base abstract
 * definition which can easily be extended to handle various entry use cases
 */
#ifndef CORE_CONVERSATIONENTRY_H
#define CORE_CONVERSATIONENTRY_H

#include <string>
#include <vector>

#include "Event/ConversationEntryType.h"

namespace core
{
  class ConversationEntry
  {
  public:
    /* Destructor function */
    virtual ~ConversationEntry();

  private:
    /* Set of next entry pointers following the current text entry */
    std::vector<ConversationEntry*> next_entries;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Pad set of next entries up to the index using the filler */
    void padNextEntries(uint8_t index, ConversationEntry& filler_entry);

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deletes a single entry following this entry at the given index in the vector */
    void deleteNextEntry(uint8_t index);

    /* Returns a single entry following this entry at the given index in the vector */
    ConversationEntry& getNextEntry(uint8_t index) const;

    /* Returns the number of next entries linked to this entry in the vector */
    uint8_t getNextEntryCount() const;

    /* Returns the entry type classification of the implementation */
    virtual ConversationEntryType getType() const = 0;

    /* Inserts a single entry following this entry at the given index in the vector */
    void insertNextEntry(uint8_t index, ConversationEntry& entry, ConversationEntry& filler_entry);

    /* Sets a single entry following this entry at the given index in the vector */
    void setNextEntry(uint8_t index, ConversationEntry& entry, ConversationEntry& filler_entry);
  };
};

#endif // CORE_CONVERSATIONENTRY_H
