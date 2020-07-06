/**
 * @class SpriteMatrix
 *
 * Foundation data object for a sprite matrix. The matrix represents a two dimensional
 * grid of sprites that together are grouped to represent a single object. It is
 * expected to animate and be owned by one in game entity.
 */
#include "Foundation/SpriteMatrix.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Full sprite matrix reference of the two-dimensional vector stored within the class. This is
 * a reference; if any alterations are made, it will affect the sprite matrix class result.
 * @return full contained tile sprite matrix
 */
std::vector<std::vector<TileSprite>>& SpriteMatrix::getMatrix()
{
  return matrix;
}

/**
 * Fetches a single sprite within the matrix, as a reference. If the (X, Y) coordinate is out
 * of range, it throws an std::out_of_range exception is thrown.
 * @param x width coordinate, represented by the first vector. Matrix[X][Y] is the form.
 * @param y height coordinate, represented by the internal vector. Matrix[X][Y] is the form.
 * @return internal element sprite reference
 */
TileSprite& SpriteMatrix::getSprite(uint16_t x, uint16_t y)
{
  return matrix.at(x).at(y);
}

/**
 * Height of the sprite matrix. This is the second, Y, coordinate of the matrix when accessed
 * using matrix[X][Y].
 * @return height value. does not represent the number that can be rendered, just matrix size.
 */
uint16_t SpriteMatrix::height() const
{
  if(matrix.size() > 0)
    return matrix.back().size();
  return 0;
}

/**
 * Width of the sprite matrix. This is the first, X, coordinate of the matrix when accessed
 * using matrix[X][Y].
 * @return width value. does not represent the number that can be rendered, just matrix size.
 */
uint16_t SpriteMatrix::width() const
{
  return matrix.size();
}
