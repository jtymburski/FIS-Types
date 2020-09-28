/**
 * @class EventMapSwitch
 *
 * A map switch event definition for the properties needed when the player triggers it
 * for changing to another map.
 */
#ifndef CORE_EVENTMAPSWITCH_H
#define CORE_EVENTMAPSWITCH_H

#include <cstdint>

#include "Event/Event.h"
#include "Event/EventType.h"

namespace core
{
  class EventMapSwitch : public Event
  {
  private:
    /* Unique identifier for the map */
    uint16_t map_id = 0;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the map ID for the player switch */
    uint16_t getMapId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the map ID that should be used for the player switch */
    void setMapId(uint16_t map_id);
  };
};

#endif // CORE_EVENTMAPSWITCH_H
