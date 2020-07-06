/**
 * @class SpriteMatrix
 *
 * Foundation data object for a sprite matrix. The matrix represents a two dimensional
 * grid of sprites that together are grouped to represent a single object. It is
 * expected to animate and be owned by one in game entity.
 */
#ifndef CORE_SPRITEMATRIX_H
#define CORE_SPRITEMATRIX_H

#include <vector>

#include "Foundation/TileSprite.h"

namespace core
{
  class SpriteMatrix
  {
  private:
    /* Two-dimensional matrix of sprites */
    std::vector<std::vector<TileSprite>> matrix;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the stored sprite matrix */
    std::vector<std::vector<TileSprite>>& getMatrix();

    /* Returns the sprite at a given [X][Y] coordinate */
    TileSprite& getSprite(uint16_t x, uint16_t y);

    /* Returns the height (Y direction) of the matrix */
    uint16_t height() const;

    /* Returns the width (X direction) of the matrix */
    uint16_t width() const;
  };
};

#endif // CORE_SPRITEMATRIX_H
