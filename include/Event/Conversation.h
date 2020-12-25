/**
 * @class Conversation
 *
 * A conversation is one fully contained set of entries that are displayed to communicate
 * to the player through a dynamic content presentation system.
 */
#ifndef CORE_CONVERSATION_H
#define CORE_CONVERSATION_H

#include "Event/ConversationEntry.h"
#include "Event/ConversationEntryIndex.h"
#include "Event/ConversationEntryNone.h"

namespace core
{
  class Conversation
  {
  public:
    /* Constructor function */
    Conversation();

    /* Destructor function */
    ~Conversation();

  private:
    /* Starting conversation entry, top of the decision tree */
    ConversationEntry* root_entry = new ConversationEntryNone();

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Create the first entry, if one doesn't exist */
    void createFirstEntry();

    /* Recursive entry fetch to traverse the tree and return the entry at the index */
    ConversationEntry& getEntry(ConversationEntry& previous_entry,
                                const ConversationEntryIndex& index,
                                uint16_t group_max, uint16_t group = 0) const;

    /* Recursive entry fetch to traverse the tree and return the entry at the index or create it */
    ConversationEntry& getOrAddEntry(ConversationEntry& filler_entry,
                                     ConversationEntry& previous_entry,
                                     const ConversationEntryIndex& index,
                                     uint16_t group_max, uint16_t group = 0) const;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deletes a single entry at the index in the conversation tree */
    void deleteEntry(const ConversationEntryIndex& index);

    /* Returns a single entry at the index in the conversation tree */
    ConversationEntry& getEntry(const ConversationEntryIndex& index) const;

    /* Returns the top level, first conversation entry */
    ConversationEntry& getFirstEntry() const;

    /* Returns if a single valid entry is at the index in the conversation tree */
    bool hasEntry(const ConversationEntryIndex& index) const;

    /* Inserts a single entry at the index in the conversation tree */
    void insertEntry(const ConversationEntryIndex& index, ConversationEntry& entry);

    /* Sets a single entry at the index in the conversation tree */
    void setEntry(const ConversationEntryIndex& index, ConversationEntry& entry);
  };
};

#endif // CORE_CONVERSATION_H
