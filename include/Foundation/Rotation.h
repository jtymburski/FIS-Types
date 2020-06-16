/**
 * @class Rotation
 *
 * Enumerator defining how an asset can be rotated around its center point
 * within the bounding box.
 */
#ifndef ROTATION_H
#define ROTATION_H

#include <cstdint>

enum class Rotation : std::uint8_t
{
  NONE,
  ANGLE_90,
  ANGLE_180,
  ANGLE_270
};

#endif // ROTATION_H
