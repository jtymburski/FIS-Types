/**
 * @class DataType
 *
 * Enumerator defining a data type classification for a generic storage element.
 */
#ifndef DATATYPE_H
#define DATATYPE_H

#include <cstdint>

enum class DataType : std::uint8_t
{
  NONE    = 0,
  BOOLEAN = 1,
  INTEGER = 2,
  FLOAT   = 3,
  STRING  = 4
};

#endif // DATATYPE_H
