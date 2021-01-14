/**
 * @class EventUnlockTile
 *
 * A tile unlock event definition for the properties needed to identify the map tile that
 * should be unlocked when the event is triggered.
 */
#include "Event/EventUnlockTile.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventUnlockTile::kKEY_SECTION_ID = "sectionid";
const std::string EventUnlockTile::kKEY_TILE_HORIZONTAL = "x";
const std::string EventUnlockTile::kKEY_TILE_VERTICAL = "y";
const std::string EventUnlockTile::kKEY_UNLOCK_EVENT_ALL = "eventall";
const std::string EventUnlockTile::kKEY_UNLOCK_EVENT_ENTER = "evententer";
const std::string EventUnlockTile::kKEY_UNLOCK_EVENT_EXIT = "eventexit";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads unlock event data from the XML entry, specific to the unlock type.
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventUnlockTile::loadForUnlock(std::string element, XmlData data, int)
{
  if(element == kKEY_SECTION_ID)
    setSectionId(data.getDataIntegerOrThrow());
  else if(element == kKEY_TILE_HORIZONTAL)
    setTileHorizontal(data.getDataIntegerOrThrow());
  else if(element == kKEY_TILE_VERTICAL)
    setTileVertical(data.getDataIntegerOrThrow());
  else if(element == kKEY_UNLOCK_EVENT_ALL)
  {
    bool unlock_event = data.getDataBooleanOrThrow();
    setUnlockEventEnter(unlock_event);
    setUnlockEventExit(unlock_event);
  }
  else if(element == kKEY_UNLOCK_EVENT_ENTER)
    setUnlockEventEnter(data.getDataBooleanOrThrow());
  else if(element == kKEY_UNLOCK_EVENT_EXIT)
    setUnlockEventExit(data.getDataBooleanOrThrow());
}

/**
 * Saves unlock event data into the XML writer, specific to the unlock type.
 * @param writer saving file handler interface
 */
void EventUnlockTile::saveForUnlock(XmlWriter* writer) const
{
  writer->writeData(kKEY_TILE_HORIZONTAL, getTileHorizontal());
  writer->writeData(kKEY_TILE_VERTICAL, getTileVertical());

  if(getSectionId() != kACTIVE_SECTION_ID)
    writer->writeData(kKEY_SECTION_ID, getSectionId());

  if(isUnlockEventEnter() && isUnlockEventExit())
    writer->writeData(kKEY_UNLOCK_EVENT_ALL, true);
  else
  {
    if(isUnlockEventEnter())
      writer->writeData(kKEY_UNLOCK_EVENT_ENTER, isUnlockEventEnter());
    if(isUnlockEventExit())
      writer->writeData(kKEY_UNLOCK_EVENT_EXIT, isUnlockEventExit());
  }
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the event to return a new memory space version of the same data.
 * @return newly created event
 */
Event* EventUnlockTile::clone() const
{
  return new EventUnlockTile(*this);
}

/**
 * Returns the map section ID within the current map.
 * @return section within the map, < 0 is current section where event was triggered
 */
int16_t EventUnlockTile::getSectionId() const
{
  return section_id;
}

/**
 * Returns the grid X (horizontal) tile location in the section.
 * @return map grid location, in tile units
 */
uint16_t EventUnlockTile::getTileHorizontal() const
{
  return tile_horizontal;
}

/**
 * Returns the grid Y (vertical) tile location in the section.
 * @return map grid location, in tile units
 */
uint16_t EventUnlockTile::getTileVertical() const
{
  return tile_vertical;
}

/**
 * Returns {@link EventType#UNLOCKTILE} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventUnlockTile::getType() const
{
  return EventType::UNLOCKTILE;
}

/**
 * Returns if the event tries to unlock the tile enter event.
 * @return TRUE to unlock the enter event, FALSE to ignore it
 */
bool EventUnlockTile::isUnlockEventEnter() const
{
  return unlock_event_enter;
}

/**
 * Returns if the event tries to unlock the tile exit event.
 * @return TRUE to unlock the exit event, FALSE to ignore it
 */
bool EventUnlockTile::isUnlockEventExit() const
{
  return unlock_event_exit;
}

/**
 * Sets the map section ID within the current map.
 * @param section_id section within the map, < 0 is current section where event was triggered
 */
void EventUnlockTile::setSectionId(int16_t section_id)
{
  this->section_id = section_id;
}

/**
 * Sets the grid X (horizontal) tile location in the section.
 * @param tile_horizontal map horizontal grid location, in tile units
 */
void EventUnlockTile::setTileHorizontal(uint16_t tile_horizontal)
{
  this->tile_horizontal = tile_horizontal;
}

/**
 * Sets the grid Y (vertical) tile location in the section.
 * @param tile_vertical map vertical grid location, in tile units
 */
void EventUnlockTile::setTileVertical(uint16_t tile_vertical)
{
  this->tile_vertical = tile_vertical;
}

/**
 * Sets if the event tries to unlock the tile enter event.
 * @param unlock_event TRUE to unlock the enter event, FALSE to ignore it
 */
void EventUnlockTile::setUnlockEventEnter(bool unlock_event)
{
  this->unlock_event_enter = unlock_event;
}

/**
 * Sets if the event tries to unlock the tile exit event.
 * @param unlock_event TRUE to unlock the exit event, FALSE to ignore it
 */
void EventUnlockTile::setUnlockEventExit(bool unlock_event)
{
  this->unlock_event_exit = unlock_event;
}
