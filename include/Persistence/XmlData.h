/**
 * @class XmlData
 *
 * Handles a line of XML data. This is used when data is read from the XML file reader.
 * A single line represents the full element tree branch of a single endpoint.
 */
#ifndef XMLDATA_H
#define XMLDATA_H

#include <deque>
#include <string>

#include "Persistence/DataType.h"

class XmlData
{
public:
  /* Constructor: Sets up a blank template with no data in the line set */
  XmlData() = default;

  /* Constructor: Sets up a template with one data item */
  XmlData(bool data);
  XmlData(float data);
  XmlData(int data);
  XmlData(std::string data);

private:
  /* Element, key, and value stacks for data */
  std::deque<std::string> element;
  std::deque<std::string> key;
  std::deque<std::string> value;

  /* The data from the XML */
  DataType data_type = DataType::NONE;
  bool bool_data;
  float float_data;
  int int_data;
  std::string string_data;

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/
public:
  /* Add element to XML array */
  void addElementBack(std::string element, std::string key = "", std::string value = "");
  void addElementFront(std::string element, std::string key = "", std::string value = "");

  /* Get data calls - success holds if the data is actually set in the class */
  std::string getData(bool* success = nullptr);
  bool getDataBoolean(bool* success = nullptr);
  float getDataFloat(bool* success = nullptr);
  int getDataInteger(bool* success = nullptr);
  std::string getDataString(bool* success = nullptr);

  /* Returns the data type */
  DataType getDataType();

  /* Element handling */
  std::string getElement(uint16_t index);
  std::string getKey(uint16_t index);
  std::string getKeyValue(uint16_t index);
  std::string getLastElement();
  int getNumElements();

  /* Determine the type of the data */
  bool isDataBoolean();
  bool isDataFloat();
  bool isDataInteger();
  bool isDataString();
  bool isDataUnset();

  /* Delete last element - clears data */
  void removeLastElement();

  /* If the start element has been added that indicates the data, call this
   * with a string read of the data and it will be converted */
  bool setData(std::string data);

  /* Set data to encapsulate in this class */
  void setDataOfType(bool data);
  void setDataOfType(float data);
  void setDataOfType(int data);
  void setDataOfType(std::string data);
};

#endif // XMLDATA_H
