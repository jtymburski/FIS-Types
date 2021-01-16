/**
 * @class ConversationEntryIndex
 *
 * Single immutable conversation entry index that allows for easy access of the groupings
 * into accessible values. The focus here is single directional, takes the string form
 * and parses to generate the usable index data.
 */
#include "Event/Conversation/ConversationEntryIndex.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const char ConversationEntryIndex::kINDEX_GROUP_DELIMITER = '.';
const std::regex ConversationEntryIndex::kINDEX_STRING_FORMAT("^1(\\.[1-9]\\d*)*$");

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Construction function. Builds a root node index ({@link #isRoot()} returns true).
 */
ConversationEntryIndex::ConversationEntryIndex()
{
  groups.push_back(1);
}

/**
 * Constructor function. Takes in a correctly formatted index string and converts it
 * to the underlying storage mechanism for easy re-access. It will throw
 * {@link std::invalid_argument} if the format does not match.
 */
ConversationEntryIndex::ConversationEntryIndex(std::string index_str)
{
  if(!isValidString(index_str))
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

/**
 * Constructor function. Takes in an ordered vector of group values (node addresses) and builds
 * the index object around it. It will throw {@link std::invalid_argument} if the index values
 * are misconfigured.
 */
ConversationEntryIndex::ConversationEntryIndex(std::vector<uint8_t> index_groups)
{
  if(index_groups.size() == 0)
    throw std::invalid_argument("Index groups passed in have no values in the vector. "
                                "There must be at least one");
  groups = index_groups;
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Copies the existing index (since its immutable) but re-creates it with a new tail group added
 * and set to 1. This pushes the index address one node deeper.
 * @return newly created index
 */
ConversationEntryIndex ConversationEntryIndex::copyAndAddTail() const
{
  std::vector<uint8_t> copied_groups(groups);
  copied_groups.push_back(1);

  return ConversationEntryIndex(copied_groups);
}

/**
 * Copies the existing index (since its immutable) but re-creates it with the tail group value
 * incremented by 1 (next leaf).
 * @return newly created index
 */
ConversationEntryIndex ConversationEntryIndex::copyAndIncrementTail() const
{
  std::vector<uint8_t> copied_groups(groups);
  uint16_t last_index = copied_groups.size() - 1;
  copied_groups[last_index] = copied_groups[last_index] + 1;

  return ConversationEntryIndex(copied_groups);
}

/*
 * Total number of group values in the index address.
 * @return group count
 */
uint16_t ConversationEntryIndex::groupCount() const
{
  return groups.size();
}

/**
 * Integer value of a single group in the index address, as a 0..n value from a 1..n internally
 * stored value.
 * @param group_index relative index in the address. 0 is first value, 1 is second, ...
 * @return group value. Will throw {@link std::out_of_range} if index is larger than count
 */
uint8_t ConversationEntryIndex::groupValue(uint16_t group_index) const
{
  if(group_index >= groups.size())
    throw std::out_of_range("Group index=" + std::to_string(group_index) +
                            " is out of range in ConversationEntryIndex::groupValue()");
  return groups.at(group_index) - 1;
}

/**
 * Returns if the index address references the root conversation entry.
 * @return TRUE if this references the root
 */
bool ConversationEntryIndex::isRoot() const
{
  return groupCount() == 1;
}

/**
 * Converts the index to a serialized string.
 * @return string address, matching format {#kINDEX_STRING_FORMAT}
 */
std::string ConversationEntryIndex::toString() const
{
  std::string index_str;

  for(auto &group : groups)
    index_str += std::to_string(group) + kINDEX_GROUP_DELIMITER;

  // There is one extra delimiter added at the end. Pop it off if at least one group was added
  if(index_str.length() > 0)
    index_str.pop_back();

  return index_str;
}
/*=============================================================================
 * PUBLIC STATIC FUNCTIONS
 *============================================================================*/

/**
 * Returns if the string is in the valid format to convert into the index object.
 * @param index_str index string representing an entry in the tree
 * @return TRUE if the string is correctly formed and can be converted into the entry object
 */
bool ConversationEntryIndex::isValidString(std::string index_str)
{
  return std::regex_match(index_str, kINDEX_STRING_FORMAT);
}
