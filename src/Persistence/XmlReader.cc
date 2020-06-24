/**
 * @class XmlReader
 *
 * Public interface that defines the contract functionality to read XML data from a
 * generic data source as pure C++ making no library assumptions.
 */
#include "Persistence/XmlReader.h"

/*=============================================================================
 * PUBLIC FUNCTIONS - STABLE, NON-VIRTUAL INTERFACE
 *============================================================================*/

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
