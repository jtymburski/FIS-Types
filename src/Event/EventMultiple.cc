/**
 * @class EventMultiple
 *
 * A multiple event definition that contains 1+ events that will trigger concurrently
 * when this event is triggered.
 */
#include "Event/EventMultiple.h"
#include "Event/PersistEvent.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventMultiple::kKEY_EVENT = "event";
const std::string EventMultiple::kKEY_EVENT_ID = "id";

const std::regex EventMultiple::kPOSITIVE_INTEGER_FORMAT("^\\d+$");

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Default constructor.
 */
EventMultiple::EventMultiple() {}

/**
 * Copy constructor, duplicates the existing source in new memory.
 * @param source object to copy
 */
EventMultiple::EventMultiple(const EventMultiple& source)
{
  cloneSource(source);
}

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
 * Copy function. This duplicates (new memory) the source objects and replaces them in the
 * existing class. All existing objects will be overriden.
 * @param source object to copy
 */
void EventMultiple::cloneSource(const EventMultiple& source)
{
  deleteEvents();
  for (auto event : source.events)
    events.push_back(event->clone());
}

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

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventMultiple::loadForType(std::string element, XmlData data, int index)
{
  if(element == kKEY_EVENT)
  {
    std::string key = data.getKey(index);
    std::string key_value = data.getKeyValue(index);
    if(key == kKEY_EVENT_ID && std::regex_match(key_value, kPOSITIVE_INTEGER_FORMAT))
    {
      uint8_t event_index = std::stoi(key_value);

      if(event_index >= getEventCount())
      {
        Event* empty_event = new EventNone();;
        setEvent(event_index, *empty_event);
      }

      events[event_index] = PersistEvent::load(events.at(event_index), data, index + 1);
    }
  }
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventMultiple::saveForType(XmlWriter* writer) const
{
  for(uint32_t i = 0; i < events.size(); i++)
  {
    Event* event_to_save = events.at(i);
    if(event_to_save->isSaveable())
    {
      writer->writeElement(kKEY_EVENT, kKEY_EVENT_ID, std::to_string(i));
      PersistEvent::save(event_to_save, writer);
      writer->jumpToParent();
    }
  }
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the event to return a new memory space version of the same data.
 * @return newly created event
 */
Event* EventMultiple::clone() const
{
  return new EventMultiple(*this);
}

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

/*=============================================================================
 * OPERATOR FUNCTIONS
 *============================================================================*/

/**
 * Copy assignment operator, duplicates the existing source in new memory.
 * @param source object to copy
 * @return copied object, new memory
 */
EventMultiple& EventMultiple::operator=(const EventMultiple& source)
{
  if(&source != this)
    cloneSource(source);
  return *this;
}
