/**
 * @class Event
 *
 * Event base abstract class. This parent centralizes the common event functionality shared
 * by all implementations.
 */
#ifndef CORE_EVENT_H
#define CORE_EVENT_H

#include "Event/EventType.h"
#include "Persistence/XmlData.h"
#include "Persistence/XmlWriter.h"

namespace core
{
  class Event
  {
  public:
    /* Destructor function of the implementation */
    virtual ~Event() = 0;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the event to return a new memory space version of the same data */
    virtual Event* clone() const = 0;

    /* Returns the event type classification of the implementation */
    virtual EventType getType() const = 0;

    /* Returns if the event can be saved */
    virtual bool isSaveable() const = 0;

    /* Loads event data from the XML entry */
    virtual void load(XmlData data, int index) = 0;

    /* Saves all event data into the XML writer */
    virtual void save(XmlWriter* writer) const = 0;
  };
};

#endif // CORE_EVENT_H
