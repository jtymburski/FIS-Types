/**
 * @class PersistLock
 *
 * Lock persistence handling class. This handles the loading and saving of a singular lock
 * for setting up the correct lock object (by type) before executing the embedded saving/loading
 * of the KVs embedded within the object.
 */
#ifndef CORE_PERSISTLOCK_H
#define CORE_PERSISTLOCK_H

#include <map>

#include "Event/Lock/Lock.h"
#include "Event/Lock/LockItem.h"
#include "Event/Lock/LockNone.h"
#include "Event/Lock/LockTrigger.h"
#include "Event/Lock/LockType.h"
#include "Persistence/XmlData.h"
#include "Persistence/XmlWriter.h"

namespace core
{
  class PersistLock
  {
  /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_TYPE_ITEM;
    const static std::string kKEY_TYPE_NONE;
    const static std::string kKEY_TYPE_TRIGGER;

    /* Lock type enumerator from string key map */
    const static std::map<std::string, LockType> kTYPE_FROM_STRING;

    /* Lock type enumerator to string key map */
    const static std::map<LockType, std::string> kTYPE_TO_STRING;

  /*=============================================================================
   * PRIVATE STATIC FUNCTIONS
   *============================================================================*/
  private:
    /* Create an empty lock of the given type */
    static Lock* createLockFromType(LockType type);

  /*=============================================================================
   * PUBLIC STATIC FUNCTIONS
   *============================================================================*/
  public:
    /* Loads lock data from the XML entry */
    static Lock* load(Lock* lock, XmlData data, int index);

    /* Saves lock data into the XML writer */
    static void save(Lock* lock, XmlWriter* writer, bool save_if_invalid = false);
  };
};

#endif // CORE_PERSISTLOCK_H
