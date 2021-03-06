/**
 * @class EventType
 *
 * Enumerator defining the event type classification which defines the handling and usage
 * for engine handlers.
 */
#ifndef CORE_EVENTTYPE_H
#define CORE_EVENTTYPE_H

#include <cstdint>

namespace core
{
  enum class EventType : std::uint8_t
  {
    NONE,
    BATTLESTART,
    CONVERSATION,
    ITEMGIVE,
    ITEMTAKE,
    MAPSWITCH,
    MULTIPLE,
    NOTIFICATION,
    PROPERTY,
    SOUND,
    TELEPORT,
    TRIGGERIO,
    UNLOCKIO,
    UNLOCKTHING,
    UNLOCKTILE
  };
};

#endif // CORE_EVENTTYPE_H
