/**
 * @class ConversationEntryIndex
 *
 * Single immutable conversation entry index that allows for easy access of the groupings
 * into accessible values. The focus here is single directional, takes the string form
 * and parses to generate the usable index data.
 */
#include "Event/ConversationEntryIndex.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const char ConversationEntryIndex::kINDEX_GROUP_DELIMITER = '.';
const std::regex ConversationEntryIndex::kINDEX_STRING_FORMAT("^([1-9]\\d*\\.)*[1-9]\\d*$");

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Constructor function. Takes in a correctly formatted index string and converts it
 * to the underlying storage mechanism for easy re-access. It will throw
 * {@link std::invalid_argument} if the format does not match.
 */
ConversationEntryIndex::ConversationEntryIndex(std::string index_str)
{
  if(!std::regex_match(index_str, kINDEX_STRING_FORMAT))
    throw std::invalid_argument("String index=" + index_str +
                                " is not correctly formed to convert into a conversation index");

  // Replace the delimiter with a whitespace so its compatible to be streamed
  std::replace(index_str.begin(), index_str.end(), kINDEX_GROUP_DELIMITER, ' ');

  // Stream through each value and add onto the stack
  std::stringstream index_stream(index_str);
  int group_value;
  while (index_stream >> group_value)
    groups.push_back(group_value);
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/*
 * Total number of group values in the index address.
 * @return group count
 */
uint16_t ConversationEntryIndex::groupCount()
{
  return groups.size();
}

/**
 * Integer value of a single group in the index address.
 * @param group_index relative index in the address. 0 is first value, 1 is second, ...
 * @return group value. Will throw {@link std::out_of_range} if index is larger than count
 */
uint8_t ConversationEntryIndex::groupValue(uint16_t group_index)
{
  if(group_index >= groups.size())
    throw std::out_of_range("Group index=" + std::to_string(group_index) +
                            " is out of range in ConversationEntryIndex::groupValue()");
  return groups.at(group_index);
}

/**
 * Converts the index to a serialized string.
 * @return string address, matching format {#kINDEX_STRING_FORMAT}
 */
std::string ConversationEntryIndex::toString()
{
  std::string index_str;

  for(auto &group : groups)
    index_str += std::to_string(group) + kINDEX_GROUP_DELIMITER;

  // There is one extra delimiter added at the end. Pop it off if at least one group was added
  if(index_str.length() > 0)
    index_str.pop_back();

  return index_str;
}
