/**
 * @class FunctionalLock
 *
 * Functional lock, base abstract class. This extends the {@link Lock} interface to add common
 * parameters that are shared across any usable lock that can be added to secure objects.
 */
#include "Event/Lock/FunctionalLock.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string FunctionalLock::kKEY_PERMANENT = "permanent";

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Should the lock stay unlocked once unlocked (single operation).
 * @return TRUE if it should stay unlocked. FALSE if it can be re-locked
 */
bool FunctionalLock::isPermanent() const
{
  return permanent;
}

/**
 * Returns if the lock can be saved using {@link save(XmlWriter*)}. All functional locks can
 * be saved.
 * @return TRUE if it will generate save data
 */
bool FunctionalLock::isSaveable() const
{
  return true;
}

/**
 * Loads lock data from the XML entry.
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @throws std::bad_cast if any correctly named element doesn't match the type expected
 */
void FunctionalLock::load(XmlData data, int index)
{
  std::string element = data.getElement(index);
  loadForType(element, data, index);

  if(element == kKEY_PERMANENT)
    setPermanent(data.getDataBooleanOrThrow());
}

/**
 * Saves lock data into the XML writer.
 * @param writer saving file handler interface
 */
void FunctionalLock::save(XmlWriter* writer) const
{
  saveForType(writer);

  if(!isPermanent())
    writer->writeData(kKEY_PERMANENT, isPermanent());
}

/**
 * Sets if the lock stays unlocked once unlocked (single operation).
 * @param permanent the new value that defines if the lock should stay unlocked
 */
void FunctionalLock::setPermanent(bool permanent)
{
  this->permanent = permanent;
}
