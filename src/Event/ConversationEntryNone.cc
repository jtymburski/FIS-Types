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

/**
 * Returns if the conversation entry can be saved using {@link save(XmlWriter*)}.
 * @return TRUE if it will generate save data
 */
bool ConversationEntryNone::isSaveable() const
{
  return false;
}

/**
 * Loads conversation entry data from the XML entry. In this implementation, it is no-op.
 */
void ConversationEntryNone::load(XmlData, int)
{
}

/**
 * Saves all conversation entry data into the XML writer. In this implementation, it is no-op.
 */
void ConversationEntryNone::save(XmlWriter*) const
{
}
