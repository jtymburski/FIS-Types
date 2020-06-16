/**
 * @class Sequence
 *
 * Enumerator defining an animation sequence and how it should transition
 * through a given flow.
 */
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstdint>

enum class Sequence : std::uint8_t
{
  DEFAULT,
  FORWARD,
  REVERSE
};

#endif // SEQUENCE_H
