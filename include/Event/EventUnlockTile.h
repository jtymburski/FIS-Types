/**
 * @class EventUnlockTile
 *
 * A tile unlock event definition for the properties needed to identify the map tile that
 * should be unlocked when the event is triggered.
 */
#ifndef CORE_EVENTUNLOCKTILE_H
#define CORE_EVENTUNLOCKTILE_H

#include <cstdint>

#include "Event/EventType.h"
#include "Event/EventUnlock.h"

namespace core
{
  class EventUnlockTile : public EventUnlock
  {
  private:
    /* Map section within the current map */
    int16_t section_id = kACTIVE_SECTION_ID;

    /* Tile grid X (horizontal) location */
    uint16_t tile_horizontal = 0;

    /* Tile grid Y (vertical) location */
    uint16_t tile_vertical = 0;

    /* Option to unlock the tile enter event */
    bool unlock_event_enter = false;

    /* Option to unlock the tile exit event */
    bool unlock_event_exit = false;

    /*------------------- Constants -----------------------*/
  public:
    /* Special ID for the current active map section ID */
    const static int16_t kACTIVE_SECTION_ID = -1;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the map section ID within the current map */
    int16_t getSectionId() const;

    /* Returns the grid X (horizontal) tile location in the section */
    uint16_t getTileHorizontal() const;

    /* Returns the grid Y (vertical) tile location in the section */
    uint16_t getTileVertical() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Returns if the event tries to unlock the tile enter event */
    bool isUnlockEventEnter() const;

    /* Returns if the event tries to unlock the tile exit event */
    bool isUnlockEventExit() const;

    /* Sets the map section ID within the current map */
    void setSectionId(int16_t section_id);

    /* Sets the grid X (horizontal) tile location in the section */
    void setTileHorizontal(uint16_t tile_horizontal);

    /* Sets the grid Y (vertical) tile location in the section */
    void setTileVertical(uint16_t tile_vertical);

    /* Sets if the event tries to unlock the tile enter event */
    void setUnlockEventEnter(bool unlock_event);

    /* Sets if the event tries to unlock the tile exit event */
    void setUnlockEventExit(bool unlock_event);
  };
};

#endif // CORE_EVENTUNLOCKTILE_H
