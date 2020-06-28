/**
 * @class XmlReader
 *
 * Public interface that defines the contract functionality to read XML data from a
 * generic data source as pure C++ making no library assumptions.
 */
#ifndef XMLREADER_H
#define XMLREADER_H

#include <string>

#include "Persistence/XmlData.h"

class XmlReader {
/*=============================================================================
 * PUBLIC FUNCTIONS - STABLE, NON-VIRTUAL INTERFACE
 *============================================================================*/
public:
  /* Finds an element node from the current read location */
  bool find(XmlData branch);

  /* Is the reader started already and available? */
  bool isStarted();

  /* Jumps the reader back to the root element of the document */
  bool jumpToRoot();

  /* Last date the data source was modified */
  std::string lastModifiedDate();

  /* Reads the next XML data element at the end of a branch */
  XmlData read(bool& done, bool& success);

  /* Sets up the reader to be able to read from the data source */
  bool start();

  /* Stops and cleans up the reader after reading from the data source */
  bool stop();

  /* Total count of the number of XML data elements available in the data source */
  int totalDataCount();

/*=============================================================================
 * PRIVATE FUNCTIONS - IMPLEMENTATION SPECIFIC, PURE VIRTUAL
 *============================================================================*/
private:
  /* Finds an element node from the current read location */
  virtual bool findInSource(XmlData branch) = 0;

  /* Is the reader started already and available? */
  virtual bool isSourceAvailable() = 0;

  /* Jumps the reader back to the root element of the document */
  virtual bool jumpToRootInSource() = 0;

  /* Last date the data source was modified */
  virtual std::string lastModifiedDateFromSource() = 0;

  /* Reads the next XML data element at the end of a branch */
  virtual XmlData readFromSource(bool& done, bool& success) = 0;

  /* Sets up the reader to be able to read from the data source */
  virtual bool startReadFromSource() = 0;

  /* Stops and cleans up the reader after reading from the data source */
  virtual bool stopReadFromSource() = 0;

  /* Total count of the number of XML data elements available in the data source */
  virtual int totalDataCountFromSource() = 0;
};

#endif // XMLREADER_H
