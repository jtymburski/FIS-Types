/**
 * @class Lock
 *
 * Lock pure interface (abstract) class. This defines the common lock functionality shared
 * by all implementations.
 */
#ifndef CORE_LOCK_H
#define CORE_LOCK_H

#include "Event/Lock/LockType.h"
#include "Persistence/XmlData.h"
#include "Persistence/XmlWriter.h"

namespace core
{
  class Lock
  {
  public:
    /* Destructor function of the implementation */
    virtual ~Lock() = 0;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the lock to return a new memory space version of the same data */
    virtual Lock* clone() const = 0;

    /* Returns the lock type classification of the implementation */
    virtual LockType getType() const = 0;

    /* Returns if the lock can be saved */
    virtual bool isSaveable() const = 0;

    /* Loads lock data from the XML entry */
    virtual void load(XmlData data, int index) = 0;

    /* Saves lock data into the XML writer */
    virtual void save(XmlWriter* writer) const = 0;
  };
};

#endif // CORE_LOCK_H
