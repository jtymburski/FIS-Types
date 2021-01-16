/**
 * @class LockItem
 *
 * A lock keyed by an item class implementation. This expects an item to be in possession by the
 * interactor in order to unlock.
 */
#ifndef CORE_LOCKITEM_H
#define CORE_LOCKITEM_H

#include <cstdint>

#include "Event/Lock/FunctionalLock.h"

namespace core
{
  class LockItem : public FunctionalLock
  {
  private:
    /* Consume the items from the interactor */
    bool consume_to_unlock = true;

    /* Total number of items required to unlock */
    uint16_t item_count = kDEFAULT_ITEM_COUNT;

    /* Unique identifier for the item */
    int32_t item_id = kUNSET_ITEM_ID;

    /*------------------- Constants -----------------------*/
  private:
    /* Default count for items required */
    const static uint16_t kDEFAULT_ITEM_COUNT = 1;

    /* Data storage key names */
    const static std::string kKEY_CONSUME_TO_UNLOCK;
    const static std::string kKEY_ITEM_COUNT;
    const static std::string kKEY_ITEM_ID;

    /* Unset item ID */
    const static int32_t kUNSET_ITEM_ID = -1;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads lock data from the XML entry, specific to the lock type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Saves lock data into the XML writer, specific to the lock type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the lock to return a new memory space version of the same data */
    Lock* clone() const override;

    /* Returns the number of items required to unlock by the interactor */
    uint16_t getItemCount() const;

    /* Returns the item ID that is required for the lock key */
    int32_t getItemId() const;

    /* Returns lock type classification */
    LockType getType() const override;

    /* Returns if the items should be consumed from the interactor to unlock */
    bool isConsumeToUnlock() const;

    /* Sets if the items should be consumed from the interactor to unlock */
    void setConsumeToUnlock(bool consume_to_unlock);

    /* Sets the number of items required to unlock by the interactor */
    void setItemCount(uint16_t item_count);

    /* Sets the item ID that is required for the lock key */
    void setItemId(int32_t item_id);
  };
};

#endif // CORE_LOCKITEM_H
