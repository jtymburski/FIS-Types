/**
 * @class EventUnlockThing
 *
 * A thing unlock event definition for the properties needed to identify the thing that
 * should be unlocked when the event is triggered.
 */
#ifndef CORE_EVENTUNLOCKTHING_H
#define CORE_EVENTUNLOCKTHING_H

#include <cstdint>

#include "Event/EventType.h"
#include "Event/EventUnlock.h"

namespace core
{
  class EventUnlockThing : public EventUnlock
  {
  private:
    /* Unique identifier for the thing to unlock */
    int32_t thing_id = kINITIATING_THING_ID;

  public:
    /* Special ID for the initiating thing (event source) */
    const static int32_t kINITIATING_THING_ID = -1;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the thing ID that is unlocked by this event */
    int32_t getThingId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the thing ID that is unlocked by this event */
    void setThingId(int32_t thing_id);
  };
};

#endif // CORE_EVENTUNLOCKTHING_H
