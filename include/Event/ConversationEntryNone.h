/**
 * @class ConversationEntryNone
 *
 * A no-op conversation entry that should not be displayed. If at the end of a sequence,
 * the conversation should end.
 */
#ifndef CORE_CONVERSATIONENTRYNONE_H
#define CORE_CONVERSATIONENTRYNONE_H

#include "Event/ConversationEntry.h"
#include "Event/ConversationEntryType.h"

namespace core
{
  class ConversationEntryNone : public ConversationEntry
  {
  public:
    /* Returns entry type classification */
    ConversationEntryType getType() const override;
  };
};

#endif // CORE_CONVERSATIONENTRYNONE_H
