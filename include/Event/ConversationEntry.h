/**
 * @class ConversationEntry
 *
 * The conversation entry is a single node in the entry decision tree. It is the base abstract
 * definition which can easily be extended to handle various entry use cases
 */
#ifndef CORE_CONVERSATIONENTRY_H
#define CORE_CONVERSATIONENTRY_H

#include "Event/ConversationEntryType.h"

namespace core
{
  class ConversationEntry
  {
  public:
    /* Destructor function of the implementation */
    virtual ~ConversationEntry() = 0;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the entry type classification of the implementation */
    virtual ConversationEntryType getType() const = 0;
  };
};

#endif // CORE_CONVERSATIONENTRY_H
