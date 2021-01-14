/**
 * @class EventItemGive
 *
 * A give item event definition for what will be given to the target player inventory
 * when triggered.
 */
#include "Event/EventItemGive.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventItemGive::kKEY_CHANCE = "chance";
const std::string EventItemGive::kKEY_DROP_IF_NO_ROOM = "autodrop";
const std::string EventItemGive::kKEY_ITEM_ID = "id";
const std::string EventItemGive::kKEY_ITEM_COUNT = "count";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventItemGive::loadForType(std::string element, XmlData data, int)
{
  if(element == kKEY_CHANCE)
    setChance(data.getDataIntegerOrThrow());
  else if(element == kKEY_DROP_IF_NO_ROOM)
    setDropIfNoRoom(data.getDataBooleanOrThrow());
  else if(element == kKEY_ITEM_ID)
    setItemId(data.getDataIntegerOrThrow());
  else if(element == kKEY_ITEM_COUNT)
    setItemCount(data.getDataIntegerOrThrow());
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventItemGive::saveForType(XmlWriter* writer) const
{
  writer->writeData(kKEY_ITEM_ID, item_id);
  writer->writeData(kKEY_ITEM_COUNT, item_count);

  if(isDropIfNoRoom())
    writer->writeData(kKEY_DROP_IF_NO_ROOM, drop_if_no_room);
  if(chance < kMAX_CHANCE)
    writer->writeData(kKEY_CHANCE, chance);
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the event to return a new memory space version of the same data.
 * @return newly created event
 */
Event* EventItemGive::clone() const
{
  return new EventItemGive(*this);
}

/**
 * Returns the chance of the item being given when the event is executed.
 * @return percent chance, between 0 and {@link #kMAX_CHANCE}
 */
uint8_t EventItemGive::getChance() const
{
  return chance;
}

/**
 * Returns the item count to give for the event.
 * @return item count. If set to 0, nothing will be given.
 */
uint16_t EventItemGive::getItemCount() const
{
  return item_count;
}

/**
 * Returns the item ID that will be given for the event.
 * @return item ID. Can be unset (<0)
 */
int32_t EventItemGive::getItemId() const
{
  return item_id;
}

/**
 * Returns {@link EventType#ITEMGIVE} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventItemGive::getType() const
{
  return EventType::ITEMGIVE;
}

/**
 * Returns if items that do not fit in the inventory should be dropped.
 * @return TRUE to drop the extra items on the ground. FALSE to just discard
 */
bool EventItemGive::isDropIfNoRoom() const
{
  return drop_if_no_room;
}

/**
 * Sets the chance of the item being given when the event is executed.
 * @param chance 0 to {@link #kMAX_CHANCE} percent of the item to be given
 */
void EventItemGive::setChance(uint8_t chance)
{
  if(chance > kMAX_CHANCE)
    this->chance = kMAX_CHANCE;
  else
    this->chance = chance;
}

/**
 * Sets if items that do not fit in the inventory should be dropped.
 * @param drop_if_no_room TRUE to drop the extra items on the ground. FALSE to just discard
 */
void EventItemGive::setDropIfNoRoom(bool drop_if_no_room)
{
  this->drop_if_no_room = drop_if_no_room;
}

/**
 * Sets the item count that will be given when the event is triggered.
 * @param item_count give item count
 */
void EventItemGive::setItemCount(uint16_t item_count)
{
  this->item_count = item_count;
}

/**
 * Sets the item ID that will be given when the event is triggered.
 * @param item_id the Item#getId() for event trigger. Set less than 0 to unset
 */
void EventItemGive::setItemId(int32_t item_id)
{
  this->item_id = item_id;
}
