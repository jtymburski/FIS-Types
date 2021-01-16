/**
 * @class ConversationEntryNone
 *
 * A no-op conversation entry that should not be displayed. If at the end of a sequence,
 * the conversation should end.
 */
#ifndef CORE_CONVERSATIONENTRYNONE_H
#define CORE_CONVERSATIONENTRYNONE_H

#include "Event/Conversation/ConversationEntry.h"
#include "Event/Conversation/ConversationEntryType.h"

namespace core
{
  class ConversationEntryNone : public ConversationEntry
  {
  public:
    /* Deep clones the entry to return a new memory space version of the same data */
    ConversationEntry* clone() const override;

    /* Returns entry type classification */
    ConversationEntryType getType() const override;

    /* Returns if the conversation entry can be saved */
    bool isSaveable() const override;

    /* Loads conversation entry data from the XML entry */
    void load(XmlData data, int index) override;

    /* Saves all conversation entry data into the XML writer */
    void save(XmlWriter* writer) const override;
  };
};

#endif // CORE_CONVERSATIONENTRYNONE_H
