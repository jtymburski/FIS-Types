/**
 * @class Tracking
 *
 * Enumerator defining how a moving object reacts to the breach by another object
 * into its set range.
 */
#ifndef CORE_TRACKING_H
#define CORE_TRACKING_H

#include <cstdint>

namespace core
{
  enum class Tracking : std::uint8_t
  {
    NONE,
    AVOID,
    CHASE
  };
};

#endif // CORE_TRACKING_H
