/**
 * @class EventItemTake
 *
 * A take item event definition for what will be pulled from the target player inventory
 * when triggered.
 */
#include "Event/EventItemTake.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventItemTake::kKEY_ITEM_ID = "id";
const std::string EventItemTake::kKEY_ITEM_COUNT = "count";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventItemTake::loadForType(std::string element, XmlData data, int)
{
  if(element == kKEY_ITEM_ID)
    setItemId(data.getDataIntegerOrThrow());
  else if(element == kKEY_ITEM_COUNT)
    setItemCount(data.getDataIntegerOrThrow());
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventItemTake::saveForType(XmlWriter* writer) const
{
  writer->writeData(kKEY_ITEM_ID, item_id);
  writer->writeData(kKEY_ITEM_COUNT, item_count);
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the event to return a new memory space version of the same data.
 * @return newly created event
 */
Event* EventItemTake::clone() const
{
  return new EventItemTake(*this);
}

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
