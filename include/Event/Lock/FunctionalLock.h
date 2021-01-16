/**
 * @class FunctionalLock
 *
 * Functional lock, base abstract class. This extends the {@link Lock} interface to add common
 * parameters that are shared across any usable lock that can be added to secure objects.
 */
#ifndef CORE_FUNCTIONALLOCK_H
#define CORE_FUNCTIONALLOCK_H

#include "Event/Lock/Lock.h"

namespace core
{
  class FunctionalLock : public Lock
  {
  private:
    /* Should the lock stay unlocked once unlocked? (single operation) */
    bool permanent = true;

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_PERMANENT;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads lock data from the XML entry, specific to the lock type (sub-class) */
    virtual void loadForType(std::string element, XmlData data, int index) = 0;

    /* Saves lock data into the XML writer, specific to the lock type (sub-class) */
    virtual void saveForType(XmlWriter* writer) const = 0;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns if the lock stays unlocked once unlocked (single operation) */
    bool isPermanent() const;

    /* Returns if the lock can be saved */
    bool isSaveable() const override;

    /* Loads lock data from the XML entry */
    void load(XmlData data, int index) override;

    /* Saves lock data into the XML writer */
    void save(XmlWriter* writer) const override;

    /* Sets if the lock stays unlocked once unlocked (single operation) */
    void setPermanent(bool permanent);
  };
};

#endif // CORE_FUNCTIONALLOCK_H
