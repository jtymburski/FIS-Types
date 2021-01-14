/**
 * @class EventUnlockThing
 *
 * A thing unlock event definition for the properties needed to identify the thing that
 * should be unlocked when the event is triggered.
 */
#ifndef CORE_EVENTUNLOCKTHING_H
#define CORE_EVENTUNLOCKTHING_H

#include <cstdint>
#include <string>

#include "Event/EventType.h"
#include "Event/EventUnlock.h"

namespace core
{
  class EventUnlockThing : public EventUnlock
  {
  private:
    /* Unique identifier for the thing to unlock */
    int32_t thing_id = kINITIATING_THING_ID;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_THING_ID;

  public:
    /* Special ID for the initiating thing (event source) */
    const static int32_t kINITIATING_THING_ID = -1;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads unlock event data from the XML entry, specific to the unlock type */
    void loadForUnlock(std::string element, XmlData data, int index) override;

    /* Saves unlock event data into the XML writer, specific to the unlock type */
    void saveForUnlock(XmlWriter* writer) const override;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the event to return a new memory space version of the same data */
    Event* clone() const override;

    /* Returns the thing ID that is unlocked by this event */
    int32_t getThingId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the thing ID that is unlocked by this event */
    void setThingId(int32_t thing_id);
  };
};

#endif // CORE_EVENTUNLOCKTHING_H
