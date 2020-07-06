/**
 * @class Rotation
 *
 * Enumerator defining how an asset can be rotated around its center point
 * within the bounding box.
 */
#ifndef CORE_ROTATION_H
#define CORE_ROTATION_H

#include <cstdint>

namespace core
{
  enum class Rotation : std::uint8_t
  {
    NONE,
    ANGLE_90,
    ANGLE_180,
    ANGLE_270
  };
};

#endif // CORE_ROTATION_H
