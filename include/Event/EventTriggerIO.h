/**
 * @class EventTriggerIO
 *
 * A trigger interactive object event definition for the properties needed to state change the
 * object. It executes against the object and tries to transition it or fire the stored event.
 */
#ifndef CORE_EVENTTRIGGERIO_H
#define CORE_EVENTTRIGGERIO_H

#include <cstdint>
#include <string>

#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"

namespace core
{
  class EventTriggerIO : public ExecutableEvent
  {
  private:
    /* Unique identifier for the interactive object */
    int32_t io_id = kINITIATING_IO_ID;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_IO_ID;

  public:
    /* Special ID for the initiating interactive object (event source) */
    const static int32_t kINITIATING_IO_ID = -1;

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
    /* Deep clones the event to return a new memory space version of the same data */
    Event* clone() const override;

    /* Returns the interactive object ID to trigger by the event */
    int32_t getInteractiveObjectId() const;

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the interactive object ID to trigger by the event */
    void setInteractiveObjectId(int32_t io_id);
  };
};

#endif // CORE_EVENTTRIGGERIO_H
