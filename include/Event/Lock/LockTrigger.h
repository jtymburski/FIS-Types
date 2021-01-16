/**
 * @class LockTrigger
 *
 * A lock keyed by an event trigger implementation. This will only unlock when triggered by
 * a {@link EventUnlock} class trigger, on the object where this lock exists.
 */
#ifndef CORE_LOCKTRIGGER_H
#define CORE_LOCKTRIGGER_H

#include "Event/Lock/FunctionalLock.h"

namespace core
{
  class LockTrigger : public FunctionalLock
  {
  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads lock data from the XML entry, specific to the lock type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Saves lock data into the XML writer, specific to the lock type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the lock to return a new memory space version of the same data */
    Lock* clone() const override;

    /* Returns lock type classification */
    LockType getType() const override;
  };
};

#endif // CORE_LOCKTRIGGER_H
