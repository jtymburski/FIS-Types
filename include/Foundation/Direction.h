/**
 * @class Direction
 *
 * Enumerator defining a direction on a standard compass axis: North, East, South, West.
 * It is designed to be bitwise combined under one reference, if necessary.
 */
#ifndef CORE_DIRECTION_H
#define CORE_DIRECTION_H

#include <cstdint>

namespace core
{
  enum class Direction : std::uint8_t
  {
    NONE  = 0,
    NORTH = 1 << 0,
    EAST  = 1 << 1,
    SOUTH = 1 << 2,
    WEST  = 1 << 3
  };

  constexpr enum Direction operator& (const enum Direction firstValue,
                                      const enum Direction secondValue)
  {
    return static_cast<Direction>(uint8_t(firstValue) & uint8_t(secondValue));
  }

  constexpr enum Direction operator| (const enum Direction firstValue,
                                      const enum Direction secondValue)
  {
    return static_cast<Direction>(uint8_t(firstValue) | uint8_t(secondValue));
  }

  constexpr enum Direction operator~ (const enum Direction value)
  {
    return static_cast<Direction>(~uint8_t(value));
  }
};

#endif // CORE_DIRECTION_H
