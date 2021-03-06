/**
 * @class Flip
 *
 * Enumerator defining how an asset can be flipped on the X and/or Y axis.
 */
#ifndef CORE_FLIP_H
#define CORE_FLIP_H

#include <cstdint>

namespace core
{
  enum class Flip : std::uint8_t
  {
    NONE       = 0,
    HORIZONTAL = 1 << 0,
    VERTICAL   = 1 << 1
  };

  constexpr enum Flip operator& (const enum Flip firstValue, const enum Flip secondValue)
  {
    return static_cast<Flip>(uint8_t(firstValue) & uint8_t(secondValue));
  }

  constexpr enum Flip operator| (const enum Flip firstValue, const enum Flip secondValue)
  {
    return static_cast<Flip>(uint8_t(firstValue) | uint8_t(secondValue));
  }

  constexpr enum Flip operator~ (const enum Flip value)
  {
    return static_cast<Flip>(~uint8_t(value));
  }
};

#endif // CORE_FLIP_H
