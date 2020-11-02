/**
 * @class EventProperty
 *
 * A property modifier event definition which holds all thing extended properties that
 * can be modified on trigger during live gameplay. Currently, this class is designed
 * to encapsulate all properties for all sub-classes of the thing as well.
 */
#include "Event/EventProperty.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the time to return to the previous state in the interactive object if inactive.
 * @return inactivate timeout in milliseconds
 */
uint32_t EventProperty::getIOStateInactiveMillis() const
{
  return io_state_inactive_ms;
}

/**
 * Returns the NPC movement tracking for when the player is in range.
 * @return tracking enum definition
 */
Tracking EventProperty::getNPCTracking() const
{
  return npc_tracking;
}

/**
 * Returns the person map movement speed.
 * @return speed defined in units of (tiles per second) = (speed / 4).
 *         For example, a speed of 8 is 2 tiles per second of movement
 */
uint16_t EventProperty::getPersonSpeed() const
{
  return person_speed;
}

/**
 * Returns the thing ID that is modified by this event.
 * @return thing reference ID
 */
int32_t EventProperty::getThingId() const
{
  return thing_id;
}

/**
 * Returns the time for the thing to respawn after visibility is disabled.
 * @return respawn timer in milliseconds
 */
uint32_t EventProperty::getThingRespawnMillis() const
{
  return thing_respawn_ms;
}

/**
 * Returns {@link EventType#PROPERTY} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventProperty::getType() const
{
  return EventType::PROPERTY;
}

/**
 * Returns if the inactive timeout is disabled for the interactive object. When disabled,
 * the IO will never fall back to a previous state.
 * @return TRUE if inactive timeout is disabled. FALSE if enabled
 *         with timeout {@link #getIOStateInactiveMillis()}.
 */
bool EventProperty::isIOStateInactiveDisabled() const
{
  return io_state_inactive_disabled;
}

/**
 * Returns if interactive object inactive timeout property is modified in this event. If enabled,
 * {@link #isIOStateInactiveDisabled()} or {@link #getIOStateInactiveMillis()} returns the
 * changes that will be made.
 * @return TRUE if the property has been modified. FALSE if it is untouched by the event
 */
bool EventProperty::isIOStateInactiveSet() const
{
  return io_state_inactive_set;
}

/**
 * Returns if a player is in range, the NPC will force an interaction.
 * @return TRUE if it should be forced, FALSE to require the player to interact
 */
bool EventProperty::isNPCInteractionForced() const
{
  return npc_interaction_forced;
}

/**
 * Returns if NPC forced interaction property is modified in this event. If enabled,
 * {@link #isNPCInteractionForced()} returns the changes that will be made.
 * @return TRUE if the property has been modified. FALSE if it is untouched by the event
 */
bool EventProperty::isNPCInteractionForcedSet() const
{
  return npc_interaction_forced_set;
}

/**
 * Returns if NPC movement tracking is modified in this event. If enabled,
 * {@link #getNPCTracking()} returns the changes that will be made.
 * @return TRUE if the property has been modified. FALSE if it is untouched by the event
 */
bool EventProperty::isNPCTrackingSet() const
{
  return npc_tracking_set;
}

/**
 * Returns if the person's location should be set back to their starting map location.
 * @return TRUE to reset back to starting location. FALSE to do nothing
 */
bool EventProperty::isPersonLocationReset() const
{
  return person_location_reset;
}

/**
 * Returns if the person's map movement to enabled or disabled (stuck in place).
 * @return TRUE to lock the person in place. FALSE to let the movement be free based on passability
 */
bool EventProperty::isPersonMovementDisabled() const
{
  return person_movement_disabled;
}

/**
 * Returns if person disabled movement is modified in this event. If enabled,
 * {@link #isPersonMovementDisabled()} returns the changes that will be made.
 * @return TRUE if the property has been modified. FALSE if it is untouched by the event
 */
bool EventProperty::isPersonMovementDisabledSet() const
{
  return person_movement_disabled_set;
}

/**
 * Returns if person map movement speed is modified in this event. If enabled,
 * {@link #getPersonSpeed()} returns the changes that will be made.
 * @return TRUE if the property has been modified. FALSE if it is untouched by the event
 */
bool EventProperty::isPersonSpeedSet() const
{
  return person_speed_set;
}

/**
 * Returns if the thing's active state should be enabled or disabled.
 * @return TRUE if the thing should be active and part of the rendering / updating queue
 */
bool EventProperty::isThingActive() const
{
  return thing_active;
}

/**
 * Returns if the thing active state is modified in this event. If enabled,
 * {@link #isThingActive()} returns the changes that will be made.
 * @return TRUE if the property has been modified. FALSE if it is untouched by the event
 */
bool EventProperty::isThingActiveSet() const
{
  return thing_active_set;
}

/**
 * Returns if the respawn time is disabled for the thing.
 * @return TRUE to disable respawn after made inactive. FALSE to let the respawn timer decide
 */
bool EventProperty::isThingRespawnDisabled() const
{
  return thing_respawn_disabled;
}

/**
 * Returns if the respawn time property is modified in this event. If enabled,
 * {@link #isThingRespawnDisabled()} or {@link #getThingRespawnMillis()} returns the
 * changes that will be made.
 * @return TRUE if the property has been modified. FALSE if it is untouched by the event
 */
bool EventProperty::isThingRespawnSet() const
{
  return thing_respawn_set;
}

