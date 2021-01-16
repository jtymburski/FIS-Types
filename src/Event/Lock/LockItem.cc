/**
 * @class LockItem
 *
 * A lock keyed by an item class implementation. This expects an item to be in possession by the
 * interactor in order to unlock.
 */
#include "Event/Lock/LockItem.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string LockItem::kKEY_CONSUME_TO_UNLOCK = "consume";
const std::string LockItem::kKEY_ITEM_COUNT = "count";
const std::string LockItem::kKEY_ITEM_ID = "id";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads lock data from the XML entry, specific to the lock type (sub-class).
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void LockItem::loadForType(std::string element, XmlData data, int)
{
  if(element == kKEY_CONSUME_TO_UNLOCK)
    setConsumeToUnlock(data.getDataBooleanOrThrow());
  else if(element == kKEY_ITEM_ID)
    setItemId(data.getDataIntegerOrThrow());
  else if(element == kKEY_ITEM_COUNT)
    setItemCount(data.getDataIntegerOrThrow());
}

/**
 * Saves lock data into the XML writer, specific to the lock type (sub-class).
 * @param writer saving file handler interface
 */
void LockItem::saveForType(XmlWriter* writer) const
{
  writer->writeData(kKEY_ITEM_ID, getItemId());

  if(getItemCount() != kDEFAULT_ITEM_COUNT)
    writer->writeData(kKEY_ITEM_COUNT, getItemCount());
  if(!isConsumeToUnlock())
    writer->writeData(kKEY_CONSUME_TO_UNLOCK, isConsumeToUnlock());
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the lock to return a new memory space version of the same data.
 * @return newly created lock
 */
Lock* LockItem::clone() const
{
  return new LockItem(*this);
}

/**
 * Returns the number of items held by the interactor that are required to unlock.
 * @return item count. If set to 0, no item will actually be required.
 */
uint16_t LockItem::getItemCount() const
{
  return item_count;
}

/**
 * Returns the item ID that is required for the lock key.
 * @return item ID. Can be unset (<0)
 */
int32_t LockItem::getItemId() const
{
  return item_id;
}

/**
 * Returns {@link LockItem#ITEM} to define the type classification, overrides parent.
 * @return lock type classification enum
 */
LockType LockItem::getType() const
{
  return LockType::ITEM;
}

/**
 * Returns if the items should be consumed from the interactor to unlock.
 * @return TRUE to consume the items from the interactor ownership, FALSE to just verify it exists
 */
bool LockItem::isConsumeToUnlock() const
{
  return consume_to_unlock;
}

/**
 * Sets if the items should be consumed from the interactor to unlock.
 * @param consume_to_unlock TRUE to consume the items, FALSE to just verify it exists
 */
void LockItem::setConsumeToUnlock(bool consume_to_unlock)
{
  this->consume_to_unlock = consume_to_unlock;
}

/**
 * Sets the number of items held by the interactor that are required to unlock.
 * @param item_count individual item stack count
 */
void LockItem::setItemCount(uint16_t item_count)
{
  this->item_count = item_count;
}

/**
 * Sets the item ID that is required for the lock key.
 * @param item_id the Item#getId() for the lock key. Set less than 0 to unset
 */
void LockItem::setItemId(int32_t item_id)
{
  this->item_id = item_id;
}
