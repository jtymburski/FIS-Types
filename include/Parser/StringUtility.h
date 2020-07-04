/**
 * @class StringUtility
 *
 * Extended functionality on the standard C++ string to add frequently used processing
 * requirements.
 */
#ifndef STRINGUTILITY_H
#define STRINGUTILITY_H

#include <sstream>
#include <string>
#include <vector>

class StringUtility
{
/*=============================================================================
 * PUBLIC STATIC FUNCTIONS
 *============================================================================*/
public:
  /* Splits the string using the given delimiter */
  static std::vector<std::string> split(const std::string& line, char delimiter);
};

#endif // STRINGUTILITY_H
