/**
 * @class DataType
 *
 * Enumerator defining a data type classification for a generic storage element.
 */
#ifndef CORE_DATATYPE_H
#define CORE_DATATYPE_H

#include <cstdint>

namespace core
{
  enum class DataType : std::uint8_t
  {
    NONE    = 0,
    BOOLEAN = 1,
    INTEGER = 2,
    FLOAT   = 3,
    STRING  = 4
  };
};

#endif // CORE_DATATYPE_H
