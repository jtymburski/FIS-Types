/**
 * @class EventProperty
 *
 * A property modifier event definition which holds all thing extended properties that
 * can be modified on trigger during live gameplay. Currently, this class is designed
 * to encapsulate all properties for all sub-classes of the thing as well.
 */
#ifndef CORE_EVENTPROPERTY_H
#define CORE_EVENTPROPERTY_H

#include <cstdint>

#include "Event/Event.h"
#include "Event/EventType.h"
#include "Map/Tracking.h"

namespace core
{
  class EventProperty : public Event
  {
  private:
    /* Time to return to the previous state in the interactive object if inactive. It can
     * also toggle between enabled (with time delay) or disabled (never falls back) */
    bool io_state_inactive_disabled;
    uint32_t io_state_inactive_ms;
    bool io_state_inactive_set = false;

    /* If a player is in range, should the NPC force interaction? */
    bool npc_interaction_forced;
    bool npc_interaction_forced_set = false;

    /* NPC movement tracking when player is in range */
    Tracking npc_tracking;
    bool npc_tracking_set = false;

    /* Reset the person location back to the starting map location */
    bool person_location_reset = false;

    /* Enable or disable the person map movement */
    bool person_movement_disabled;
    bool person_movement_disabled_set = false;

    /* Person map movement speed, (tiles per second) = (speed / 4) */
    uint16_t person_speed;
    bool person_speed_set = false;

    /* Thing active state for being included in the enabled map objects (rendering, update logic) */
    bool thing_active;
    bool thing_active_set = false;

    /* Unique identifier for the thing to modify */
    int32_t thing_id = kUNSET_THING_ID;

    /* Time for the thing to respawn after visibility is disabled. It can also toggle between
     * enabled (with time delay) or disabled (never shows) */
    bool thing_respawn_disabled;
    uint32_t thing_respawn_ms;
    bool thing_respawn_set = false;

    /* The visibility of the map thing. If disabled, it will still exist and be updated
     * without being rendered */
    bool thing_visible;
    bool thing_visible_set = false;

    /*------------------- Constants -----------------------*/
  public:
    /* Unset thing ID */
    const static int32_t kUNSET_THING_ID = -1;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the time to return to the previous state in the interactive object if inactive */
    uint32_t getIOStateInactiveMillis() const;

    /* Returns the NPC movement tracking for when the player is in range */
    Tracking getNPCTracking() const;

    /* Returns the person map movement speed */
    uint16_t getPersonSpeed() const;

    /* Returns the thing ID that is modified by this event */
    int32_t getThingId() const;

    /* Returns the time for the thing to respawn after visibility is disabled */
    uint32_t getThingRespawnMillis() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Returns if the inactive timeout is disabled for the interactive object */
    bool isIOStateInactiveDisabled() const;

    /* Returns if interactive object inactive timeout property is modified in this event */
    bool isIOStateInactiveSet() const;

    /* Returns if a player is in range, the NPC will force an interaction */
    bool isNPCInteractionForced() const;

    /* Returns if NPC forced interaction is modified in this event */
    bool isNPCInteractionForcedSet() const;

    /* Returns if NPC movement tracking is modified in this event */
    bool isNPCTrackingSet() const;

    /* Returns if person location reset is triggered by this event */
    bool isPersonLocationReset() const;

    /* Returns if the person's map movement to enabled or disabled (stuck in place) */
    bool isPersonMovementDisabled() const;

    /* Returns if person disabled movement is modified in this event */
    bool isPersonMovementDisabledSet() const;

    /* Returns if person map movement speed is modified in this event */
    bool isPersonSpeedSet() const;

    /* Returns if the thing's active state should be enabled or disabled */
    bool isThingActive() const;

    /* Returns if the thing active state is modified in this event */
    bool isThingActiveSet() const;

    /* Returns if the respawn time is disabled for the thing */
    bool isThingRespawnDisabled() const;

    /* Returns if the respawn time property is modified in this event */
    bool isThingRespawnSet() const;

    /* Returns if the thing's rendering visibility should be enabled or disabled */
    bool isThingVisible() const;

    /* Returns if the thing visibile state is modified in this event */
    bool isThingVisibleSet() const;

    /* Resets the inactive timeout property to not be modified by this event */
    void resetIOStateInactive();

    /* Resets the NPC forced interaction property to not be modified by this event */
    void resetNPCInteractionForced();

    /* Resets the NPC movement tracking property to not be modified by this event */
    void resetNPCTracking();

    /* Resets the person location reset property to not be modified by this event */
    void resetPersonLocationReset();

    /* Resets the person disabled movement property to not be modified by this event */
    void resetPersonMovementDisabled();

    /* Resets the person map movement speed property to not be modified by this event */
    void resetPersonSpeed();

    /* Resets the thing active property to not be modified by this event */
    void resetThingActive();

    /* Resets the respawn time property to not be modified by this event */
    void resetThingRespawn();

    /* Resets the thing visible property to not be modified by this event */
    void resetThingVisible();

    /* Sets the inactive timeout to disabled for the interactive object */
    void setIOStateInactiveDisabled();

    /* Sets the time to return to the previous state in the interactive object if inactive */
    void setIOStateInactiveMillis(uint32_t state_inactive_ms);

    /* Sets if a player is in range, the NPC will force an interaction */
    void setNPCInteractionForced(bool interaction_forced);

    /* Sets the NPC movement tracking for when the player is in range */
    void setNPCTracking(Tracking tracking);

    /* Sets if the person's location should be set to their starting map location */
    void setPersonLocationReset();

    /* Sets the person's map movement to enabled or disabled (stuck in place) */
    void setPersonMovementDisabled(bool movement_disabled);

    /* Sets the person map movement speed */
    void setPersonSpeed(uint16_t speed);

    /* Sets if the thing's active state should be enabled or disabled */
    void setThingActive(bool active);

    /* Sets the thing ID that is modified by this event */
    void setThingId(int32_t thing_id);

    /* Sets the respawn timeout to disabled for the thing */
    void setThingRespawnDisabled();

    /* Sets the time for the thing to respawn after visibility is disabled */
    void setThingRespawnMillis(uint32_t respawn_ms);

    /* Sets if the thing's visible state should be enabled or disabled */
    void setThingVisible(bool visible);
  };
};

#endif // CORE_EVENTPROPERTY_H
