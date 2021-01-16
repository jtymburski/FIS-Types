/**
 * @class LockNone
 *
 * A no-op lock that will do nothing and is not functional.
 */
#include "Event/Lock/LockNone.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Deep clones the lock to return a new memory space version of the same data.
 * @return newly created lock
 */
Lock* LockNone::clone() const
{
  return new LockNone(*this);
}

/**
 * Returns {@link LockType#NONE} to define the type classification, overrides parent.
 * @return lock type classification enum
 */
LockType LockNone::getType() const
{
  return LockType::NONE;
}

/**
 * Returns if the lock can be saved using {@link save(XmlWriter*)}.
 * @return TRUE if it will generate save data
 */
bool LockNone::isSaveable() const
{
  return false;
}

/**
 * Loads lock data from the XML entry. In this implementation, it is no-op.
 */
void LockNone::load(XmlData, int)
{
}

/**
 * Saves lock data into the XML writer. In this implementation, it is no-op.
 */
void LockNone::save(XmlWriter*) const
{
}
