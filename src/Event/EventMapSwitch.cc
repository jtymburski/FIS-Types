/**
 * @class EventMapSwitch
 *
 * A map switch event definition for the properties needed when the player triggers it
 * for changing to another map.
 */
#include "Event/EventMapSwitch.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventMapSwitch::kKEY_MAP_ID = "id";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventMapSwitch::loadForType(std::string element, XmlData data, int)
{
  if(element == kKEY_MAP_ID)
    setMapId(data.getDataIntegerOrThrow());
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventMapSwitch::saveForType(XmlWriter* writer) const
{
  writer->writeData(kKEY_MAP_ID, getMapId());
}

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
