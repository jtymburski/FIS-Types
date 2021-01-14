/**
 * @class EventUnlockIO
 *
 * An interactive object unlock event definition for the properties needed to identify the
 * object state that should be unlocked when the event is triggered.
 */
#include "Event/EventUnlockIO.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventUnlockIO::kKEY_IO_ID = "id";
const std::string EventUnlockIO::kKEY_STATE_ID = "state";
const std::string EventUnlockIO::kKEY_UNLOCK_EVENT_ALL = "eventall";
const std::string EventUnlockIO::kKEY_UNLOCK_EVENT_ENTER = "evententer";
const std::string EventUnlockIO::kKEY_UNLOCK_EVENT_EXIT = "eventexit";
const std::string EventUnlockIO::kKEY_UNLOCK_EVENT_USE = "eventuse";
const std::string EventUnlockIO::kKEY_UNLOCK_EVENT_WALKOVER = "eventwalkover";
const std::string EventUnlockIO::kKEY_UNLOCK_INTERACTION = "modelock";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads unlock event data from the XML entry, specific to the unlock type.
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventUnlockIO::loadForUnlock(std::string element, XmlData data, int)
{
  if(element == kKEY_IO_ID)
    setInteractiveObjectId(data.getDataIntegerOrThrow());
  else if(element == kKEY_STATE_ID)
    setStateId(data.getDataIntegerOrThrow());
  else if(element == kKEY_UNLOCK_EVENT_ALL)
  {
    bool unlock_event = data.getDataBooleanOrThrow();
    setUnlockEventEnter(unlock_event);
    setUnlockEventExit(unlock_event);
    setUnlockEventUse(unlock_event);
    setUnlockEventWalkover(unlock_event);
  }
  else if(element == kKEY_UNLOCK_EVENT_ENTER)
    setUnlockEventEnter(data.getDataBooleanOrThrow());
  else if(element == kKEY_UNLOCK_EVENT_EXIT)
    setUnlockEventExit(data.getDataBooleanOrThrow());
  else if(element == kKEY_UNLOCK_EVENT_USE)
    setUnlockEventUse(data.getDataBooleanOrThrow());
  else if(element == kKEY_UNLOCK_EVENT_WALKOVER)
    setUnlockEventWalkover(data.getDataBooleanOrThrow());
  else if(element == kKEY_UNLOCK_INTERACTION)
    setUnlockInteraction(data.getDataBooleanOrThrow());
}

/**
 * Saves unlock event data into the XML writer, specific to the unlock type.
 * @param writer saving file handler interface
 */
void EventUnlockIO::saveForUnlock(XmlWriter* writer) const
{
  writer->writeData(kKEY_IO_ID, getInteractiveObjectId());

  if(isUnlockInteraction())
    writer->writeData(kKEY_UNLOCK_INTERACTION, isUnlockInteraction());

  // Unlock event data
  if(isUnlockEventEnter() || isUnlockEventExit() || isUnlockEventUse() || isUnlockEventWalkover())
  {
    if(getStateId() != kALL_STATES_ID)
      writer->writeData(kKEY_STATE_ID, getStateId());

    if(isUnlockEventEnter() && isUnlockEventExit() && isUnlockEventUse() && isUnlockEventWalkover())
      writer->writeData(kKEY_UNLOCK_EVENT_ALL, true);
    else
    {
      if(isUnlockEventEnter())
        writer->writeData(kKEY_UNLOCK_EVENT_ENTER, isUnlockEventEnter());
      if(isUnlockEventExit())
        writer->writeData(kKEY_UNLOCK_EVENT_EXIT, isUnlockEventExit());
      if(isUnlockEventUse())
        writer->writeData(kKEY_UNLOCK_EVENT_USE, isUnlockEventUse());
      if(isUnlockEventWalkover())
        writer->writeData(kKEY_UNLOCK_EVENT_WALKOVER, isUnlockEventWalkover());
    }
  }
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the event to return a new memory space version of the same data.
 * @return newly created event
 */
Event* EventUnlockIO::clone() const
{
  return new EventUnlockIO(*this);
}

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
