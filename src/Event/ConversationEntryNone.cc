/**
 * @class ConversationEntryNone
 *
 * A no-op conversation entry that should not be displayed. If at the end of a sequence,
 * the conversation should end.
 */
#include "Event/ConversationEntryNone.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns {@link ConversationEntryType#NONE} to define the type classification, overrides parent.
 * @return entry type classification enum
 */
ConversationEntryType ConversationEntryNone::getType() const
{
  return ConversationEntryType::NONE;
}
