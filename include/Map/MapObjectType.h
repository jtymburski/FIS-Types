/**
 * @class MapObjectType
 *
 * Enumerator defining the categories of map objects, that are available on a game map.
 */
#ifndef CORE_MAPOBJECTTYPE_H
#define CORE_MAPOBJECTTYPE_H

#include <cstdint>

namespace core
{
  enum class MapObjectType : std::uint8_t
  {
    ITEM,
    THING
  };
};

#endif // CORE_MAPOBJECTTYPE_H
