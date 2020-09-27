/**
 * @class EventItemGive
 *
 * A give item event definition for what will be given to the target player inventory
 * when triggered.
 */
#ifndef CORE_EVENTITEMGIVE_H
#define CORE_EVENTITEMGIVE_H

#include <cstdint>

#include "Event/Event.h"
#include "Event/EventType.h"

namespace core
{
  class EventItemGive : public Event
  {
  private:
    /* Percent chance the item will be given */
    uint8_t chance = kMAX_CHANCE;

    /* If there is no more room in the inventory, should the items be dropped */
    bool drop_if_no_room = false;

    /* Total number of items to give to the player */
    uint16_t item_count = 0;

    /* Unique identifier for the item */
    int32_t item_id = kUNSET_ITEM_ID;

    /*------------------- Constants -----------------------*/
  public:
    /* Max percent chance that can be set to give an item */
    const static uint8_t kMAX_CHANCE = 100;

    /* Unset item ID */
    const static int32_t kUNSET_ITEM_ID = -1;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the chance of the item being given */
    uint8_t getChance() const;

    /* Returns the item count to give for the event */
    uint16_t getItemCount() const;

    /* Returns the item ID that will be given for the event */
    int32_t getItemId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Returns if items that do not fit in the inventory should be dropped */
    bool isDropIfNoRoom() const;

    /* Sets the chance of the item being given */
    void setChance(uint8_t chance);

    /* Sets if items that do not fit in the inventory should be dropped */
    void setDropIfNoRoom(bool drop_if_no_room);

    /* Sets the item count that will be given when the event is triggered */
    void setItemCount(uint16_t item_count);

    /* Sets the item ID that will be given when the event is triggered */
    void setItemId(int32_t item_id);
  };
};

#endif // CORE_EVENTITEMGIVE_H
