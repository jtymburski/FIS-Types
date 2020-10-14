/**
 * @class EventType
 *
 * Enumerator defining the conversation entry type classification which defines the subsets
 * of options available as single encapsulated displays.
 */
#ifndef CORE_CONVERSATIONENTRYTYPE_H
#define CORE_CONVERSATIONENTRYTYPE_H

#include <cstdint>

namespace core
{
  enum class ConversationEntryType : std::uint8_t
  {
    NONE
  };
};

#endif // CORE_CONVERSATIONENTRYTYPE_H
