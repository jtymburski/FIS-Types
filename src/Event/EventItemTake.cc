/**
 * @class EventItemTake
 *
 * A take item event definition for what will be pulled from the target player inventory
 * when triggered.
 */
#include "Event/EventItemTake.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the item count to take for the event.
 * @return item count. If set to 0, nothing will be taken.
 */
uint16_t EventItemTake::getItemCount() const
{
  return item_count;
}

/**
 * Returns the item ID that will be taken for the event.
 * @return item ID. Can be unset (<0)
 */
int32_t EventItemTake::getItemId() const
{
  return item_id;
}

/**
 * Returns {@link EventType#ITEMTAKE} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventItemTake::getType() const
{
  return EventType::ITEMTAKE;
}

/**
 * Sets the item count that will be taken when the event is triggered.
 * @param item_count take item count
 */
void EventItemTake::setItemCount(uint16_t item_count)
{
  this->item_count = item_count;
}

/**
 * Sets the item ID that will be taken when the event is triggered.
 * @param item_id the Item#getId() for event trigger. Set less than 0 to unset
 */
void EventItemTake::setItemId(int32_t item_id)
{
  this->item_id = item_id;
}
