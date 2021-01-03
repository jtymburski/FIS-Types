/**
 * @class EventUnlock
 *
 * Event unlock base abstract class. This bridges the common functionality of all
 * unlock events.
 */
#include "Event/EventUnlock.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventUnlock::kKEY_VIEW_SCROLL = "viewscroll";
const std::string EventUnlock::kKEY_VIEW_TARGET = "view";
const std::string EventUnlock::kKEY_VIEW_TIME = "viewtime";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventUnlock::loadForType(std::string element, XmlData data, int index)
{
  loadForUnlock(element, data, index);

  if(element == kKEY_VIEW_SCROLL)
    setViewScroll(data.getDataBooleanOrThrow());
  else if(element == kKEY_VIEW_TARGET)
    setViewTarget(data.getDataBooleanOrThrow());
  else if(element == kKEY_VIEW_TIME)
    setViewTimeMilliseconds(data.getDataIntegerOrThrow());
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventUnlock::saveForType(XmlWriter* writer) const
{
  saveForUnlock(writer);

  if(isViewTarget())
  {
    writer->writeData(kKEY_VIEW_TARGET, isViewTarget());

    if(isViewScroll())
      writer->writeData(kKEY_VIEW_SCROLL, isViewScroll());
    if(getViewTimeMilliseconds() != kDEFAULT_VIEW_TIME_MS)
      writer->writeData(kKEY_VIEW_TIME, getViewTimeMilliseconds());
  }
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the view time by the player camera of the unlocking target. This will not impact
 * anything if {@link #isViewTarget()} returns false.
 * @return view time, in milliseconds
 */
uint32_t EventUnlock::getViewTimeMilliseconds() const
{
  return view_time_ms;
}

/**
 * Returns if the camera should scroll viewport to the target instead of fading in and out.
 * This will not impact anything if {@link #isViewTarget()} returns false.
 * @return TRUE to scroll the viewport camera to the target location. FALSE to fade in / fade out
 */
bool EventUnlock::isViewScroll() const
{
  return view_scroll;
}

/**
 * Returns if the target being unlocked should be viewed by the player camera.
 * @return TRUE to view the target, FALSE to unlock without viewing
 */
bool EventUnlock::isViewTarget() const
{
  return view_target;
}

/**
 * Sets the view time of the unlocking target, in milliseconds. This will not impact
 * anything if {@link #isViewTarget()} returns false.
 * @param scroll TRUE to scroll to the target location. FALSE to fade in / fade out
 */
void EventUnlock::setViewScroll(bool scroll)
{
  this->view_scroll = scroll;
}

/**
 * Sets if the target being unlocked should be viewed by the player camera.
 * @param view TRUE to view the target, FALSE to unlock without viewing
 */
void EventUnlock::setViewTarget(bool view)
{
  this->view_target = view;
}

/**
 * Sets the view time of the unlocking target.  This will not impact anything if
 * {@link #isViewTarget()} returns false.
 * @param time_ms view time, in milliseconds
 */
void EventUnlock::setViewTimeMilliseconds(uint32_t time_ms)
{
  this->view_time_ms = time_ms;
}
