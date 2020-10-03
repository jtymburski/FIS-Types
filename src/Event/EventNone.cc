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
 * Returns {@link EventType#NONE} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventNone::getType() const
{
  return EventType::NONE;
}
