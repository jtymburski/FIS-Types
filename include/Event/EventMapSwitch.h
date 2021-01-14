/**
 * @class EventMapSwitch
 *
 * A map switch event definition for the properties needed when the player triggers it
 * for changing to another map.
 */
#ifndef CORE_EVENTMAPSWITCH_H
#define CORE_EVENTMAPSWITCH_H

#include <cstdint>

#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"

namespace core
{
  class EventMapSwitch : public ExecutableEvent
  {
  private:
    /* Unique identifier for the map */
    uint16_t map_id = 0;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_MAP_ID;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads event data from the XML entry, specific to the event type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Saves all event data into the XML writer, specific to the event type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the event to return a new memory space version of the same data */
    Event* clone() const override;

    /* Returns the map ID for the player switch */
    uint16_t getMapId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the map ID that should be used for the player switch */
    void setMapId(uint16_t map_id);
  };
};

#endif // CORE_EVENTMAPSWITCH_H
