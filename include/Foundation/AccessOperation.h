/**
 * @class AccessOperation
 *
 * Enumerator defining the access / IO operation flow for an ordered list of items.
 */
#ifndef CORE_ACCESSOPERATION_H
#define CORE_ACCESSOPERATION_H

#include <cstdint>

namespace core
{
  enum class AccessOperation : std::uint8_t
  {
    NONE,
    SEQUENTIAL,
    RANDOM
  };
};

#endif // CORE_ACCESSOPERATION_H
