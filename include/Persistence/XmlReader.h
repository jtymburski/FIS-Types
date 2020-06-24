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
