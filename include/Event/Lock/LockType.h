/**
 * @class LockType
 *
 * Enumerator defining the lock type classification which encapsulates the varying options for
 * locks that can be embedded on objects.
 */
#ifndef CORE_LOCKTYPE_H
#define CORE_LOCKTYPE_H

#include <cstdint>

namespace core
{
  enum class LockType : std::uint8_t
  {
    NONE,
    ITEM,
    TRIGGER
  };
};

#endif // CORE_LOCKTYPE_H
