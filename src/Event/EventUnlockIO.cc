/**
 * @class EventUnlockIO
 *
 * An interactive object unlock event definition for the properties needed to identify the
 * object state that should be unlocked when the event is triggered.
 */
#include "Event/EventUnlockIO.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the interactive object ID that is unlocked by this event. If set to
 * {@link #kINITIATING_IO_ID}, it will be set to unlock the initiating interactive object.
 * @return interactive object reference ID
 */
int32_t EventUnlockIO::getInteractiveObjectId() const
{
  return io_id;
}

/**
 * Returns the state index to target within the interactive object. This is for the unlock
 * events, to decide what state to target. For all, the {@link #kkALL_STATES_ID} can be used.
 * @return state index of the interactive object
 */
int16_t EventUnlockIO::getStateId() const
{
  return state_id;
}

/**
 * Returns {@link EventType#UNLOCKIO} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventUnlockIO::getType() const
{
  return EventType::UNLOCKIO;
}

/**
 * Returns if the event tries to unlock the state enter event.
 * @return TRUE to unlock the enter event, FALSE to ignore it
 */
bool EventUnlockIO::isUnlockEventEnter() const
{
  return unlock_event_enter;
}

/**
 * Returns if the event tries to unlock the state exit event.
 * @return TRUE to unlock the exit event, FALSE to ignore it
 */
bool EventUnlockIO::isUnlockEventExit() const
{
  return unlock_event_exit;
}

/**
 * Returns if the event tries to unlock the state use event.
 * @return TRUE to unlock the use event, FALSE to ignore it
 */
bool EventUnlockIO::isUnlockEventUse() const
{
  return unlock_event_use;
}

/**
 * Returns if the event tries to unlock the state walkover event.
 * @return TRUE to unlock the walkover event, FALSE to ignore it
 */
bool EventUnlockIO::isUnlockEventWalkover() const
{
  return unlock_event_walkover;
}

/**
 * Returns if the event tries to unlock player interaction with the object. The interaction lock
 * prevents the player from interacting and potentially changing the state in game.
 * @return TRUE to unlock object interaction, FALSE to ignore it
 */
bool EventUnlockIO::isUnlockInteraction() const
{
  return unlock_interaction;
}

/**
 * Sets the interactive object ID that is unlocked by this event.
 * @param io_id the MapInteractiveObject#getId() for event unlock manipulation.
 *              {@link #kINITIATING_IO_ID} will try and unlock the source of the event
 */
void EventUnlockIO::setInteractiveObjectId(int32_t io_id)
{
  this->io_id = io_id;
}

/**
 * Sets the state index to target within the interactive object. This is for the unlock
 * events, to decide what state to target. For all, the {@link #kkALL_STATES_ID} can be used.
 * @param state_id state index of the interactive object
 */
void EventUnlockIO::setStateId(int16_t state_id)
{
  this->state_id = state_id;
}

/**
 * Sets if the event tries to unlock the state enter event.
 * @param unlock_event TRUE to unlock the enter event, FALSE to ignore it
 */
void EventUnlockIO::setUnlockEventEnter(bool unlock_event)
{
  this->unlock_event_enter = unlock_event;
}

/**
 * Sets if the event tries to unlock the state exit event.
 * @param unlock_event TRUE to unlock the exit event, FALSE to ignore it
 */
void EventUnlockIO::setUnlockEventExit(bool unlock_event)
{
  this->unlock_event_exit = unlock_event;
}

/**
 * Sets if the event tries to unlock the state use event.
 * @param unlock_event TRUE to unlock the use event, FALSE to ignore it
 */
void EventUnlockIO::setUnlockEventUse(bool unlock_event)
{
  this->unlock_event_use = unlock_event;
}

/**
 * Sets if the event tries to unlock the state walkover event.
 * @param unlock_event TRUE to unlock the walkover event, FALSE to ignore it
 */
void EventUnlockIO::setUnlockEventWalkover(bool unlock_event)
{
  this->unlock_event_walkover = unlock_event;
}

/**
* Sets if the event tries to unlock player interaction with the object. The interaction lock
* prevents the player from interacting and potentially changing the state in game.
 * @param unlock_interaction TRUE to unlock object interaction, FALSE to ignore it
 */
void EventUnlockIO::setUnlockInteraction(bool unlock_interaction)
{
  this->unlock_interaction = unlock_interaction;
}
