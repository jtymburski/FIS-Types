/**
 * @class EventMapSwitch
 *
 * A map switch event definition for the properties needed when the player triggers it
 * for changing to another map.
 */
#include "Event/EventMapSwitch.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the map ID that would become active when the event is triggered.
 * @return map reference ID
 */
/* Returns the map ID for the player switch */
uint16_t EventMapSwitch::getMapId() const
{
  return map_id;
}

/**
 * Returns {@link EventType#MAPSWITCH} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventMapSwitch::getType() const
{
  return EventType::MAPSWITCH;
}

/**
 * Sets the map ID that would become active when the event is triggered.
 * @param map_id the Map#getId() for event trigger
 */
void EventMapSwitch::setMapId(uint16_t map_id)
{
  this->map_id = map_id;
}
