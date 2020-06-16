/**
 * @class FrameCore
 *
 * Foundation data object for a game frame. A frame is a single image asset that can be
 * rendered and displayed
 */
#include "Foundation/FrameCore.h"

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Fetches the opacity setting of the frame
 * @return opacity value between 0 (0%) and 255 (100%)
 */
uint8_t FrameCore::getOpacity() const
{
  return opacity;
}

/**
 * Fetches the frame asset path
 * @return path to find a single frame
 */
std::string FrameCore::getPath() const
{
  return path;
}

/**
 * Fetches the rendering rotation of the frame
 * @return an enumerator representing a single rotation value (mod 90)
 */
Rotation FrameCore::getRotation() const
{
  return rotation;
}

/**
 * Should the frame be flipped horizontally (at the center along the Y-axis)
 * @return TRUE if it should be flipped. FALSE left as normal
 */
bool FrameCore::isFlipHorizontal() const
{
  return (flip & Flip::HORIZONTAL) == Flip::HORIZONTAL;
}

/**
 * Should the frame be flipped vertically (at the center along the X-axis)
 * @return TRUE if it should be flipped. FALSE left as normal
 */
bool FrameCore::isFlipVertical() const
{
  return (flip & Flip::VERTICAL) == Flip::VERTICAL;
}

/**
 * Sets a flip option for the frame
 * @param flip the enumerator that represents a flip dimension
 * @param set TRUE to enable the flip option. FALSE to disable the flip option
 */
void FrameCore::setFlip(Flip flip, bool set)
{
  this->flip = set ? (this->flip | flip)
                   : (this->flip & ~flip);
}

/**
 * Sets the opacity setting of the frame
 * @param opacity an unsigned 8-bit integer between 0-255 representing 0%-100% opacity
 */
void FrameCore::setOpacity(uint8_t opacity)
{
  this->opacity = opacity;
}

/**
 * Sets the frame asset path
 * @param path asset disk location to find the image
 */
void FrameCore::setPath(std::string path)
{
  this->path = path;
}

/**
 * Sets the rotation for rendering the frame
 * @param rotation the enumerator representing each mod 90 angle to rotate at the center
 */
void FrameCore::setRotation(Rotation rotation)
{
  this->rotation = rotation;
}
