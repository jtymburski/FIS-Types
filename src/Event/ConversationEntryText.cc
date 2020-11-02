/**
 * @class ConversationEntryText
 *
 * Text display entry that contains readable text with optional time to show and trigger event.
 * It is modeled to both handle single entries, one after the other, and multi (option decisions)
 * by branching at an entry with the options on the next entries. This simplification was a legacy
 * decision and will be maintained until the entries can be remodeled.
 */
#include "Event/ConversationEntryText.h"
using namespace core;

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Destructor function, cleans up any dynamically assigned memory managed in the class.
 */
ConversationEntryText::~ConversationEntryText()
{
  delete event;
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the delay time for the message to be displayed. This is the amount of time the
 * player is required to view this content before it can be bypassed.
 * @return delay game time, in milliseconds
 */
uint32_t ConversationEntryText::getDelayMilliseconds() const
{
  return delay_ms;
}

/**
 * Returns the event triggered along with the entry.
 * @return contained event to trigger
 */
Event& ConversationEntryText::getEvent() const
{
  return *event;
}

/**
 * Returns the readable text to display.
 * @param message standard ASCII text
 */
std::string ConversationEntryText::getMessage() const
{
  return message;
}

/**
 * Returns the thing ID that is presenting the message. If set to {@link #kINITIATING_THING_ID},
 * it will be set to use the initiating (event source) thing.
 * @return thing reference ID
 */
int32_t ConversationEntryText::getThingId() const
{
  return thing_id;
}

/**
 * Returns {@link ConversationEntryType#TEXT} to define the type classification, overrides parent.
 * @return entry type classification enum
 */
ConversationEntryType ConversationEntryText::getType() const
{
  return ConversationEntryType::TEXT;
}

/**
 * Sets the delay time for the message to be displayed. This is the amount of time the
 * player is required to view this content before it can be bypassed.
 * @param delay_ms delay game time, in milliseconds
 */
void ConversationEntryText::setDelayMilliseconds(uint32_t delay_ms)
{
  this->delay_ms = delay_ms;
}

/**
 * Sets the event triggered along with the entry.
 * @param event contained event to trigger
 */
void ConversationEntryText::setEvent(Event& event)
{
  delete this->event;
  this->event = &event;
}

/**
 * Sets the readable text to display.
 * @param message standard ASCII text
 */
void ConversationEntryText::setMessage(std::string message)
{
  this->message = message;
}

/**
 * Sets the thing ID that is presenting the message.
 * @param thing_id the MapThing#getId() for presenting in the content. {@link #kINITIATING_THING_ID}
 *                 will try and use the source of the content
 */
void ConversationEntryText::setThingId(int32_t thing_id)
{
  this->thing_id = thing_id;
}
