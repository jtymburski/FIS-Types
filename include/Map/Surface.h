/**
 * @class Surface
 *
 * Enumerator defining a map surface that can be travelled on or rendered.
 */
#ifndef CORE_SURFACE_H
#define CORE_SURFACE_H

#include <cstdint>

namespace core
{
  enum class Surface : std::uint8_t
  {
    GROUND
  };
};

#endif // CORE_SURFACE_H
