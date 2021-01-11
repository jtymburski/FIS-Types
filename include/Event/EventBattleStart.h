/**
 * @class EventBattleStart
 *
 * A battle start event definition for the configuration of the battle that will be set
 * up around the current player.
 */
#ifndef CORE_EVENTBATTLESTART_H
#define CORE_EVENTBATTLESTART_H

#include "Event/EventNone.h"
#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"

namespace core
{
  class EventBattleStart : public ExecutableEvent
  {
  public:
    /* Destructor function */
    ~EventBattleStart() override;

  private:
    /* Event to trigger on win condition */
    Event* event_lose = new EventNone();

    /* Event to trigger on lose condition */
    Event* event_win = new EventNone();

    /* If on loss, should the game be over? */
    bool game_over_on_loss = false;

    /* If on battle end, should health is restored? */
    bool restore_health = false;

    /* If on battle end, should qd is restored? */
    bool restore_qd = false;

    /* If on win, should the initiating thing disappear? */
    bool target_hide_on_win = false;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_EVENT_LOSE;
    const static std::string kKEY_EVENT_WIN;
    const static std::string kKEY_GAME_OVER_ON_LOSS;
    const static std::string kKEY_RESTORE_HEALTH;
    const static std::string kKEY_RESTORE_QD;
    const static std::string kKEY_TARGET_HIDE_ON_WIN;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads event data from the XML entry, specific to the event type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Saves all event data into the XML writer, specific to the event type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the event triggered on battle loss */
    Event& getLoseEvent() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Returns the event triggered on battle win */
    Event& getWinEvent() const;

    /* Returns if on lose, the game should be over */
    bool isGameOverOnLoss() const;

    /* Returns if on battle end, the player health should be restored */
    bool isHealthRestored() const;

    /* Returns if on battle end, the player qd should be restored */
    bool isQdRestored() const;

    /* Returns if on win, the initiating target should be removed from the map */
    bool isTargetHiddenOnWin() const;

    /* Sets if on lose, the game should be over */
    void setGameOverOnLoss(bool game_over_on_loss);

    /* Sets if on battle end, the player health should be restored */
    void setHealthRestored(bool restore_health);

    /* Sets the event triggered on battle loss */
    void setLoseEvent(Event& event);

    /* Sets if on battle end, the player qd should be restored */
    void setQdRestored(bool restore_qd);

    /* Sets if on win, the initiating target should be removed from the map */
    void setTargetHiddenOnWin(bool target_hide_on_win);

    /* Sets the event triggered on battle win */
    void setWinEvent(Event& event);
  };
};

#endif // CORE_EVENTBATTLESTART_H
