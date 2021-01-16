/**
 * @class ConversationEntry
 *
 * The conversation entry is a single node in the entry decision tree. It is the base abstract
 * definition which can easily be extended to handle various entry use cases
 */
#ifndef CORE_CONVERSATIONENTRY_H
#define CORE_CONVERSATIONENTRY_H

#include <string>
#include <vector>

#include "Event/Conversation/ConversationEntryType.h"
#include "Persistence/XmlData.h"
#include "Persistence/XmlWriter.h"

namespace core
{
  class ConversationEntry
  {
  public:
    /* Default constructor */
    ConversationEntry();

    /* Copy constructor */
    ConversationEntry(const ConversationEntry& source);

    /* Destructor function */
    virtual ~ConversationEntry();

  private:
    /* Set of next entry pointers following the current text entry */
    std::vector<ConversationEntry*> next_entries;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Copy function, to be called by a copy constructor or assignment operator */
    void cloneSource(const ConversationEntry& source);

    /* Deletes all next entries stored in the list */
    void deleteNextEntries();

    /* Pad set of next entries up to the index using the filler */
    void padNextEntries(uint8_t index, ConversationEntry& filler_entry);

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deep clones the entry to return a new memory space version of the same data */
    virtual ConversationEntry* clone() const = 0;

    /* Deletes a single entry following this entry at the given index in the vector */
    void deleteNextEntry(uint8_t index);

    /* Returns a single entry following this entry at the given index in the vector */
    ConversationEntry& getNextEntry(uint8_t index) const;

    /* Returns the number of next entries linked to this entry in the vector */
    uint8_t getNextEntryCount() const;

    /* Returns the entry type classification of the implementation */
    virtual ConversationEntryType getType() const = 0;

    /* Inserts a single entry following this entry at the given index in the vector */
    void insertNextEntry(uint8_t index, ConversationEntry& entry, ConversationEntry& filler_entry);

    /* Returns if the event can be saved */
    virtual bool isSaveable() const = 0;

    /* Loads event data from the XML entry */
    virtual void load(XmlData data, int index) = 0;

    /* Saves all event data into the XML writer */
    virtual void save(XmlWriter* writer) const = 0;

    /* Sets a single entry following this entry at the given index in the vector */
    void setNextEntry(uint8_t index, ConversationEntry& entry, ConversationEntry& filler_entry);

  /*=============================================================================
   * OPERATOR FUNCTIONS
   *============================================================================*/
  public:
    ConversationEntry& operator=(const ConversationEntry& source);
  };
};

#endif // CORE_CONVERSATIONENTRY_H
