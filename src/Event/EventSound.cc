/**
 * @class EventSound
 *
 * A sound only event definition for just playing a sound on trigger.
 */
#include "Event/EventSound.h"
using namespace core;

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventSound::loadForType(std::string, XmlData data, int index)
{
  // The (index == data.getNumElements()) represents the case where the sound is defined
  // immediately inside the sound event XML wrapper. It is legacy support.
  if(index == data.getNumElements())
    setSoundId(data.getDataIntegerOrThrow());
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class). No extra
 * data is required to be saved by this event.
 */
void EventSound::saveForType(XmlWriter*) const
{
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns {@link EventType#SOUND} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventSound::getType() const
{
  return EventType::SOUND;
}
