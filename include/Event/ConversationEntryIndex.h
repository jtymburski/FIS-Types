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
  public:
    /* Constructor function */
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
    /* Number of groups in the index */
    uint16_t groupCount();

    /* Value of a single group in the index */
    uint8_t groupValue(uint16_t group_index);

    /* Converts the index to a serialized string */
    std::string toString();
  };
};

#endif // CORE_CONVERSATIONENTRYINDEX_H
