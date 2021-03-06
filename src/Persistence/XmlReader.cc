/**
 * @class XmlReader
 *
 * Public interface that defines the contract functionality to read XML data from a
 * generic data source as pure C++ making no library assumptions.
 */
#include "Persistence/XmlReader.h"
using namespace core;

/*=============================================================================
 * PUBLIC FUNCTIONS - STABLE, NON-VIRTUAL INTERFACE
 *============================================================================*/

/**
 * Finds an element node from the current read location. For instance, if the
 * current tree location is at "parent.node" and the branch requested is "foo.bar", it will
 * search for "parent.node.foo.bar" in the overall document.
 * @param branch the XML data wrapper which defines the child branch to find in the tree.
 *               Using the example in the description, this would just contain "foo.bar"
 * @return true if the path was found and the read pointer was moved
 */
bool XmlReader::find(XmlData branch)
{
  return findInSource(branch);
}

/**
 * Checks if the reader has been started already and is available.
 * @return true if start() has been called and the source is still available
 */
bool XmlReader::isStarted()
{
  return isSourceAvailable();
}

/**
 * Jumps the reader reference location back to the root element of the document.
 * @return true if the reader is back at the root of the source for the next read()
 */
bool XmlReader::jumpToRoot()
{
  return jumpToRootInSource();
}

/**
 * Extracts last date that the data source was modified before beginning this read.
 * Calling start() is required to access the date field.
 * @return the date formatted as a string
 */
std::string XmlReader::lastModifiedDate()
{
  return lastModifiedDateFromSource();
}

/**
 * Reads the next XML data element at the end of a branch. Calling start() is required
 * before accessing the source.
 * @param done has the read reached the end of the source? (passed by reference)
 * @param success was the read a success? (passed by reference)
 * @return branch element that includes the full path location through the XML
 *         wrapping the data
 */
XmlData XmlReader::read(bool& done, bool& success)
{
  return readFromSource(done, success);
}

/**
 * Configures and sets up the class to start reading from the data source. This is required
 * before calling any other functions.
 * @return success status of beginning the read
 */
bool XmlReader::start()
{
  return startReadFromSource();
}

/**
 * Stops and cleans up the reader after reading from the data source.
 * @return success status of cleaning up the fragments and closing the source
 */
bool XmlReader::stop()
{
  return stopReadFromSource();
}

/**
 * Counts the total number of XML data elements available in the data source. Calling
 * start() is required to determine the total count.
 * @return total count
 */
int XmlReader::totalDataCount()
{
  return totalDataCountFromSource();
}
