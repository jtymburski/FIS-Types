/**
 * @class ExecutableEvent
 *
 * Executable event abstract class. This extends the base {@link Event} to add common
 * functionality that is shared across any event that can be executed by the player.
 */
#include "Event/ExecutableEvent.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string ExecutableEvent::kKEY_ONE_SHOT = "one_shot";
const std::string ExecutableEvent::kKEY_SOUND_ID = "sound_id";

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Sound system identifier for the trigger on action animation of the event.
 * @return sound ID. Can be unset (<0)
 */
int32_t ExecutableEvent::getSoundId() const
{
  return sound_id;
}

/**
 * Should the event only trigger once when it is executed.
 * @return TRUE if it should trigger once. FALSE if it can execute each time
 */
bool ExecutableEvent::isOneShot() const
{
  return one_shot;
}

/**
 * Returns if the event can be saved using {@link save(XmlWriter*)}. Executable events at their
 * core can be saved.
 * @return TRUE if it will generate save data
 */
bool ExecutableEvent::isSaveable() const
{
  return true;
}

/**
 * Loads event data from the XML entry.
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void ExecutableEvent::load(XmlData data, int index)
{
  std::string element = data.getElement(index);
  loadForType(element, data, index);

  if(element == kKEY_ONE_SHOT)
    setOneShot(data.getDataBooleanOrThrow());
  else if(element == kKEY_SOUND_ID)
    setSoundId(data.getDataIntegerOrThrow());
}

/**
 * Saves all event data into the XML writer.
 * @param writer saving file handler interface
 */
void ExecutableEvent::save(XmlWriter* writer) const
{
  saveForType(writer);

  if(isOneShot())
    writer->writeData(kKEY_ONE_SHOT, isOneShot());
  if(getSoundId() >= 0)
    writer->writeData(kKEY_SOUND_ID, getSoundId());
}

/**
 * Sets if the event will only trigger once.
 * @param one_shot the new value that defines if the event shuold only trigger once
 */
void ExecutableEvent::setOneShot(bool one_shot)
{
  this->one_shot = one_shot;
}

/**
 * Sets the sound action identifier paired with the event.
 * @param sound_id the Sound#getId() for event trigger. Set less than 0 to unset
 */
void ExecutableEvent::setSoundId(int32_t sound_id)
{
  this->sound_id = sound_id;
}
