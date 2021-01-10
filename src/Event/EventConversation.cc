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
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventConversation::loadForType(std::string, XmlData data, int index)
{
  conversation.load(data, index);
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventConversation::saveForType(XmlWriter* writer) const
{
  conversation.save(writer);
}

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
