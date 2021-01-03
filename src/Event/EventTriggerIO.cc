/**
 * @class EventTriggerIO
 *
 * A trigger interactive object event definition for the properties needed to state change the
 * object. It executes against the object and tries to transition it or fire the stored event.
 */
#include "Event/EventTriggerIO.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventTriggerIO::kKEY_IO_ID = "id";

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventTriggerIO::loadForType(std::string element, XmlData data, int)
{
  if(element == kKEY_IO_ID)
    setInteractiveObjectId(data.getDataIntegerOrThrow());
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventTriggerIO::saveForType(XmlWriter* writer) const
{
  writer->writeData(kKEY_IO_ID, getInteractiveObjectId());
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the interactive object ID to trigger by the event.
 * @return reference interactive object ID
 */
int32_t EventTriggerIO::getInteractiveObjectId() const
{
  return io_id;
}

/**
 * Returns {@link EventType#TRIGGERIO} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventTriggerIO::getType() const
{
  return EventType::TRIGGERIO;
}

/**
 * Sets the interactive object ID to trigger by the event.
 * @param io_id reference interactive object ID
 */
void EventTriggerIO::setInteractiveObjectId(int32_t io_id)
{
  this->io_id = io_id;
}
