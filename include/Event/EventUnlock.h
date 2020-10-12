/**
 * @class EventUnlock
 *
 * Event unlock base abstract class. This bridges the common functionality of all
 * unlock events.
 */
#ifndef CORE_EVENTUNLOCK_H
#define CORE_EVENTUNLOCK_H

#include <cstdint>

#include "Event/Event.h"

namespace core
{
  class EventUnlock : public Event
  {
  private:
    /* Scroll the viewport to the target instead of fading in and out */
    bool view_scroll = false;

    /* Make the player view the target that is being unlocked */
    bool view_target = false;

    /* View time of the unlocking target, in milliseconds */
    uint32_t view_time_ms = kDEFAULT_VIEW_TIME_MS;

    /*------------------- Constants -----------------------*/
  public:
    /* Default view time of the unlocking target, in milliseconds */
    const static uint32_t kDEFAULT_VIEW_TIME_MS = 1000;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the view time of the unlocking target, in milliseconds */
    uint32_t getViewTimeMilliseconds() const;

    /* Returns if the camera should scroll viewport to the target instead of fading in and out */
    bool isViewScroll() const;

    /* Returns if the target being unlocked should be viewed by the player camera */
    bool isViewTarget() const;

    /* Sets the view time of the unlocking target, in milliseconds */
    void setViewScroll(bool scroll);

    /* Sets if the target being unlocked should be viewed by the player camera */
    void setViewTarget(bool view);

    /* Sets the view time of the unlocking target, in milliseconds */
    void setViewTimeMilliseconds(uint32_t time_ms);
  };
};

#endif // CORE_EVENTUNLOCK_H
