/**
 * @class EventMultiple
 *
 * A multiple event definition that contains 1+ events that will trigger concurrently
 * when this event is triggered.
 */
#ifndef CORE_EVENTMULTIPLE_H
#define CORE_EVENTMULTIPLE_H

#include <cstdint>
#include <string>
#include <vector>

#include "Event/Event.h"
#include "Event/EventNone.h"
#include "Event/EventType.h"

namespace core
{
  class EventMultiple : public Event
  {
  public:
    /* Destructor function */
    ~EventMultiple() override;

  private:
    /* List of events that are triggered together when executed */
    std::vector<Event*> events;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Deletes all events stored in the list */
    void deleteEvents();

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the event in the multiple stack at the index location */
    Event& getEvent(uint8_t index);

    /* Returns the number of events in the multiple stack */
    uint8_t getEventCount();

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the event in the multiple stack at the index location */
    void setEvent(uint8_t index, Event& event);
  };
};

#endif // CORE_EVENTMULTIPLE_H
