/**
 * @class TileSpriteCore
 *
 * Extends a standard Sprite and adds passability, render depth and any other
 * map specific properties which describes a sprite within a tile stack
 */
#ifndef TILESPRITECORE_H
#define TILESPRITECORE_H

#include "Foundation/Direction.h"
#include "Foundation/SpriteCore.h"

class TileSpriteCore : public SpriteCore
{
private:
  /* Permitted passability, from the perspective within the tile */
  Direction passability = Direction::NONE;

  /* Render depth - 'z' coordinate */
  uint8_t render_depth = 0;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/
public:
  /* Returns if a single direction is passable in that direction from tile center */
  bool getPassability(Direction dir) const;

  /* Returns the stack render depth */
  uint8_t getRenderDepth() const;

  /* Sets or clears the passability for a single direction */
  void setPassability(Direction dir, bool set);

  /* Sets the stack render depth */
  void setRenderDepth(uint8_t depth);
};

#endif // TILESPRITECORE_H
