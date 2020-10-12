/**
 * @class EventTriggerIO
 *
 * A trigger interactive object event definition for the properties needed to state change the
 * object. It executes against the object and tries to transition it or fire the stored event.
 */
#ifndef CORE_EVENTTRIGGERIO_H
#define CORE_EVENTTRIGGERIO_H

#include <cstdint>

#include "Event/Event.h"
#include "Event/EventType.h"

namespace core
{
  class EventTriggerIO : public Event
  {
  private:
    /* Unique identifier for the interactive object */
    int32_t io_id = kINITIATING_IO_ID;

    /*------------------- Constants -----------------------*/
  public:
    /* Special ID for the initiating interactive object (event source) */
    const static int32_t kINITIATING_IO_ID = -1;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the interactive object ID to trigger by the event */
    int32_t getInteractiveObjectId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the interactive object ID to trigger by the event */
    void setInteractiveObjectId(int32_t io_id);
  };
};

#endif // CORE_EVENTTRIGGERIO_H
