/**
 * @class EventNotification
 *
 * A notification event definition for the properties needed when a visibile UI event
 * is triggered to display text to the player.
 */
#ifndef CORE_EVENTNOTIFICATION_H
#define CORE_EVENTNOTIFICATION_H

#include <string>

#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"

namespace core
{
  class EventNotification : public ExecutableEvent
  {
  private:
    /* Notification string to present to the player */
    std::string notification;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_TEXT;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads event data from the XML entry, specific to the event type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Saves all event data into the XML writer, specific to the event type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

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
