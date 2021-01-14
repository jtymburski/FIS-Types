/**
 * @class EventNone
 *
 * A no-op event that will do nothing.
 */
#include "Event/EventNone.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the event to return a new memory space version of the same data.
 * @return newly created event
 */
Event* EventNone::clone() const
{
  return new EventNone(*this);
}

/**
 * Returns {@link EventType#NONE} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventNone::getType() const
{
  return EventType::NONE;
}

/**
 * Returns if the event can be saved using {@link save(XmlWriter*)}.
 * @return TRUE if it will generate save data
 */
bool EventNone::isSaveable() const
{
  return false;
}

/**
 * Loads event data from the XML entry. In this implementation, it is no-op.
 */
void EventNone::load(XmlData, int)
{
}

/**
 * Saves all event data into the XML writer. In this implementation, it is no-op.
 */
void EventNone::save(XmlWriter*) const
{
}