/**
 * Returns if the thing's rendering visibility should be enabled or disabled.
 * @return TRUE if the thing should be visible and part of the rendering queue
 */
bool EventProperty::isThingVisible() const
{
  return thing_visible;
}

/* Returns if the thing visibile state is modified in this event */
/**
 * Returns if the thing visibile state is modified in this event. If enabled,
 * {@link #isThingVisible()} returns the changes that will be made.
 * @return TRUE if the property has been modified. FALSE if it is untouched by the event
 */
bool EventProperty::isThingVisibleSet() const
{
  return thing_visible_set;
}

/**
 * Resets the inactive timeout property to not be modified by this event.
 */
void EventProperty::resetIOStateInactive()
{
  io_state_inactive_set = false;
}

/**
 * Resets the NPC forced interaction property to not be modified by this event.
 */
void EventProperty::resetNPCInteractionForced()
{
  npc_interaction_forced_set = false;
}

/**
 * Resets the NPC movement tracking property to not be modified by this event.
 */
void EventProperty::resetNPCTracking()
{
  npc_tracking_set = false;
}

/**
 * Resets the person location reset property to not be modified by this event.
 */
void EventProperty::resetPersonLocationReset()
{
  person_location_reset = false;
}

/**
 * Resets the person disabled movement property to not be modified by this event.
 */
void EventProperty::resetPersonMovementDisabled()
{
  person_movement_disabled_set = false;
}

/**
 * Resets the person map movement speed property to not be modified by this event.
 */
void EventProperty::resetPersonSpeed()
{
  person_speed_set = false;
}

/**
 * Resets the thing active property to not be modified by this event.
 */
void EventProperty::resetThingActive()
{
  thing_active_set = false;
}

/**
 * Resets the respawn time property to not be modified by this event.
 */
void EventProperty::resetThingRespawn()
{
  thing_respawn_set = false;
}

/**
 * Resets the thing visible property to not be modified by this event.
 */
void EventProperty::resetThingVisible()
{
  thing_visible_set = false;
}

/**
 * Sets the inactive timeout to disabled for the interactive object. It will make any IO
 * stay in the current state and not fall back.
 */
void EventProperty::setIOStateInactiveDisabled()
{
  io_state_inactive_disabled = true;
  io_state_inactive_set = true;
}

/**
 * Sets the time to return to the previous state in the interactive object if inactive.
 * @param state_inactive_ms inactive timeout in milliseconds
 */
void EventProperty::setIOStateInactiveMillis(uint32_t state_inactive_ms)
{
  io_state_inactive_disabled = false;
  io_state_inactive_ms = state_inactive_ms;
  io_state_inactive_set = true;
}

/**
 * Sets if a player is in range, the NPC will force an interaction.
 * @param interaction_forced TRUE to force interaction on player when nearby
 */
void EventProperty::setNPCInteractionForced(bool interaction_forced)
{
  npc_interaction_forced = interaction_forced;
  npc_interaction_forced_set = true;
}

/**
 * Sets the NPC movement tracking for when the player is in range.
 * @param tracking new state of tracking for the NPC
 */
void EventProperty::setNPCTracking(Tracking tracking)
{
  npc_tracking = tracking;
  npc_tracking_set = true;
}

/**
 * Sets if the person's location should be set to their starting map location.
 */
void EventProperty::setPersonLocationReset()
{
  person_location_reset = true;
}

/**
 * Sets the person's map movement to enabled or disabled (stuck in place).
 * @param movement_disabled TRUE to disable movement (stuck in place), FALSE to make movement
 *                          based on passability
 */
void EventProperty::setPersonMovementDisabled(bool movement_disabled)
{
  person_movement_disabled = movement_disabled;
  person_movement_disabled_set = true;
}

/**
 * Sets the person map movement speed.
 * @param speed configured person speed, in units (tiles per second) = (speed / 4)
 */
void EventProperty::setPersonSpeed(uint16_t speed)
{
  person_speed = speed;
  person_speed_set = true;
}

/**
 * Sets if the thing's active state should be active (part of the rendering and update queues)
 * or inactive (completely removed from the game loops).
 * @param active TRUE if the thing should be active, FALSE to make it inactive
 */
void EventProperty::setThingActive(bool active)
{
  thing_active = active;
  thing_active_set = true;
}

/**
 * Sets the thing ID that is modified by this event.
 * the Thing#getId() for event property manipulation
 */
void EventProperty::setThingId(int32_t thing_id)
{
  this->thing_id = thing_id;
}

/**
 * Sets the respawn timeout to disabled for the thing. It will prevent the thing from
 * respawning if ever made inactive
 */
void EventProperty::setThingRespawnDisabled()
{
  thing_respawn_disabled = true;
  thing_respawn_set = true;
}

/**
 * Sets the time for the thing to respawn after visibility is disabled.
 * @param respawn_ms respawn time delay in milliseconds
 */
void EventProperty::setThingRespawnMillis(uint32_t respawn_ms)
{
  thing_respawn_disabled = false;
  thing_respawn_ms = respawn_ms;
  thing_respawn_set = true;
}

/**
 * Sets if the thing's visible state should be visible (sprites rendered on map) or
 * invisible (takes up space but not rendered).
 * @param visible TRUE if the thing should be visible, FALSE to make it invisible
 */
void EventProperty::setThingVisible(bool visible)
{
  thing_visible = visible;
  thing_visible_set = true;
}