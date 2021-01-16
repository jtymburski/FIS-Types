/**
 * @class ConversationEntryText
 *
 * Text display entry that contains readable text with optional time to show and trigger event.
 * It is modeled to both handle single entries, one after the other, and multi (option decisions)
 * by branching at an entry with the options on the next entries. This simplification was a legacy
 * decision and will be maintained until the entries can be remodeled.
 */
#include "Event/Conversation/ConversationEntryText.h"
#include "Event/PersistEvent.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string ConversationEntryText::kKEY_DELAY = "delay";
const std::string ConversationEntryText::kKEY_EVENT = "event";
const std::string ConversationEntryText::kKEY_MESSAGE = "text";
const std::string ConversationEntryText::kKEY_THING_ID = "id";

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Default constructor.
 */
ConversationEntryText::ConversationEntryText() {}

/**
 * Copy constructor, duplicates the existing source in new memory.
 * @param source object to copy
 */
ConversationEntryText::ConversationEntryText(const ConversationEntryText& source)
                     : ConversationEntry(source)
{
  cloneSource(source);
}

/**
 * Destructor function, cleans up any dynamically assigned memory managed in the class.
 */
ConversationEntryText::~ConversationEntryText()
{
  delete event;
}

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Copy function. This duplicates (new memory) the source objects and replaces them in the
 * existing class. All existing objects will be overriden.
 * @param source object to copy
 */
void ConversationEntryText::cloneSource(const ConversationEntryText& source)
{
  delay_ms = source.delay_ms;

  delete event;
  event = source.event->clone();

  message = source.message;
  thing_id = source.thing_id;
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the entry to return a new memory space version of the same data.
 * @return newly created event
 */
ConversationEntry* ConversationEntryText::clone() const
{
  return new ConversationEntryText(*this);
}

/**
 * Returns the delay time for the message to be displayed. This is the amount of time the
 * player is required to view this content before it can be bypassed.
 * @return delay game time, in milliseconds
 */
uint32_t ConversationEntryText::getDelayMilliseconds() const
{
  return delay_ms;
}

/**
 * Returns the event triggered along with the entry.
 * @return contained event to trigger
 */
Event& ConversationEntryText::getEvent() const
{
  return *event;
}

/**
 * Returns the readable text to display.
 * @param message standard ASCII text
 */
std::string ConversationEntryText::getMessage() const
{
  return message;
}

/**
 * Returns the thing ID that is presenting the message. If set to {@link #kINITIATING_THING_ID},
 * it will be set to use the initiating (event source) thing.
 * @return thing reference ID
 */
int32_t ConversationEntryText::getThingId() const
{
  return thing_id;
}

/**
 * Returns {@link ConversationEntryType#TEXT} to define the type classification, overrides parent.
 * @return entry type classification enum
 */
ConversationEntryType ConversationEntryText::getType() const
{
  return ConversationEntryType::TEXT;
}

/**
 * Returns if the conversation entry can be saved using {@link save(XmlWriter*)}.
 * @return TRUE if it will generate save data
 */
bool ConversationEntryText::isSaveable() const
{
  return true;
}

/**
 * Loads conversation entry data from the XML entry.
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 */
void ConversationEntryText::load(XmlData data, int index)
{
  std::string element = data.getElement(index);

  if(element == kKEY_DELAY)
    setDelayMilliseconds(data.getDataIntegerOrThrow());
  else if(element == kKEY_EVENT)
    event = PersistEvent::load(event, data, index + 1);
  else if(element == kKEY_MESSAGE)
    setMessage(data.getDataStringOrThrow());
  else if(element == kKEY_THING_ID)
    setThingId(data.getDataIntegerOrThrow());
}

/**
 * Saves all conversation entry data into the XML writer.
 * @param writer saving file handler interface
 */
void ConversationEntryText::save(XmlWriter* writer) const
{
  writer->writeData(kKEY_MESSAGE, getMessage());

  if(getThingId() != kINITIATING_THING_ID)
    writer->writeData(kKEY_THING_ID, getThingId());
  if(getDelayMilliseconds() > 0)
    writer->writeData(kKEY_DELAY, getDelayMilliseconds());

  if(event->isSaveable())
  {
    writer->writeElement(kKEY_EVENT);
    PersistEvent::save(event, writer);
    writer->jumpToParent();
  }
}

/**
 * Sets the delay time for the message to be displayed. This is the amount of time the
 * player is required to view this content before it can be bypassed.
 * @param delay_ms delay game time, in milliseconds
 */
void ConversationEntryText::setDelayMilliseconds(uint32_t delay_ms)
{
  this->delay_ms = delay_ms;
}

/**
 * Sets the event triggered along with the entry.
 * @param event contained event to trigger
 */
void ConversationEntryText::setEvent(Event& event)
{
  delete this->event;
  this->event = &event;
}

/**
 * Sets the readable text to display.
 * @param message standard ASCII text
 */
void ConversationEntryText::setMessage(std::string message)
{
  this->message = message;
}

/**
 * Sets the thing ID that is presenting the message.
 * @param thing_id the MapThing#getId() for presenting in the content. {@link #kINITIATING_THING_ID}
 *                 will try and use the source of the content
 */
void ConversationEntryText::setThingId(int32_t thing_id)
{
  this->thing_id = thing_id;
}

/*=============================================================================
 * OPERATOR FUNCTIONS
 *============================================================================*/

/**
 * Copy assignment operator, duplicates the existing source in new memory.
 * @param source object to copy
 * @return copied object, new memory
 */
ConversationEntryText& ConversationEntryText::operator=(const ConversationEntryText& source)
{
  ConversationEntry::operator=(source);

  if(&source != this)
    cloneSource(source);
  return *this;
}
