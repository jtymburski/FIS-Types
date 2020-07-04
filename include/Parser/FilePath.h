/**
 * @class FilePath
 *
 * File path parsing and processing functionality shared across implementations.
 */
#ifndef FILEPATH_H
#define FILEPATH_H

#include <string>
#include <vector>

#include "Parser/StringUtility.h"

class FilePath
{
/*=============================================================================
 * CONSTANTS
 *============================================================================*/
private:
  /* Start delimiter wrapping a valid range. For example, "[A-D]" */
  const static char kRANGE_SEQUENCE_END = ']';

  /* Middle separator contained in a valid range. For example, "[A-D]" */
  const static char kRANGE_SEQUENCE_MID = '-';

  /* End delimiter wrapping a valid range. For example, "[A-D]" */
  const static char kRANGE_SEQUENCE_START = '[';

/*=============================================================================
 * PRIVATE STATIC FUNCTIONS
 *============================================================================*/
private:
  /* Rolls out a range, for example "A-C", into a linear list along the range: [A, B, C] */
  static std::vector<std::string> rollOutRange(std::string range);

  /* Rolls out a range in part of a line that may end in other content, like "A-C]foo" */
  static std::vector<std::string> rollOutRangeWithSuffix(std::string part);

/*=============================================================================
 * PUBLIC STATIC FUNCTIONS
 *============================================================================*/
public:
  /* Splits the string into a 2D matrix based on the defined range delimiters */
  static std::vector<std::vector<std::string>> separateOnRanges(std::string path);
};

#endif // FILEPATH_H
