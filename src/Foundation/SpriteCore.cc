/**
 * @class SpriteCore
 *
 * Foundation data object for a game sprite. A sprite is a single frame or a sequence of
 * frames that can animate and act as a single image within various contexts
 */
#include "Foundation/SpriteCore.h"

/* Returns the sequence for how to animate through the frames */
Sequence SpriteCore::getAnimationSequence() const
{
  return animation_sequence;
}

/* Returns the total animation time between frame changes */
uint16_t SpriteCore::getAnimationTimeMs() const
{
  return animation_time_ms;
}

/* Returns the brightness modifier value */
float SpriteCore::getBrightness() const
{
  return brightness;
}

/* Returns the color modifier values (RGB) */
uint8_t SpriteCore::getColorBlue() const
{
  return color_blue;
}

uint8_t SpriteCore::getColorGreen() const
{
  return color_green;
}

uint8_t SpriteCore::getColorRed() const
{
  return color_red;
}

/* Returns the set of ordered frames */
std::list<FrameCore>& SpriteCore::getFrames()
{
  return frames;
}

/* Returns the unique identifier */
uint16_t SpriteCore::getId() const
{
  return id;
}

/* Returns the stored opacity value for rendering */
uint8_t SpriteCore::getOpacity() const
{
  return opacity;
}

/* Returns the rotation degrees rotated clockwise around the center */
double SpriteCore::getRotationDegrees() const
{
  return rotation_degrees;
}

/* Returns the sound action identifier paired with sprite */
int32_t SpriteCore::getSoundId() const
{
  return sound_id;
}

/* Sets the sequence for how to animate through the frames */
void SpriteCore::setAnimationSequence(Sequence animation_sequence)
{
  this->animation_sequence = animation_sequence;
}

/* Sets the total animation time between frame changes */
void SpriteCore::setAnimationTimeMs(uint16_t animation_time_ms)
{
  this->animation_time_ms = animation_time_ms;
}

/* Sets the brightness modifier value */
void SpriteCore::setBrightness(float brightness)
{
  this->brightness = brightness;
}

/* Sets the color modifier values (RGB) */
void SpriteCore::setColorBlue(uint8_t color_blue)
{
  this->color_blue = color_blue;
}

void SpriteCore::setColorGreen(uint8_t color_green)
{
  this->color_green = color_green;
}

void SpriteCore::setColorRed(uint8_t color_red)
{
  this->color_red = color_red;
}

/* Sets the unique identifier */
void SpriteCore::setId(uint16_t id)
{
  this->id = id;
}

/* Sets the stored opacity value for rendering */
void SpriteCore::setOpacity(uint8_t opacity)
{
  this->opacity = opacity;
}

/* Sets the rotation degrees rotated clockwise around the center */
void SpriteCore::setRotationDegrees(double rotation_degrees)
{
  this->rotation_degrees = rotation_degrees;
}

/* Sets the sound action identifier paired with sprite */
void SpriteCore::setSoundId(int32_t sound_id)
{
  this->sound_id = sound_id;
}
