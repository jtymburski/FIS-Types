/**
 * @class EventMultiple
 *
 * A multiple event definition that contains 1+ events that will trigger concurrently
 * when this event is triggered.
 */
#ifndef CORE_EVENTMULTIPLE_H
#define CORE_EVENTMULTIPLE_H

#include <cstdint>
#include <regex>
#include <string>
#include <vector>

#include "Event/EventNone.h"
#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"
#include "Event/PersistEvent.h"

namespace core
{
  class EventMultiple : public ExecutableEvent
  {
  public:
    /* Destructor function */
    ~EventMultiple() override;

  private:
    /* List of events that are triggered together when executed */
    std::vector<Event*> events;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_EVENT;
    const static std::string kKEY_EVENT_ID;

    /* Format representing a positive integer, 0+ */
    const static std::regex kPOSITIVE_INTEGER_FORMAT;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Deletes all events stored in the list */
    void deleteEvents();

    /* Loads event data from the XML entry, specific to the event type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Saves all event data into the XML writer, specific to the event type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

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
