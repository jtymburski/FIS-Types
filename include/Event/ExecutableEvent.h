/**
 * @class ExecutableEvent
 *
 * Executable event abstract class. This extends the base {@link Event} to add common
 * functionality that is shared across any event that can be executed by the player.
 */
#ifndef CORE_EXECUTABLEEVENT_H
#define CORE_EXECUTABLEEVENT_H

#include <cstdint>

#include "Event/Event.h"
#include "Persistence/XmlData.h"
#include "Persistence/XmlWriter.h"

namespace core
{
  class ExecutableEvent : public Event
  {
  private:
    /* Should the event only trigger once? */
    bool one_shot = false;

    /* Sound action identifier paired with the event */
    int32_t sound_id = kUNSET_SOUND_ID;

    /*------------------- Constants -----------------------*/
  public:
    /* Unset sound action ID */
    const static int32_t kUNSET_SOUND_ID = -1;

  private:
    /* Data storage key names */
    const static std::string kKEY_ONE_SHOT;
    const static std::string kKEY_SOUND_ID;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads event data from the XML entry, specific to the event type (sub-class) */
    virtual void loadForType(std::string element, XmlData data, int index) = 0;

    /* Saves all event data into the XML writer, specific to the event type (sub-class) */
    virtual void saveForType(XmlWriter* writer) const = 0;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the sound action identifier paired with the event */
    int32_t getSoundId() const;

    /* Returns if the event will only trigger once */
    bool isOneShot() const;

    /* Returns if the event can be saved */
    bool isSaveable() const override;

    /* Loads event data from the XML entry */
    void load(XmlData data, int index) override;

    /* Saves all event data into the XML writer */
    void save(XmlWriter* writer) const override;

    /* Sets if the event will only trigger once */
    void setOneShot(bool one_shot);

    /* Sets the sound action identifier paired with the event */
    void setSoundId(int32_t sound_id);
  };
};

#endif // CORE_EXECUTABLEEVENT_H
