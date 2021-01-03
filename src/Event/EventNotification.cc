/**
 * @class EventNotification
 *
 * A notification event definition for the properties needed when a visibile UI event
 * is triggered to display text to the player.
 */
#include "Event/EventNotification.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventNotification::kKEY_TEXT = "text";

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
void EventNotification::loadForType(std::string element, XmlData data, int index)
{
  // The (index == data.getNumElements()) represents the case where the string is defined
  // immediately inside the notification event XML wrapper. It is legacy support.
  if(element == kKEY_TEXT || index == data.getNumElements())
    setNotification(data.getDataStringOrThrow());
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventNotification::saveForType(XmlWriter* writer) const
{
  writer->writeData(kKEY_TEXT, notification);
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the text string for the notification.
 * @return ascii supported text for UI display
 */
std::string EventNotification::getNotification() const
{
  return notification;
}

/**
 * Returns {@link EventType#NOTIFICATION} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventNotification::getType() const
{
  return EventType::NOTIFICATION;
}

/**
 * Sets the text string of the notification.
 * @param notification ascii supported text for UI display
 */
void EventNotification::setNotification(std::string notification)
{
  this->notification = notification;
}
