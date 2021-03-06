/**
 * @class EventUnlockIO
 *
 * An interactive object unlock event definition for the properties needed to identify the
 * object state that should be unlocked when the event is triggered.
 */
#ifndef CORE_EVENTUNLOCKIO_H
#define CORE_EVENTUNLOCKIO_H

#include <cstdint>
#include <string>

#include "Event/EventType.h"
#include "Event/EventUnlock.h"

namespace core
{
  class EventUnlockIO : public EventUnlock
  {
  private:
    /* Unique identifier for the interactive object to unlock */
    int32_t io_id = kINITIATING_IO_ID;

    /* State index within the interactive object */
    int16_t state_id = kALL_STATES_ID;

    /* Option to unlock the state enter event */
    bool unlock_event_enter = false;

    /* Option to unlock the state exit event */
    bool unlock_event_exit = false;

    /* Option to unlock the state use event */
    bool unlock_event_use = false;

    /* Option to unlock the state walkover event */
    bool unlock_event_walkover = false;

    /* Option to unlock player interaction with the object */
    bool unlock_interaction = false;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_IO_ID;
    const static std::string kKEY_STATE_ID;
    const static std::string kKEY_UNLOCK_EVENT_ALL;
    const static std::string kKEY_UNLOCK_EVENT_ENTER;
    const static std::string kKEY_UNLOCK_EVENT_EXIT;
    const static std::string kKEY_UNLOCK_EVENT_USE;
    const static std::string kKEY_UNLOCK_EVENT_WALKOVER;
    const static std::string kKEY_UNLOCK_INTERACTION;

  public:
    /* Special ID for the all states in the object */
    const static int16_t kALL_STATES_ID = -1;

    /* Special ID for the initiating interactive object (event source) */
    const static int32_t kINITIATING_IO_ID = -1;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads unlock event data from the XML entry, specific to the unlock type */
    void loadForUnlock(std::string element, XmlData data, int index) override;

    /* Saves unlock event data into the XML writer, specific to the unlock type */
    void saveForUnlock(XmlWriter* writer) const override;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the event to return a new memory space version of the same data */
    Event* clone() const override;

    /* Returns the interactive object ID that is unlocked by this event */
    int32_t getInteractiveObjectId() const;

    /* Returns the state index to target within the interactive object */
    int16_t getStateId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Returns if the event tries to unlock the state enter event */
    bool isUnlockEventEnter() const;

    /* Returns if the event tries to unlock the state exit event */
    bool isUnlockEventExit() const;

    /* Returns if the event tries to unlock the state use event */
    bool isUnlockEventUse() const;

    /* Returns if the event tries to unlock the state walkover event */
    bool isUnlockEventWalkover() const;

    /* Returns if the event tries to unlock player interaction with the object */
    bool isUnlockInteraction() const;

    /* Sets the interactive object ID that is unlocked by this event */
    void setInteractiveObjectId(int32_t io_id);

    /* Sets the state index to target within the interactive object */
    void setStateId(int16_t state_id);

    /* Sets if the event tries to unlock the state enter event */
    void setUnlockEventEnter(bool unlock_event);

    /* Sets if the event tries to unlock the state exit event */
    void setUnlockEventExit(bool unlock_event);

    /* Sets if the event tries to unlock the state use event */
    void setUnlockEventUse(bool unlock_event);

    /* Sets if the event tries to unlock the state walkover event */
    void setUnlockEventWalkover(bool unlock_event);

    /* Sets if the event tries to unlock player interaction with the object */
    void setUnlockInteraction(bool unlock_interaction);
  };
};

#endif // CORE_EVENTUNLOCKIO_H
