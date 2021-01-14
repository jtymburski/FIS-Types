/**
 * @class EventItemTake
 *
 * A take item event definition for what will be pulled from the target player inventory
 * when triggered.
 */
#ifndef CORE_EVENTITEMTAKE_H
#define CORE_EVENTITEMTAKE_H

#include <cstdint>

#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"

namespace core
{
  class EventItemTake : public ExecutableEvent
  {
  private:
    /* Total number of items to take from the inventory */
    uint16_t item_count = 0;

    /* Unique identifier for the item */
    int32_t item_id = kUNSET_ITEM_ID;

    /*------------------- Constants -----------------------*/

    /* Data storage key names */
    const static std::string kKEY_ITEM_ID;
    const static std::string kKEY_ITEM_COUNT;

    /* Unset item ID */
    const static int32_t kUNSET_ITEM_ID = -1;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads event data from the XML entry, specific to the event type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Saves all event data into the XML writer, specific to the event type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the event to return a new memory space version of the same data */
    Event* clone() const override;

    /* Returns the item count to take for the event */
    uint16_t getItemCount() const;

    /* Returns the item ID that will be taken for the event */
    int32_t getItemId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the item count that will be taken when the event is triggered */
    void setItemCount(uint16_t item_count);

    /* Sets the item ID that will be taken when the event is triggered */
    void setItemId(int32_t item_id);
  };
};

#endif // CORE_EVENTITEMTAKE_H
