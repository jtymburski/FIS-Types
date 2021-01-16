/**
 * @class PersistLock
 *
 * Lock persistence handling class. This handles the loading and saving of a singular lock
 * for setting up the correct lock object (by type) before executing the embedded saving/loading
 * of the KVs embedded within the object.
 */
#include "Event/Lock/PersistLock.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string PersistLock::kKEY_TYPE_ITEM = "item";
const std::string PersistLock::kKEY_TYPE_TRIGGER = "trigger";

/**
 * Lock type enumerator from string key static map.
 */
const std::map<std::string, LockType> PersistLock::kTYPE_FROM_STRING = {
  { kKEY_TYPE_ITEM,    LockType::ITEM    },
  { kKEY_TYPE_TRIGGER, LockType::TRIGGER }
};

/**
 * Lock type enumerator to string key static map.
 */
const std::map<LockType, std::string> PersistLock::kTYPE_TO_STRING = {
  { LockType::ITEM,    kKEY_TYPE_ITEM    },
  { LockType::TRIGGER, kKEY_TYPE_TRIGGER }
};

/*=============================================================================
 * PRIVATE STATIC FUNCTIONS
 *============================================================================*/

/**
 * Create an empty lock object of the given type.
 * @param type lock classification
 * @return newly created lock object
 */
Lock* PersistLock::createLockFromType(LockType type)
{
  switch(type) {
    case LockType::ITEM:
      return new LockItem();
    case LockType::TRIGGER:
      return new LockTrigger();
    default:
      throw std::domain_error("Lock type mapping for create lock is not defined");
  }
}

/*=============================================================================
 * PUBLIC STATIC FUNCTIONS
 *============================================================================*/

/**
 * Loads the individual lock data from the XML entry.
 * @param lock current lock stored locally that either needs to be augmented or thrown away
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @return augmented lock by the load state
 */
Lock* PersistLock::load(Lock* lock, XmlData data, int index)
{
  std::string element = data.getElement(index);

  auto found_type_pair = kTYPE_FROM_STRING.find(element);
  if(found_type_pair == kTYPE_FROM_STRING.end())
    throw std::domain_error("Lock type mapping for load lock is not defined");

  LockType type_from_data = found_type_pair->second;

  // Decide if the old lock can be used or if a new one need to be created
  Lock* lock_to_edit;
  if(lock->getType() != type_from_data)
    lock_to_edit = createLockFromType(type_from_data);
  else
    lock_to_edit = lock;

  // Call load in the lock
  lock_to_edit->load(data, index + 1);

  // If a new lock was created, delete the old one
  if(lock_to_edit != lock)
    delete lock;

  return lock_to_edit;
}

/**
 * Saves the individual lock data into the XML writer.
 * @param lock persist ready lock object
 * @param writer saving file handler interface
 */
void PersistLock::save(Lock* lock, XmlWriter* writer)
{
  if(lock->isSaveable())
  {
    auto found_type_pair = kTYPE_TO_STRING.find(lock->getType());
    if(found_type_pair == kTYPE_TO_STRING.end())
      throw std::domain_error("Lock type mapping for save lock is not defined");

    std::string type_string = found_type_pair->second;
    writer->writeElement(type_string);
    lock->save(writer);
    writer->jumpToParent();
  }
}
