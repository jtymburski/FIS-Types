/**
 * @class ConversationEntryIndex
 *
 * Single immutable conversation entry index that allows for easy access of the groupings
 * into accessible values. The focus here is single directional, takes the string form
 * and parses to generate the usable index data.
 */
#ifndef CORE_CONVERSATIONENTRYINDEX_H
#define CORE_CONVERSATIONENTRYINDEX_H

#include <cstdint>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace core
{
  class ConversationEntryIndex
  {
  private:
    /* Constructor function, from pre-built group value vector */
    ConversationEntryIndex(std::vector<uint8_t> index_groups);

  public:
    /* Constructor function, for the root */
    ConversationEntryIndex();

    /* Constructor function, from string index */
    ConversationEntryIndex(std::string index_str);

  private:
    /* Address group values for a single index */
    std::vector<uint8_t> groups;

    /*------------------- Constants -----------------------*/

    /* Index string group delimiter */
    const static char kINDEX_GROUP_DELIMITER;

    /* Index string strict format, in regex. Requires index in form "1.4.1" */
    const static std::regex kINDEX_STRING_FORMAT;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Adds a new group value (1) to the tail in a newly created index */
    ConversationEntryIndex copyAndAddTail() const;

    /* Increments the last group value in a newly created index */
    ConversationEntryIndex copyAndIncrementTail() const;

    /* Number of groups in the index */
    uint16_t groupCount() const;

    /* Value of a single group in the index */
    uint8_t groupValue(uint16_t group_index) const;

    /* Does this index reference the root conversation entry */
    bool isRoot() const;

    /* Converts the index to a serialized string */
    std::string toString() const;

  /*=============================================================================
   * PUBLIC STATIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns if the string is in the valid format to convert into the index object */
    static bool isValidString(std::string index_str);
  };
};

#endif // CORE_CONVERSATIONENTRYINDEX_H
