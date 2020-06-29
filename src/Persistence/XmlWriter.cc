/**
 * @class XmlWriter
 *
 * Public interface that defines the contract functionality to write XML data to a
 * generic data source as pure C++ making no library assumptions.
 */
#include "Persistence/XmlWriter.h"

/*=============================================================================
 * PUBLIC FUNCTIONS - STABLE, NON-VIRTUAL INTERFACE
 *============================================================================*/

/**
 * Deletes all child elements and data nodes beneath the current write tree location.
 * @return true if the deletion was successful, regardless of if data was deleted or not
 */
bool XmlWriter::deleteChildren()
{
  return deleteChildrenFromSource();
}

/**
 * Finds a lower child node from the current node location in the XML tree. For instance, if the
 * current tree location is at "parent.node" and the branch requested is "foo.bar", it will
 * search for "parent.node.foo.bar" in the overall document.
 * @param branch the XML data wrapper which defines the child branch to find in the tree.
 *               Using the example in the description, this would just contain "foo.bar"
 * @return true if the path was found and the write pointer was moved
 */
bool XmlWriter::find(XmlData branch)
{
  return findInSource(branch);
}

/**
 * Checks if the writer has been started already and is available.
 * @return true if start() has been called and the source is still available
 */
bool XmlWriter::isStarted()
{
  return isSourceAvailable();
}

/**
 * Jumps the writer reference location in the tree up one level to the parent element. If the
 * active location is already at the root, this call will do nothing.
 * @return true if the writer had permission to move to the parent and experienced no unforeseen
 *         problems. It will return true even if its already at the root
 */
bool XmlWriter::jumpToParent()
{
  return jumpToParentInSource();
}

/**
 * Jumps the writer reference location in the tree back to the root element of the document.
 * @return true if the writer is back at the root of the source for the next write call
 */
bool XmlWriter::jumpToRoot()
{
  return jumpToRootInSource();
}

/**
 * Configures and sets up the class to start writing to the data source. This is required
 * before calling any other functions. It may or may not read a data source first into memory or
 * start with a blank empty document, depending on the implementation.
 * @return success status of beginning the write
 */
bool XmlWriter::start()
{
  return startWriteToSource();
}

/**
 * Stops and cleans up the writer after writing to the data source.
 * @param save_changes true to commit all changes made since the last start(). false will rollback
 * @return success status of cleaning up the fragments and closing the source
 */
bool XmlWriter::stop(bool save_changes)
{
  return stopWriteToSource(save_changes);
}

/**
 * Writes an element that encapsulates a data object at the current location in the XML document.
 * @param element name of the XML tag to wrap the data
 * @param type category of the data (classification)
 * @param data saveable, string converted stored and wrapped between the open and closing tags
 * @return true if successfully written to the current source
 */
bool XmlWriter::writeData(std::string element, DataType type, std::string data)
{
  return writeDataToSource(element, type, data);
}

/**
 * Writes an element that encapsulates a boolean at the current location in the XML document.
 * @param element name of the XML tag to wrap the data
 * @param data boolean type to be stored and wrapped between the open and closing tags
 * @return true if successfully written to the current source
 */
bool XmlWriter::writeData(std::string element, bool data)
{
  return writeDataToSource(element, data);
}

/**
 * Writes an element that encapsulates a float at the current location in the XML document.
 * @param element name of the XML tag to wrap the data
 * @param data float type to be stored and wrapped between the open and closing tags
 * @return true if successfully written to the current source
 */
bool XmlWriter::writeData(std::string element, float data)
{
  return writeDataToSource(element, data);
}

/**
 * Writes an element that encapsulates a integer at the current location in the XML document.
 * @param element name of the XML tag to wrap the data
 * @param data int type to be stored and wrapped between the open and closing tags
 * @return true if successfully written to the current source
 */
bool XmlWriter::writeData(std::string element, int data)
{
  return writeDataToSource(element, data);
}

/**
 * Writes an element that encapsulates a string at the current location in the XML document.
 * @param element name of the XML tag to wrap the data
 * @param data string type to be stored and wrapped between the open and closing tags
 * @return true if successfully written to the current source
 */
bool XmlWriter::writeData(std::string element, std::string data)
{
  return writeDataToSource(element, data);
}

/**
 * Writes an element that encapsulates a unsigned int at the current location in the XML document.
 * @param element name of the XML tag to wrap the data
 * @param data unsigned int type to be stored and wrapped between the open and closing tags.
 *             This wraps under the same general integer data type but handles the casting
 * @return true if successfully written to the current source
 */
bool XmlWriter::writeData(std::string element, uint32_t data)
{
  return writeDataToSource(element, data);
}

/**
 * Writes a new child element with an optional key and value attribute pair at the
 * current tree location. Once written, the internal write cursor is moved inside this child.
 * @param element name of the XML tag for the new child node
 * @param key optional attribute key inside the tag
 * @param value optional attribute value paired with the key inside the tag
 * @return true if successfully written to the current source
 */
bool XmlWriter::writeElement(std::string element, std::string key, std::string value)
{
  return writeElementToSource(element, key, value);
}

/**
 * Writes a set of child elements with the branch defined inside the data parameter. This will
 * run through all elements stored inside the set and add them one by one to the current location
 * in the tree. For instance, if the current tree location is at "parent.node" and the parameter
 * has "foo.bar" described internally, it will write "foo.bar" inside "parent.node" and result in
 * "parent.node.foo.bar" in the overall document.
 * @param element_set branch elements to write at the current tree location
 * @return true if successfully written to the current source
 */
bool XmlWriter::writeElements(XmlData element_set)
{
  return writeElementsToSource(element_set);
}
