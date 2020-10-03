/**
 * @class EventBattleStart
 *
 * A battle start event definition for the configuration of the battle that will be set
 * up around the current player.
 */
#include "Event/EventBattleStart.h"
using namespace core;

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Destructor function, cleans up any dynamically assigned memory managed in the class.
 */
EventBattleStart::~EventBattleStart()
{
  delete event_lose;
  delete event_win;
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the event triggered on battle loss.
 * @return lose event
 */
Event& EventBattleStart::getLoseEvent() const
{
  return *event_lose;
}

/**
 * Returns {@link EventType#BATTLESTART} to define the type classification, overrides parent.
 * @return event type classification enum
 */
EventType EventBattleStart::getType() const
{
  return EventType::BATTLESTART;
}

/**
 * Returns the event triggered on battle win.
 * @return win event
 */
Event& EventBattleStart::getWinEvent() const
{
  return *event_win;
}

/**
 * Returns if on lose, the game should be over.
 * @return true to end game on loss, false to go back to the map
 */
bool EventBattleStart::isGameOverOnLoss() const
{
  return game_over_on_loss;
}

/**
 * Returns if on battle end, the player health should be restored.
 * @return true to restore health to full when returning from battle. false to leave as is
 */
bool EventBattleStart::isHealthRestored() const
{
  return restore_health;
}

/**
 * Returns if on battle end, the player qd should be restored.
 * @return true to restore QD to full when returning from battle. false to leave as is
 */
bool EventBattleStart::isQdRestored() const
{
  return restore_qd;
}

/**
 * Returns if on win, the initiating target should be removed from the map.
 * @return true to hide initiating thing on win, false to leave it on the map
 */
bool EventBattleStart::isTargetHiddenOnWin() const
{
  return target_hide_on_win;
}

/**
 * Sets if on lose, the game should be over.
 * @param game_over_on_loss true to end game on loss, false to go back to the map
 */
void EventBattleStart::setGameOverOnLoss(bool game_over_on_loss)
{
  this->game_over_on_loss = game_over_on_loss;
}

/**
 * Sets if on battle end, the player health should be restored.
 * @param restore_health true to restore health to full after battle. false to leave as is
 */
void EventBattleStart::setHealthRestored(bool restore_health)
{
  this->restore_health = restore_health;
}

/**
 * Sets the event triggered on battle loss.
 * @param event triggers on battle loss
 */
void EventBattleStart::setLoseEvent(Event& event)
{
  delete this->event_lose;
  this->event_lose = &event;
}

/**
 * Sets if on battle end, the player qd should be restored.
 * @param restore_qd true to restore QD to full when returning from battle. false to leave as is
 */
void EventBattleStart::setQdRestored(bool restore_qd)
{
  this->restore_qd = restore_qd;
}

/**
 * Sets if on win, the initiating target should be removed from the map.
 * @param target_hide_on_win true to hide initiating thing on win, false to leave it on the map
 */
void EventBattleStart::setTargetHiddenOnWin(bool target_hide_on_win)
{
  this->target_hide_on_win = target_hide_on_win;
}

/**
 * Sets the event triggered on battle win.
 * @param event triggers on battle win
 */
void EventBattleStart::setWinEvent(Event& event)
{
  delete this->event_win;
  this->event_win = &event;
}
