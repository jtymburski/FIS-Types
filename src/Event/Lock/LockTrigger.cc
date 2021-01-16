/**
 * @class LockTrigger
 *
 * A lock keyed by an event trigger implementation. This will only unlock when triggered by
 * a {@link EventUnlock} class trigger, on the object where this lock exists.
 */
#include "Event/Lock/LockTrigger.h"
using namespace core;

/*=============================================================================
 * PRIVATE FUNCTIONS
 *============================================================================*/

/**
 * Loads lock data from the XML entry, specific to the lock type (sub-class).
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void LockTrigger::loadForType(std::string, XmlData, int)
{
}

/**
 * Saves lock data into the XML writer, specific to the lock type (sub-class).
 */
void LockTrigger::saveForType(XmlWriter*) const
{
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the lock to return a new memory space version of the same data.
 * @return newly created lock
 */
Lock* LockTrigger::clone() const
{
  return new LockTrigger(*this);
}

/**
 * Returns {@link LockItem#TRIGGER} to define the type classification, overrides parent.
 * @return lock type classification enum
 */
LockType LockTrigger::getType() const
{
  return LockType::TRIGGER;
}
