/**
 * @class EventItemGive
 *
 * A give item event definition for what will be given to the target player inventory
 * when triggered.
 */
#include "Event/EventItemGive.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

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
