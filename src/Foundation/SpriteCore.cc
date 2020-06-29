/**
 * @class SpriteCore
 *
 * Foundation data object for a game sprite. A sprite is a single frame or a sequence of
 * frames that can animate and act as a single image within various contexts
 */
#include "Foundation/SpriteCore.h"

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * The animation sequence for how frames are stepped once a single frame of animation
 * is finished.
 * @return directional sequencing for frame animation management
 */
Sequence SpriteCore::getAnimationSequence() const
{
  return animation_sequence;
}

/**
 * The time that each frame is displayed before triggering an animation change. The properties
 * of what happens when the time elapses for a single frame is defined in #getAnimationSequence().
 * @return time in milliseconds
 */
uint16_t SpriteCore::getAnimationTimeMs() const
{
  return animation_time_ms;
}

/**
 * Brightness setting for modifiers that affect the default values before all frames wrapped
 * in this sprite are rendered.
 * @return 0.0f is 100% dark (black), 1.0f is normal, 2.0f is double the normal brightness
 */
float SpriteCore::getBrightness() const
{
  return brightness;
}

/**
 * Color RGB modifier for the blue dimension of the frame rendering profile.
 * @return 0 (0%) to 255 (100%) of the current blue values
 */
uint8_t SpriteCore::getColorBlue() const
{
  return color_blue;
}

/**
 * Color RGB modifier for the green dimension of the frame rendering profile.
 * @return 0 (0%) to 255 (100%) of the current green values
 */
uint8_t SpriteCore::getColorGreen() const
{
  return color_green;
}

/**
 * Color RGB modifier for the red dimension of the frame rendering profile.
 * @return 0 (0%) to 255 (100%) of the current red values
 */
uint8_t SpriteCore::getColorRed() const
{
  return color_red;
}

/**
 * A reference list of all stored frames inside the sprite.
 * @return ordered by how the frames were added during creation
 */
std::list<FrameCore>& SpriteCore::getFrames()
{
  return frames;
}

/**
 * A unique identifier for the sprite referenced by animations or control sequencing. Uniquely
 * identifies the sprite in a single context.
 * @return unique, set at creation
 */
uint16_t SpriteCore::getId() const
{
  return id;
}

/**
 * Fetches the opacity setting of the sprite for rendering.
 * @return opacity value between 0 (0%) and 255 (100%)
 */
uint8_t SpriteCore::getOpacity() const
{
  return opacity;
}

/**
 * Fetches the rendering rotation degrees rotated clockwise around the center.
 * @return a value representing degrees of rotation (360.0 being a full rotation)
 */
double SpriteCore::getRotationDegrees() const
{
  return rotation_degrees;
}

/**
 * Sound system identifier for the trigger on action animation of the sprite.
 * @return sound ID. Can be unset (<0)
 */
int32_t SpriteCore::getSoundId() const
{
  return sound_id;
}

/**
 * Sets the animation sequence for how frames are stepped once a single frame of animation
 * is finished.
 * @animation_sequence directional sequencing for frame animation management
 */
void SpriteCore::setAnimationSequence(Sequence animation_sequence)
{
  this->animation_sequence = animation_sequence;
}

/**
 * Sets the time that each frame is displayed before triggering an animation change. The properties
 * of what happens when the time elapses for a single frame is defined in #getAnimationSequence().
 * @param animation_time_ms time in milliseconds, max at 65,536 by data type
 */
void SpriteCore::setAnimationTimeMs(uint16_t animation_time_ms)
{
  this->animation_time_ms = animation_time_ms;
}

/**
 * Sets the brightness setting for modifiers that affect the default values before all
 * frames wrapped in this sprite are rendered.
 * @param brightness 0.0f is 100% dark (black), 1.0f is normal, 2.0f is double brightness
 */
void SpriteCore::setBrightness(float brightness)
{
  this->brightness = brightness;
}

/**
 * Sets the color RGB modifier for the blue dimension of the frame rendering profile.
 * @param color_blue 0 (0%) to 255 (100%) of the current blue values
 */
void SpriteCore::setColorBlue(uint8_t color_blue)
{
  this->color_blue = color_blue;
}

/**
 * Sets the color RGB modifier for the green dimension of the frame rendering profile.
 * @param color_blue 0 (0%) to 255 (100%) of the current green values
 */
void SpriteCore::setColorGreen(uint8_t color_green)
{
  this->color_green = color_green;
}

/**
 * Sets the color RGB modifier for the red dimension of the frame rendering profile.
 * @param color_blue 0 (0%) to 255 (100%) of the current red values
 */
void SpriteCore::setColorRed(uint8_t color_red)
{
  this->color_red = color_red;
}

/**
 * Sets the unique identifier for the sprite referenced by animations or control sequencing.
 * @param id unique, identifies sprite across a single context, like a map
 */
void SpriteCore::setId(uint16_t id)
{
  this->id = id;
}

/**
 * Sets the opacity setting of the sprite for rendering.
 * @param opacity value between 0 (0%) and 255 (100%). 100% is fully opaque, 0% is invisible
 */
void SpriteCore::setOpacity(uint8_t opacity)
{
  this->opacity = opacity;
}

/**
 * Sets the rendering rotation degrees rotated clockwise around the center.
 * @param rotation_degrees value representing degrees of rotation (360.0 being a full rotation)
 */
void SpriteCore::setRotationDegrees(double rotation_degrees)
{
  this->rotation_degrees = rotation_degrees;
}

/**
 * Sets the sound system identifier for the trigger on action animation of the sprite.
 * @param sound_id the Sound#getId() for animation changes. Set less than 0 to unset
 */
void SpriteCore::setSoundId(int32_t sound_id)
{
  this->sound_id = sound_id;
}
