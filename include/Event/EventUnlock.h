/**
 * @class EventUnlock
 *
 * Event unlock base abstract class. This bridges the common functionality of all
 * unlock events.
 */
#ifndef CORE_EVENTUNLOCK_H
#define CORE_EVENTUNLOCK_H

#include <cstdint>
#include <string>

#include "Event/ExecutableEvent.h"

namespace core
{
  class EventUnlock : public ExecutableEvent
  {
  private:
    /* Scroll the viewport to the target instead of fading in and out */
    bool view_scroll = false;

    /* Make the player view the target that is being unlocked */
    bool view_target = false;

    /* View time of the unlocking target, in milliseconds */
    uint32_t view_time_ms = kDEFAULT_VIEW_TIME_MS;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_VIEW_SCROLL;
    const static std::string kKEY_VIEW_TARGET;
    const static std::string kKEY_VIEW_TIME;

  public:
    /* Default view time of the unlocking target, in milliseconds */
    const static uint32_t kDEFAULT_VIEW_TIME_MS = 1000;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads event data from the XML entry, specific to the event type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Loads unlock event data from the XML entry, specific to the unlock type */
    virtual void loadForUnlock(std::string element, XmlData data, int index) = 0;

    /* Saves all event data into the XML writer, specific to the event type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

    /* Saves unlock event data into the XML writer, specific to the unlock type */
    virtual void saveForUnlock(XmlWriter* writer) const = 0;

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
