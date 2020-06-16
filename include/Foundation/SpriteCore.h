/**
 * @class SpriteCore
 *
 * Foundation data object for a game sprite. A sprite is a single frame or a sequence of
 * frames that can animate and act as a single image within various contexts
 */
#ifndef SPRITECORE_H
#define SPRITECORE_H

#include <cstdint>
#include <list>

#include "Foundation/FrameCore.h"
#include "Foundation/Sequence.h"

class SpriteCore
{
private:
  /* Sequence for how to animate through the frames */
  Sequence animation_sequence = Sequence::DEFAULT;

  /* Time to display each frame before going to the next */
  uint16_t animation_time_ms = 250;

  /* Brightness modifier value [0..1..2 = 0..100..200%] */
  float brightness = 1.0f;

  /* Colour modifier values (RGB) [0..255 = 0..100%] */
  uint8_t color_blue = 255;
  uint8_t color_green = 255;
  uint8_t color_red = 255;

  /* Set of ordered frames that defines the animation timeline */
  std::list<FrameCore> frames;

  /* Unique identifier */
  uint16_t id = 0;

  /* Stored opacity value for rendering [0..255 = 0..100%] */
  uint8_t opacity = 255;

  /* Rotation angle rotated clockwise around the center */
  double rotation_degrees = 0.0;

  /* Sound action identifier paired with sprite */
  int32_t sound_id = kUNSET_SOUND_ID;

  /*------------------- Constants -----------------------*/

  /* Unset sound action ID */
  const static int32_t kUNSET_SOUND_ID = -1;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/
public:
  /* Returns the sequence for how to animate through the frames */
  Sequence getAnimationSequence() const;

  /* Returns the total animation time between frame changes */
  uint16_t getAnimationTimeMs() const;

  /* Returns the brightness modifier value */
  float getBrightness() const;

  /* Returns the color modifier values (RGB) */
  uint8_t getColorBlue() const;
  uint8_t getColorGreen() const;
  uint8_t getColorRed() const;

  /* Returns the set of ordered frames */
  std::list<FrameCore>& getFrames();

  /* Returns the unique identifier */
  uint16_t getId() const;

  /* Returns the stored opacity value for rendering */
  uint8_t getOpacity() const;

  /* Returns the rotation degrees rotated clockwise around the center */
  double getRotationDegrees() const;

  /* Returns the sound action identifier paired with sprite */
  int32_t getSoundId() const;

  /* Sets the sequence for how to animate through the frames */
  void setAnimationSequence(Sequence animation_sequence);

  /* Sets the total animation time between frame changes */
  void setAnimationTimeMs(uint16_t animation_time_ms);

  /* Sets the brightness modifier value */
  void setBrightness(float brightness);

  /* Sets the color modifier values (RGB) */
  void setColorBlue(uint8_t color_blue);
  void setColorGreen(uint8_t color_green);
  void setColorRed(uint8_t color_red);

  /* Sets the unique identifier */
  void setId(uint16_t id);

  /* Sets the stored opacity value for rendering */
  void setOpacity(uint8_t opacity);

  /* Sets the rotation degrees rotated clockwise around the center */
  void setRotationDegrees(double rotation_degrees);

  /* Sets the sound action identifier paired with sprite */
  void setSoundId(int32_t sound_id);
};

#endif // SPRITECORE_H
