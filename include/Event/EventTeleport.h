/**
 * @class EventTeleport
 *
 * A teleport event definition for the properties needed to teleport any thing within the
 * current map to another location.
 */
#ifndef CORE_EVENTTELEPORT_H
#define CORE_EVENTTELEPORT_H

#include <cstdint>

#include "Event/Event.h"
#include "Event/EventType.h"

namespace core
{
  class EventTeleport : public Event
  {
  private:
    /* Map section within the current map */
    int16_t section_id = kACTIVE_SECTION_ID;

    /* Target thing ID that will be teleported */
    uint32_t thing_id = 0;

    /* Tile grid X (horizontal) location */
    uint16_t tile_horizontal = 0;

    /* Tile grid Y (vertical) location */
    uint16_t tile_vertical = 0;

    /*------------------- Constants -----------------------*/

    /* Special ID for the current active map section ID */
    const static int16_t kACTIVE_SECTION_ID = -1;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the map section ID within the current map */
    int16_t getSectionId() const;

    /* Returns the target thing ID that will be teleported */
    uint32_t getThingId() const;

    /* Returns the map section grid X (horizontal) tile location */
    uint16_t getTileHorizontal() const;

    /* Returns the map section grid Y (vertical) tile location */
    uint16_t getTileVertical() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the map section ID within the current map */
    void setSectionId(int16_t section_id);

    /* Sets the target thing ID that will be teleported */
    void setThingId(uint32_t thing_id);

    /* Sets the map section grid X (horizontal) tile location */
    void setTileHorizontal(uint16_t tile_horizontal);

    /* Sets the map section grid Y (vertical) tile location */
    void setTileVertical(uint16_t tile_vertical);
  };
};

#endif // CORE_EVENTTELEPORT_H
