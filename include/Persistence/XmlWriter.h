/**
 * @class XmlWriter
 *
 * Public interface that defines the contract functionality to write XML data to a
 * generic data source as pure C++ making no library assumptions.
 */
#ifndef CORE_XMLWRITER_H
#define CORE_XMLWRITER_H

#include <cstdint>
#include <string>

#include "Persistence/DataType.h"
#include "Persistence/XmlData.h"

namespace core
{
  class XmlWriter
  {
  /*=============================================================================
   * PUBLIC FUNCTIONS - STABLE, NON-VIRTUAL INTERFACE
   *============================================================================*/
  public:
    /* Deletes all children element and data nodes beneath the current tree location */
    bool deleteChildren();

    /* Finds a lower child node from the current node location in the XML tree */
    bool find(XmlData branch);

    /* Is the writer started already and available? */
    bool isStarted();

    /* Jumps the writer back to the parent element of the current node */
    bool jumpToParent();

    /* Jumps the writer back to the root element of the document */
    bool jumpToRoot();

    /* Sets up the writer to be able to write to the data source */
    bool start();

    /* Stops and cleans up the writer after writing to the data source */
    bool stop(bool save_changes);

    /* Writes a data node at the current tree location */
    bool writeData(std::string element, DataType type, std::string data);
    bool writeData(std::string element, bool data);
    bool writeData(std::string element, float data);
    bool writeData(std::string element, int data);
    bool writeData(std::string element, std::string data);
    bool writeData(std::string element, uint32_t data);

    /* Writes an element child at the current tree location */
    bool writeElement(std::string element, std::string key = "", std::string value = "");

    /* Writes one or more elements at the current tree location */
    bool writeElements(XmlData element_set);

  /*=============================================================================
   * PRIVATE FUNCTIONS - IMPLEMENTATION SPECIFIC, PURE VIRTUAL
   *============================================================================*/
  private:
    /* Deletes all children element and data nodes beneath the current tree location */
    virtual bool deleteChildrenFromSource() = 0;

    /* Finds a lower child node from the current node location in the XML tree */
    virtual bool findInSource(XmlData branch) = 0;

    /* Is the writer started already and available? */
    virtual bool isSourceAvailable() = 0;

    /* Jumps the writer back to the parent element of the current node */
    virtual bool jumpToParentInSource() = 0;

    /* Jumps the writer back to the root element of the document */
    virtual bool jumpToRootInSource() = 0;

    /* Sets up the writer to be able to write to the data source */
    virtual bool startWriteToSource() = 0;

    /* Stops and cleans up the writer after writing to the data source */
    virtual bool stopWriteToSource(bool save_changes) = 0;

    /* Writes a data node at the current tree location */
    virtual bool writeDataToSource(std::string element, DataType type, std::string data) = 0;
    virtual bool writeDataToSource(std::string element, bool data) = 0;
    virtual bool writeDataToSource(std::string element, float data) = 0;
    virtual bool writeDataToSource(std::string element, int data) = 0;
    virtual bool writeDataToSource(std::string element, std::string data) = 0;
    virtual bool writeDataToSource(std::string element, uint32_t data) = 0;

    /* Writes an element child at the current tree location */
    virtual bool writeElementToSource(std::string element, std::string key, std::string value) = 0;

    /* Writes one or more elements at the current tree location */
    virtual bool writeElementsToSource(XmlData element_set) = 0;
  };
};

#endif // CORE_XMLWRITER_H
