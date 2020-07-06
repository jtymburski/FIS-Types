/**
 * @class StringUtility
 *
 * Extended functionality on the standard C++ string to add frequently used processing
 * requirements.
 */
#include "Parser/StringUtility.h"
using namespace core;

/*=============================================================================
 * PUBLIC STATIC FUNCTIONS
 *============================================================================*/

/**
 * Split function that takes a single line and a character delimiter and cuts it into
 * a list of tokens based on the delimiter (which is removed from the result). As an example,
 * "Hello,sunshine,,day" would return ["Hello", "sunshine", "", "day"].
 *
 * It will not return a final empty string if the line ends with a delimiter.
 * It will not return anything in the vector if the string is empty.
 *
 * @param line string which may contain 0-n delimiters and any other content
 * @param delimiter single character to divide the line into tokens
 * @return list of all tokens after the line is parsed
 */
std::vector<std::string> StringUtility::split(const std::string& line, char delimiter)
{
  std::vector<std::string> split_set;
  std::string split_part;
  std::stringstream line_stream(line);

  while(std::getline(line_stream, split_part, delimiter))
    split_set.push_back(split_part);

  return split_set;
}
