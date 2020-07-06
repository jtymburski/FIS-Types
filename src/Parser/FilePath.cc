/**
 * @class FilePath
 *
 * File path parsing and processing functionality shared across implementations.
 */
#include "Parser/FilePath.h"
using namespace core;

/*=============================================================================
 * PRIVATE STATIC FUNCTIONS
 *============================================================================*/

/**
 * Rolls out a range of char values in a string to a sequence of linear char values, based on
 * the ASCII table. If the string is not a valid range, the return vector will be empty.
 *
 * For example, "B-D" will result in ["B","C","D"].
 *
 * @param range string representation of a char range. It can be incorrectly formed
 * @return linear list of chars, converted to a string, of the range
 */
std::vector<std::string> FilePath::rollOutRange(std::string range)
{
  std::vector<std::string> range_sequence;

  /* Split range on {@link #kRANGE_SEQUENCE_MID}. If it is a proper range, it should be in format
   * "<start string><delimiter><end string>" */
  std::vector<std::string> range_split = StringUtility::split(range, kRANGE_SEQUENCE_MID);
  if(range_split.size() == 2)
  {
    /* Check if "<start string>" or "<end string>" can be converted to a char. Only chars can
     * be rolled out to a linear sequence */
    std::string start_string = range_split.front();
    std::string end_string = range_split.back();
    if(start_string.size() == 1 && end_string.size() == 1)
    {
      char start_value = start_string.front();
      char end_value = end_string.front();
      range_sequence.push_back(std::string(1, start_value));

      /* For multi-char ranges, go through each value and add it to the sequence */
      char current_value = start_value;
      while(current_value != end_value)
      {
        current_value = current_value + (start_value < end_value ? 1 : -1);
        range_sequence.push_back(std::string(1, current_value));
      }
    }
  }

  return range_sequence;
}

/**
 * Rolls out a range of char values embedded in a string that may contain a suffix. This extends
 * {@link #rollOutRange(std::string)} with flexibility to handle a suffix at the end of the range
 * delimited by {@link #kRANGE_SEQUENCE_END}. The suffix is added on to the end of each value in
 * the resulting sequence. If the string does not start with a valid range, the return vector
 * will be empty.
 *
 * For example, "B-D]foo" will result in ["Bfoo","Cfoo","Dfoo"].
 *
 * @param part string containing a part which may contain a valid range followed by any content
 * @return linear sequence of the range with the suffix after each element
 */
std::vector<std::string> FilePath::rollOutRangeWithSuffix(std::string part)
{
  std::vector<std::string> part_split = StringUtility::split(part, kRANGE_SEQUENCE_END);
  if(!part_split.empty())
  {
    std::string part_with_range = part_split.front();
    std::vector<std::string> range_sequence = rollOutRange(part_with_range);

    if(!range_sequence.empty())
    {
      std::string part_suffix = part.substr(part_with_range.size() + 1); // +1 for delimiter
      for(uint32_t i = 0; i < range_sequence.size(); i++)
        range_sequence.at(i) += part_suffix;
      return range_sequence;
    }
  }

  return std::vector<std::string>();
}

/*=============================================================================
 * PUBLIC STATIC FUNCTIONS
 *============================================================================*/

/**
 * Takes a string that can contain file ranges and splits them into a two dimensional matrix
 * representing the ranges rolled out. This uses a specific format, defined in the class, to
 * delimite the ranges. Range start is delimited by {@link #kRANGE_SEQUENCE_START}, separated by
 * {@link #kRANGE_SEQUENCE_MID}, and ends on {@link #kRANGE_SEQUENCE_END}, for instance "[A-C]".
 * This will only handle up to two ranges. If only one range is provided, it will be a 2D matrix
 * with only one string in each internal vector. If no ranges are provided, it will be a 2D
 * matrix with unaltered method argument in the top left.
 *
 * Example: "Test01_[A-C][A-B]_U00.png" will become
 * [
 *   ["Test01_AA_U00.png", "Test01_AB_U00.png"],
 *   ["Test01_BA_U00.png", "Test01_BB_U00.png"],
 *   ["Test01_CA_U00.png", "Test01_CB_U00.png"]
 * ]
 *
 * @param path a compressed path that may or may not contain range segments
 * @return matrix of paths, as described in the description, depending on how it was parsed
 */
std::vector<std::vector<std::string>> FilePath::separateOnRanges(std::string path)
{
  /* Split string on {@link #kRANGE_SEQUENCE_START} */
  std::vector<std::string> start_split = StringUtility::split(path, kRANGE_SEQUENCE_START);
  std::string prefix = start_split.empty() ? "" : start_split.front();
  uint32_t start_index = 1;

  /* Elements of the assembled array */
  std::vector<std::string> rows;
  std::string middle;
  std::vector<std::string> columns;
  std::string suffix;

  /* Find the rows */
  while(start_index < start_split.size() && rows.empty())
  {
    std::string part_to_analyze = start_split.at(start_index++);
    rows = rollOutRangeWithSuffix(part_to_analyze);

    /* If no row was discovered, add the part of line to the prefix */
    if(rows.empty())
      prefix += kRANGE_SEQUENCE_START + part_to_analyze;
  }

  /* Find the columns */
  while(start_index < start_split.size() && columns.empty())
  {
    std::string part_to_analyze = start_split.at(start_index++);
    columns = rollOutRangeWithSuffix(part_to_analyze);

    /* If no column was discovered, add the part of line to the middle */
    if(columns.empty())
      middle += kRANGE_SEQUENCE_START + part_to_analyze;
  }

  /* Add the remainder to the suffix */
  while(start_index < start_split.size())
    suffix += kRANGE_SEQUENCE_START + start_split.at(start_index++);

  /* Assemble 2D vector */
  std::vector<std::vector<std::string>> frame_paths;
  for(std::string unique_row : rows)
  {
    std::vector<std::string> complete_row;
    std::string prefix_row = prefix + unique_row + middle;

    for(std::string unique_column : columns)
      complete_row.push_back(prefix_row + unique_column + suffix);

    frame_paths.push_back(complete_row);
  }

  return frame_paths;
}
