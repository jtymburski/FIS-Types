/**
 * @class EventTriggerIO
 *
 * A trigger interactive object event definition for the properties needed to state change the
 * object. It executes against the object and tries to transition it or fire the stored event.
 */
#include "Event/EventTriggerIO.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the interactive object ID to trigger by the event.
 * @return reference interactive object ID
 */
int32_t EventTriggerIO::getInteractiveObjectId() const
{
  return io_id;
}

/**
 * Returns {@link EventType#TRIGGERIO} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventTriggerIO::getType() const
{
  return EventType::TRIGGERIO;
}

/**
 * Sets the interactive object ID to trigger by the event.
 * @param io_id reference interactive object ID
 */
void EventTriggerIO::setInteractiveObjectId(int32_t io_id)
{
  this->io_id = io_id;
}
