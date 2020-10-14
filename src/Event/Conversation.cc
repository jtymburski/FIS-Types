/**
 * @class Conversation
 *
 * A conversation is one fully contained set of entries that are displayed to communicate
 * to the player through a dynamic content presentation system.
 */
#include "Event/Conversation.h"
using namespace core;

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Destructor function, cleans up any dynamically assigned memory managed in the class.
 */
Conversation::~Conversation()
{
  delete root_entry;
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the top level, root conversation entry.
 * @return a single conversation entry as a starting point
 */
ConversationEntry& Conversation::getRootEntry()
{
  return *root_entry;
}

/**
 * Sets the top level, root conversation entry. This takes over the memory of the object.
 * @param entry a single conversation entry as a starting point
 */
void Conversation::setRootEntry(ConversationEntry& entry)
{
  if(this->root_entry == &entry)
    return;

  delete this->root_entry;
  this->root_entry = &entry;
}
