/**
 * @class XmlData
 *
 * Handles a line of XML data. This is used when data is read from the XML file reader.
 * A single line represents the full element tree branch of a single endpoint.
 */
#include "Persistence/XmlData.h"

/*============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *===========================================================================*/

/**
 * Constructor function - Sets up the class with just one BOOL data element in it.
 * @param data boolean storage value to represent
 */
XmlData::XmlData(bool data)
{
  setDataOfType(data);
}

/**
 * Constructor function - Set up the class with just one FLOAT
 * @param data float storage value to represent
 */
XmlData::XmlData(float data)
{
  setDataOfType(data);
}

/**
 * Constructor function - Set up the class with just one INTEGER
 * @param data integer storage value to represent
 */
XmlData::XmlData(int data)
{
  setDataOfType(data);
}

/**
 * Constructor function - Set up the class with just one STRING
 * @param data string storage value to represent
 */
XmlData::XmlData(std::string data)
{
  setDataOfType(data);
}

/*============================================================================
 * PUBLIC FUNCTIONS
 *===========================================================================*/

/**
 * Add an element to the class. It adds it to the back of the branch stack.
 * @param element the element name (front of the tag)
 * @param key the key for the tag identifier (default "")
 * @param value the value corresponding to the key (default "")
 */
void XmlData::addElementBack(std::string element, std::string key, std::string value)
{
  this->element.push_back(element);
  this->key.push_back(key);
  this->value.push_back(value);
}

/**
 * Add an element to the class. It adds it to the front of the branch stack.
 * @param element the element name (front of the tag)
 * @param key the key for the tag identifier (default "")
 * @param value the value corresponding to the key (default "")
 */
void XmlData::addElementFront(std::string element, std::string key, std::string value)
{
  this->element.push_front(element);
  this->key.push_front(key);
  this->value.push_front(value);
}

/**
 * Returns the data stored within the class in string format for use within an xml
 * storage struct.
 * @param success status if the data in the class in not invalid
 * @return the data as a string. If unset, it returns an empty string.
 */
std::string XmlData::getData(bool* success)
{
  bool data_available = true;
  std::string data_str = "";

  /* Process the data into string form */
  if(isDataBoolean())
  {
    data_str = (bool_data ? "true" : "false");
  }
  else if(isDataInteger())
  {
    data_str = std::to_string(int_data);
  }
  else if(isDataFloat())
  {
    data_str = std::to_string(float_data);
  }
  else if(isDataString())
  {
    data_str = string_data;
  }
  else
  {
    data_available = false;
  }

  /* Return success status */
  if(success != nullptr)
    *success = data_available;

  return data_str;
}

/**
 * Returns the data stored in the class, if it's a bool.
 * @param success status if the data in the class is bool
 * @return the bool data available in the class
 */
bool XmlData::getDataBoolean(bool* success)
{
  if(success != nullptr)
    *success = isDataBoolean();
  return bool_data;
}

/**
 * Returns the data stored in the class, if it's a float.
 * @param success status if the data in the class is bool
 * @return the float data available in the class
 */
float XmlData::getDataFloat(bool* success)
{
  if(success != nullptr)
    *success = isDataFloat();
  return float_data;
}

/**
 * Returns the data stored in the class, if it's an integer.
 * @param success status if the data in the class is bool
 * @return the integer data available in the class
 */
int XmlData::getDataInteger(bool* success)
{
  if(success != nullptr)
    *success = isDataInteger();
  return int_data;
}

/**
 * Returns the data stored in the class, if it's a string.
 * @param success status if the data in the class is bool
 * @return the string data available in the class
 */
std::string XmlData::getDataString(bool* success)
{
  if(success != nullptr)
    *success = isDataString();
  return string_data;
}

/**
 * Returns the data categorizing type from the data set
 * @return the current stored data type classification
 */
DataType XmlData::getDataType()
{
  return data_type;
}

/**
 * Returns a single element of the given index, if it's within range.
 * @param index the index of the element to return
 * @return the located element. Empty string if out of range
 */
std::string XmlData::getElement(uint16_t index)
{
  if(index < element.size())
    return element[index];
  return "";
}

