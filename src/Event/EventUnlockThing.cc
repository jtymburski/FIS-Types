/**
 * @class EventUnlockThing
 *
 * A thing unlock event definition for the properties needed to identify the thing that
 * should be unlocked when the event is triggered.
 */
#include "Event/EventUnlockThing.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventUnlockThing::kKEY_THING_ID = "id";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads unlock event data from the XML entry, specific to the unlock type.
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventUnlockThing::loadForUnlock(std::string element, XmlData data, int)
{
  if(element == kKEY_THING_ID)
    setThingId(data.getDataIntegerOrThrow());
}

/**
 * Saves unlock event data into the XML writer, specific to the unlock type.
 * @param writer saving file handler interface
 */
void EventUnlockThing::saveForUnlock(XmlWriter* writer) const
{
  writer->writeData(kKEY_THING_ID, getThingId());
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the event to return a new memory space version of the same data.
 * @return newly created event
 */
Event* EventUnlockThing::clone() const
{
  return new EventUnlockThing(*this);
}

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
