/**
 * @class LockNone
 *
 * A no-op lock that will do nothing and is not functional.
 */
#ifndef CORE_LOCKNONE_H
#define CORE_LOCKNONE_H

#include "Event/Lock/Lock.h"

namespace core
{
  class LockNone : public Lock
  {
  public:
    /* Deep clones the lock to return a new memory space version of the same data */
    Lock* clone() const override;

    /* Returns the lock type classification */
    LockType getType() const override;

    /* Returns if the lock object can be saved */
    bool isSaveable() const override;

    /* Loads lock data from the XML entry */
    void load(XmlData data, int index) override;

    /* Saves lock data into the XML writer */
    void save(XmlWriter* writer) const override;
  };
};

#endif // CORE_LOCKNONE_H
