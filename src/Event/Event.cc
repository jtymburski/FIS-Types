/**
 * @class Event
 *
 * Event base abstract class. This parent centralizes the common event functionality of
 * what can be triggered.
 */
#include "Event/Event.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Sound system identifier for the trigger on action animation of the event.
 * @return sound ID. Can be unset (<0)
 */
int32_t Event::getSoundId() const
{
  return sound_id;
}

/**
 * Should the event only trigger once when it is executed.
 * @return TRUE if it should trigger once. FALSE if it can execute each time
 */
bool Event::isOneShot() const
{
  return one_shot;
}

/**
 * Sets if the event will only trigger once.
 * @param one_shot the new value that defines if the event shuold only trigger once
 */
void Event::setOneShot(bool one_shot)
{
  this->one_shot = one_shot;
}

/**
 * Sets the sound action identifier paired with the event.
 * @param sound_id the Sound#getId() for event trigger. Set less than 0 to unset
 */
void Event::setSoundId(int32_t sound_id)
{
  this->sound_id = sound_id;
}
