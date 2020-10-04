/**
 * @class EventNotification
 *
 * A notification event definition for the properties needed when a visibile UI event
 * is triggered to display text to the player.
 */
#include "Event/EventNotification.h"
using namespace core;

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
