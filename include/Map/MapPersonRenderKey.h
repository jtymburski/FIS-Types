/**
 * @class MapPersonRenderKey
 *
 * Immutable render key for the map person sprite matrix objects. This is all dimensions that
 * will differ when rendering the person on map.
 */
#ifndef CORE_MAPPERSONRENDERKEY_H
#define CORE_MAPPERSONRENDERKEY_H

#include <functional>

#include "Foundation/Direction.h"
#include "Map/Surface.h"

namespace core
{
  class MapPersonRenderKey
  {
  public:
    /* Object constructor */
    MapPersonRenderKey(Surface surface, Direction direction);

  private:
    /* Facing direction */
    Direction direction;

    /* Map surface of the tile the person is standing */
    Surface surface;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Fetches the key facing direction */
    Direction getDirection() const;

    /* Fetches the map surface of the person location identifier */
    Surface getSurface() const;

  /*=============================================================================
   * OPERATOR FUNCTIONS
   *============================================================================*/
  public:
    bool operator==(const MapPersonRenderKey& rhs) const;
  };
};

/**
 * Custom hash implementation for the key. It should leverage all available fields that
 * define the unique object.
 */
namespace std
{
  template <>
  struct hash<core::MapPersonRenderKey>
  {
    size_t operator()(const core::MapPersonRenderKey& key) const
    {
      std::size_t h1 = std::hash<core::Direction>{}(key.getDirection());
      std::size_t h2 = std::hash<core::Surface>{}(key.getSurface());
      return h1 ^ (h2 << 4);
    }
  };
}

#endif // CORE_MAPPERSONRENDERKEY_H
