/**
 * @class EventSound
 *
 * A sound only event definition for just playing a sound on trigger.
 */
#ifndef CORE_EVENTSOUND_H
#define CORE_EVENTSOUND_H

#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"

namespace core
{
  class EventSound : public ExecutableEvent
  {
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
    /* Deep clones the event to return a new memory space version of the same data */
    Event* clone() const override;

    /* Returns event type classification */
    EventType getType() const override;
  };
};

#endif // CORE_EVENTSOUND_H
