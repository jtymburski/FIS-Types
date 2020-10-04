/**
 * @class EventMultiple
 *
 * A multiple event definition that contains 1+ events that will trigger concurrently
 * when this event is triggered.
 */
#include "Event/EventMultiple.h"
using namespace core;

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Destructor function, cleans up any dynamically assigned memory managed in the class.
 */
EventMultiple::~EventMultiple()
{
  deleteEvents();
}

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Deletes all event references in the trigger list and clears it. After execution,
 * no events will remain.
 */
void EventMultiple::deleteEvents()
{
  for(auto &event : events)
    delete event;
  events.clear();
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the event in the multiple stack at the index location.
 * @param index ordered list location
 * @return event reference at the given index. will throw exception if out of range
 */
Event& EventMultiple::getEvent(uint8_t index)
{
  if(index >= events.size())
    throw std::out_of_range("Event index=" + std::to_string(index) +
                            " is out of range in getEvent()");
  return *events.at(index);
}

/**
 * Returns the number of events in the multiple stack.
 * @return total number of events
 */
uint8_t EventMultiple::getEventCount()
{
  return events.size();
}

/**
 * Returns {@link EventType#MULTIPLE} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventMultiple::getType() const
{
 return EventType::MULTIPLE;
}

/**
 * Sets the event in the multiple stack at the index location.
 * @param index ordered list location
 * @param event new event reference to replace in the list
 */
void EventMultiple::setEvent(uint8_t index, Event& event)
{
  while(events.size() <= index)
    events.push_back(new EventNone());

  delete events[index];
  events[index] = &event;
}
