/**
 * @class EventConversation
 *
 * A conversation event definition is simply the starting point to begin a conversation
 * action sequence with the interacting party (likely the player) and take over control
 * of the display.
 */
#include "Event/EventConversation.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the conversation data to display when triggered.
 * @return definition to display and trigger in game
 */
Conversation& EventConversation::getConversation()
{
  return conversation;
}

/**
 * Returns {@link EventType#CONVERSATION} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventConversation::getType() const
{
  return EventType::CONVERSATION;
}

/**
 * Sets the conversation data to display when triggered.
 * @param conversation definition to display and trigger in game
 */
void EventConversation::setConversation(Conversation& conversation)
{
  this->conversation = conversation;
}
