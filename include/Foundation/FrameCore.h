/**
 * @class FrameCore
 *
 * Foundation data object for a game frame. A frame is a single image asset that can be
 * rendered and displayed
 */
#ifndef FRAMECORE_H
#define FRAMECORE_H

#include <cstdint>
#include <string>

#include "Foundation/Flip.h"
#include "Foundation/Rotation.h"

class FrameCore
{
private:
  /* Flip configuration - horizontal or vertical */
  Flip flip = Flip::NONE;

  /* The stored opacity value for rendering [0..255 = 0..100%] */
  uint8_t opacity = 255;

  /* The frame path sprite data */
  std::string path;

  /* Rotation of frame - 0, 90, 180, 270 */
  Rotation rotation = Rotation::NONE;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/
public:
  /* Returns the opacity setting of the frame */
  uint8_t getOpacity() const;

  /* Returns the frame asset path */
  std::string getPath() const;

  /* Returns the rotation for rendering the frame */
  Rotation getRotation() const;

  /* Returns the flip options of the frame */
  bool isFlipHorizontal() const;
  bool isFlipVertical() const;

  /* Sets the flip options */
  void setFlip(Flip flip, bool set);

  /* Sets the opacity setting [0-255] of the frame */
  void setOpacity(uint8_t opacity);

  /* Sets the frame asset path */
  void setPath(std::string path);

  /* Sets the rotation for rendering the frame */
  void setRotation(Rotation rotation);
};

#endif // FRAMECORE_H
