/**
 * @class Sequence
 *
 * Enumerator defining an animation sequence and how it should transition
 * through a given flow.
 */
#ifndef CORE_SEQUENCE_H
#define CORE_SEQUENCE_H

#include <cstdint>

namespace core
{
  enum class Sequence : std::uint8_t
  {
    DEFAULT,
    FORWARD,
    REVERSE
  };
};

#endif // CORE_SEQUENCE_H
