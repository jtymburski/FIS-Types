/**
 * @class EventNotification
 *
 * A notification event definition for the properties needed when a visibile UI event
 * is triggered to display text to the player.
 */
#ifndef CORE_EVENTNOTIFICATION_H
#define CORE_EVENTNOTIFICATION_H

#include <string>

#include "Event/Event.h"
#include "Event/EventType.h"

namespace core
{
  class EventNotification : public Event
  {
  private:
    /* Notification string to present to the player */
    std::string notification;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the text string for the notification */
    std::string getNotification() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the text string of the notification */
    void setNotification(std::string notification);
  };
};

#endif // CORE_EVENTNOTIFICATION_H
