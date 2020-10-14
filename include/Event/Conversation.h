/**
 * @class Conversation
 *
 * A conversation is one fully contained set of entries that are displayed to communicate
 * to the player through a dynamic content presentation system.
 */
#ifndef CORE_CONVERSATION_H
#define CORE_CONVERSATION_H

#include "Event/ConversationEntry.h"
#include "Event/ConversationEntryNone.h"

namespace core
{
  class Conversation
  {
  public:
    /* Destructor function */
    ~Conversation();

  private:
    /* Starting conversation entry, top of the decision tree */
    ConversationEntry* root_entry = new ConversationEntryNone();

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the top level, root conversation entry */
    ConversationEntry& getRootEntry();

    /* Sets the top level, root conversation entry */
    void setRootEntry(ConversationEntry& entry);
  };
};

#endif // CORE_CONVERSATION_H
