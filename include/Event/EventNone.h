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
    /* Returns event type classification */
    EventType getType() const override;
  };
};

#endif // CORE_EVENTNONE_H
