/**
 * @class EventBattleStart
 *
 * A battle start event definition for the configuration of the battle that will be set
 * up around the current player.
 */
#include "Event/EventBattleStart.h"
#include "Event/PersistEvent.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string EventBattleStart::kKEY_EVENT_LOSE = "eventlose";
const std::string EventBattleStart::kKEY_EVENT_WIN = "eventwin";
const std::string EventBattleStart::kKEY_GAME_OVER_ON_LOSS = "losegg";
const std::string EventBattleStart::kKEY_RESTORE_HEALTH = "restorehealth";
const std::string EventBattleStart::kKEY_RESTORE_QD = "restoreqd";
const std::string EventBattleStart::kKEY_TARGET_HIDE_ON_WIN = "windisappear";

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Default constructor.
 */
EventBattleStart::EventBattleStart() {}

/**
 * Copy constructor, duplicates the existing source in new memory.
 * @param source object to copy
 */
EventBattleStart::EventBattleStart(const EventBattleStart& source)
{
  cloneSource(source);
}

/**
 * Destructor function, cleans up any dynamically assigned memory managed in the class.
 */
EventBattleStart::~EventBattleStart()
{
  delete event_lose;
  delete event_win;
}

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Copy function. This duplicates (new memory) the source objects and replaces them in the
 * existing class. All existing objects will be overriden.
 * @param source object to copy
 */
void EventBattleStart::cloneSource(const EventBattleStart& source)
{
  delete event_lose;
  event_lose = source.event_lose->clone();

  delete event_win;
  event_win = source.event_win->clone();

  game_over_on_loss = source.game_over_on_loss;
  restore_health = source.restore_health;
  restore_qd = source.restore_qd;
  target_hide_on_win = source.target_hide_on_win;
}

/**
 * Loads event data from the XML entry, specific to the event type (sub-class).
 * @param element XML key name for the {@link index} in the tree
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void EventBattleStart::loadForType(std::string element, XmlData data, int index)
{
  if(element == kKEY_EVENT_LOSE)
    event_lose = PersistEvent::load(event_lose, data, index + 1);
  else if(element == kKEY_EVENT_WIN)
    event_win = PersistEvent::load(event_win, data, index + 1);
  else if(element == kKEY_GAME_OVER_ON_LOSS)
    setGameOverOnLoss(data.getDataBooleanOrThrow());
  else if(element == kKEY_RESTORE_HEALTH)
    setHealthRestored(data.getDataBooleanOrThrow());
  else if(element == kKEY_RESTORE_QD)
    setQdRestored(data.getDataBooleanOrThrow());
  else if(element == kKEY_TARGET_HIDE_ON_WIN)
    setTargetHiddenOnWin(data.getDataBooleanOrThrow());
}

/**
 * Saves all event data into the XML writer, specific to the event type (sub-class).
 * @param writer saving file handler interface
 */
void EventBattleStart::saveForType(XmlWriter* writer) const
{
  if(event_lose->isSaveable())
  {
    writer->writeElement(kKEY_EVENT_LOSE);
    PersistEvent::save(event_lose, writer);
    writer->jumpToParent();
  }
  if(event_win->isSaveable())
  {
    writer->writeElement(kKEY_EVENT_WIN);
    PersistEvent::save(event_win, writer);
    writer->jumpToParent();
  }

  if(isGameOverOnLoss())
    writer->writeData(kKEY_GAME_OVER_ON_LOSS, isGameOverOnLoss());
  if(isHealthRestored())
    writer->writeData(kKEY_RESTORE_HEALTH, isHealthRestored());
  if(isQdRestored())
    writer->writeData(kKEY_RESTORE_QD, isQdRestored());
  if(isTargetHiddenOnWin())
    writer->writeData(kKEY_TARGET_HIDE_ON_WIN, isTargetHiddenOnWin());
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the event to return a new memory space version of the same data.
 * @return newly created event
 */
Event* EventBattleStart::clone() const
{
  return new EventBattleStart(*this);
}

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

/*=============================================================================
 * OPERATOR FUNCTIONS
 *============================================================================*/

/**
 * Copy assignment operator, duplicates the existing source in new memory.
 * @param source object to copy
 * @return copied object, new memory
 */
EventBattleStart& EventBattleStart::operator=(const EventBattleStart& source)
{
  if(&source != this)
    cloneSource(source);
  return *this;
}
