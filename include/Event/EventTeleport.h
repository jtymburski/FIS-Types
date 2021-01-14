/**
 * @class EventTeleport
 *
 * A teleport event definition for the properties needed to teleport any thing within the
 * current map to another location.
 */
#ifndef CORE_EVENTTELEPORT_H
#define CORE_EVENTTELEPORT_H

#include <cstdint>
#include <string>

#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"

namespace core
{
  class EventTeleport : public ExecutableEvent
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

    /* Data storage key names */
    const static std::string kKEY_SECTION_ID;
    const static std::string kKEY_THING_ID;
    const static std::string kKEY_TILE_HORIZONTAL;
    const static std::string kKEY_TILE_VERTICAL;

    /* Special ID for the current active map section ID */
    const static int16_t kACTIVE_SECTION_ID = -1;

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
