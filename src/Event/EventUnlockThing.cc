/**
 * @class EventUnlockThing
 *
 * A thing unlock event definition for the properties needed to identify the thing that
 * should be unlocked when the event is triggered.
 */
#include "Event/EventUnlockThing.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the thing ID that is unlocked by this event. If set to {@link #kINITIATING_THING_ID},
 * it will be set to unlock the initiating thing.
 * @return thing reference ID
 */
int32_t EventUnlockThing::getThingId() const
{
  return thing_id;
}

/**
 * Returns {@link EventType#UNLOCKTHING} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventUnlockThing::getType() const
{
  return EventType::UNLOCKTHING;
}

/**
 * Sets the thing ID that is unlocked by this event.
 * @param thing_id the MapThing#getId() for event unlock manipulation. {@link #kINITIATING_THING_ID}
 *                 will try and unlock the source of the event
 */
void EventUnlockThing::setThingId(int32_t thing_id)
{
  this->thing_id = thing_id;
}
