/**
 * @class EventSound
 *
 * A sound only event definition for just playing a sound on trigger.
 */
#include "Event/EventSound.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns {@link EventType#SOUND} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventSound::getType() const
{
  return EventType::SOUND;
}
