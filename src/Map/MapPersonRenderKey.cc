/**
 * @class MapPersonRenderKey
 *
 * Immutable render key for the map person sprite matrix objects. This is all dimensions that
 * will differ when rendering the person on map.
 */
#include "Map/MapPersonRenderKey.h"
using namespace core;

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Construct the immutable key from the full list of dimensions
 * @param surface map surface of the person render info
 * @param direction facing direction of the person object
 */
MapPersonRenderKey::MapPersonRenderKey(Surface surface, Direction direction)
                  : direction{direction},
                    surface{surface}
{
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Fetches the key facing direction of the map person object.
 * @return direction dimension
 */
Direction MapPersonRenderKey::getDirection() const
{
  return direction;
}

/**
 * Fetches the map surface of the person location identifier.
 * @return surface dimension
 */
Surface MapPersonRenderKey::getSurface() const
{
  return surface;
}

/*============================================================================
 * OPERATOR FUNCTIONS
 *===========================================================================*/

/**
 * Equal to operator definition. This handles equivalence as used for key fetch and dimension
 * comparisons.
 * @param rhs Right hand side of the argument
 * @return TRUE if the underlying key data is the same. FALSE if its different (deep comparison)
 */
bool MapPersonRenderKey::operator== (const MapPersonRenderKey& rhs) const
{
  return this->direction == rhs.direction
      && this->surface == rhs.surface;
}
