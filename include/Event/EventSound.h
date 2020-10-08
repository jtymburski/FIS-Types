/**
 * @class EventSound
 *
 * A sound only event definition for just playing a sound on trigger.
 */
#ifndef CORE_EVENTSOUND_H
#define CORE_EVENTSOUND_H

#include "Event/Event.h"
#include "Event/EventType.h"

namespace core
{
  class EventSound : public Event
  {
  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns event type classification */
    EventType getType() const override;
  };
};

#endif // CORE_EVENTSOUND_H
