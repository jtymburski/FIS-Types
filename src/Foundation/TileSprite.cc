/**
 * @class TileSprite
 *
 * Extends a standard Sprite and adds passability, render depth and any other
 * map specific properties which describes a sprite within a tile stack
 */
#include "Foundation/TileSprite.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * The passability of a single direction when viewed from the center of the tile sprite.
 * @return true if passable, false if blocked
 */
bool TileSprite::getPassability(Direction dir) const
{
  return (this->passability & dir) == dir;
}

/**
 * Depth of rendering when stacked with other tile sprites.
 * @return render order. 0 is the first (lowest) up to variable max of 255
 */
uint8_t TileSprite::getRenderDepth() const
{
  return this->render_depth;
}

/**
 * Sets or clears the passability for a single direction viewed from the center of the
 * tile sprite.
 * @param dir the enumerator that represents a direction dimension
 * @param set TRUE to make the direction passable. FALSE to make it impassable
 */
void TileSprite::setPassability(Direction dir, bool set)
{
  this->passability = set ? (this->passability | dir)
                          : (this->passability & ~dir);
}

/**
 * Sets the stack render depth relative to other tile sprites.
 * @param depth an unsigned 8-bit integer between 0-255 representing lowest (0) to highest render
 *              priority
 */
void TileSprite::setRenderDepth(uint8_t depth)
{
  this->render_depth = depth;
}
