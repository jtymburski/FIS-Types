/**
 * @class EventTeleport
 *
 * A teleport event definition for the properties needed to teleport any thing within the
 * current map to another location.
 */
#include "Event/EventTeleport.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the map section ID within the current map.
 * @return section within the map, < 0 is current section where event was triggered
 */
int16_t EventTeleport::getSectionId() const
{
  return section_id;
}

/**
 * Returns the target thing ID that will be teleported.
 * @return thing reference ID
 */
uint32_t EventTeleport::getThingId() const
{
  return thing_id;
}

/**
 * Returns the map section grid X (horizontal) tile location.
 * @return map grid location, in tile units
 */
uint16_t EventTeleport::getTileHorizontal() const
{
  return tile_horizontal;
}

/**
 * Returns the map section grid Y (vertical) tile location.
 * @return map grid location, in tile units
 */
uint16_t EventTeleport::getTileVertical() const
{
  return tile_vertical;
}

/**
 * Returns {@link EventType#TELEPORT} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventTeleport::getType() const
{
  return EventType::TELEPORT;
}

/**
 * Sets the map section ID within the current map.
 * @param section_id section within the map, < 0 is current section where event was triggered
 */
void EventTeleport::setSectionId(int16_t section_id)
{
  this->section_id = section_id;
}

/**
 * Sets the target thing ID that will be teleported.
 * @param thing_id thing reference ID
 */
void EventTeleport::setThingId(uint32_t thing_id)
{
  this->thing_id = thing_id;
}

/**
 * Sets the map section grid X (horizontal) tile location.
 * @param tile_horizontal map horizontal grid location, in tile units
 */
void EventTeleport::setTileHorizontal(uint16_t tile_horizontal)
{
  this->tile_horizontal = tile_horizontal;
}

/**
 * Sets the map section grid Y (vertical) tile location.
 * @param tile_vertical map vertical grid location, in tile units
 */
void EventTeleport::setTileVertical(uint16_t tile_vertical)
{
  this->tile_vertical = tile_vertical;
}