/**
 * Returns a single key of the given index, if it's within range. Otherwise, it's
 * returns a blank string. This key corresponds directly to the element, at the same index.
 * @param index the index of the key to return
 * @return the key to be returned
 */
std::string XmlData::getKey(uint16_t index)
{
  if(index < key.size())
    return key[index];
  return "";
}

/**
 * Returns a single value (of the key) of the given index, if it's within range.
 * Otherwise, it's returns a blank string.
 * @param index the index of the value (of the key) to return
 * @return the value (of the key) to be returned
 */
std::string XmlData::getKeyValue(uint16_t index)
{
  if(index < value.size())
    return value[index];
  return "";
}

/**
 * Extracts the last element in the branch stack of fields that wrap the data.
 * @return tag name of the last element. Blank string if no elements available
 */
std::string XmlData::getLastElement()
{
  if(element.size() > 0)
    return element.back();
  return "";
}

/**
 * Returns the number of elements that are stored. This number also indicates
 * the number of keys and values, since these directly correlate.
 * @return the number of elements in the class
 */
int XmlData::getNumElements()
{
  return element.size();
}

/**
 * Check if the data stored in the class is a boolean.
 * @return if the data is a boolean.
 */
bool XmlData::isDataBoolean()
{
  return (data_type == DataType::BOOLEAN);
}

/**
 * Check if the data stored in the class is a float.
 * @return if the data is a float.
 */
bool XmlData::isDataFloat()
{
  return (data_type == DataType::FLOAT);
}

/**
 * Check if the data stored in the class is an integer.
 * @return if the data is an integer.
 */
bool XmlData::isDataInteger()
{
  return (data_type == DataType::INTEGER);
}

/**
 * Check if the data stored in the class is a string.
 * @return if the data is a string.
 */
bool XmlData::isDataString()
{
  return (data_type == DataType::STRING);
}

/**
 * Check if the data stored in the class is unset.
 * @return if the data is unset.
 */
bool XmlData::isDataUnset()
{
  return !(isDataBoolean() || isDataFloat() || isDataInteger() || isDataString());
}

/**
 * Removes the last element on the top of the stack from the list of elements.
 * This also includes the corresponding key and value. This is a pop removal system,
 * which corresponds to the way that XML acts.
 */
void XmlData::removeLastElement()
{
  if(!element.empty())
  {
    element.pop_back();
    key.pop_back();
    value.pop_back();
  }
}

/**
 * Set data to the class. It utilizes the last entered element to determine what the
 * data should be, as per the XML standard designed around this component.
 * @param data generic storage value to represent straight from storage reader, as a string
 * @return status if insert is successful
 */
bool XmlData::setData(std::string data)
{
  bool success = true;

  /* Determine what the data is */
  if(element.size() > 0)
  {
    DataType type = static_cast<DataType>(std::stoi(value.back()));

    if(type == DataType::BOOLEAN)
      setDataOfType(data == "true");
    else if(type == DataType::INTEGER)
      setDataOfType(std::stoi(data));
    else if(type == DataType::FLOAT)
      setDataOfType(std::stof(data));
    else if(type == DataType::STRING)
      setDataOfType(data);
    else
      success = false;
  }
  else
  {
    success = false;
  }

  return success;
}

/**
 * Set data to the class, of the type bool.
 * @param data boolean storage value to represent
 */
void XmlData::setDataOfType(bool data)
{
  data_type = DataType::BOOLEAN;
  bool_data = data;
}

/**
 * Set data to the class, of the type float.
 * @param data float storage value to represent
 */
void XmlData::setDataOfType(float data)
{
  data_type = DataType::FLOAT;
  float_data = data;
}

/**
 * Set data to the class, of the type integer.
 * @param data integer storage value to represent
 */
void XmlData::setDataOfType(int data)
{
  data_type = DataType::INTEGER;
  int_data = data;
}

/**
 * Set data to the class, of the type string.
 * @param data string storage value to represent
 */
void XmlData::setDataOfType(std::string data)
{
  data_type = DataType::STRING;
  string_data = data;
}
