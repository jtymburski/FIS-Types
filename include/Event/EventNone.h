/**
 * @class EventNone
 *
 * A no-op event that will do nothing.
 */
#ifndef CORE_EVENTNONE_H
#define CORE_EVENTNONE_H

#include "Event/Event.h"
#include "Event/EventType.h"

namespace core
{
  class EventNone : public Event
  {
  public:
    /* Deep clones the event to return a new memory space version of the same data */
    Event* clone() const override;

    /* Returns event type classification */
    EventType getType() const override;

    /* Returns if the event can be saved */
    bool isSaveable() const override;

    /* Loads event data from the XML entry */
    void load(XmlData data, int index) override;

    /* Saves all event data into the XML writer */
    void save(XmlWriter* writer) const override;
  };
};

#endif // CORE_EVENTNONE_H
