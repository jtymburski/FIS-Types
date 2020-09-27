/**
 * @class Event
 *
 * Event base abstract class. This parent centralizes the common event functionality of
 * what can be triggered.
 */
#ifndef CORE_EVENT_H
#define CORE_EVENT_H

#include <cstdint>

#include "Event/EventType.h"

namespace core
{
  class Event
  {
  public:
    /* Destructor function of the implementation */
    virtual ~Event() = 0;

  private:
    /* Should the event only trigger once? */
    bool one_shot = false;

    /* Sound action identifier paired with the event */
    int32_t sound_id = kUNSET_SOUND_ID;

    /*------------------- Constants -----------------------*/
  public:
    /* Unset sound action ID */
    const static int32_t kUNSET_SOUND_ID = -1;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the sound action identifier paired with the event */
    int32_t getSoundId() const;

    /* Returns the event type classification of the implementation */
    virtual EventType getType() const = 0;

    /* Returns if the event will only trigger once */
    bool isOneShot() const;

    /* Sets if the event will only trigger once */
    void setOneShot(bool one_shot);

    /* Sets the sound action identifier paired with the event */
    void setSoundId(int32_t sound_id);
  };
};

#endif // CORE_EVENT_H
