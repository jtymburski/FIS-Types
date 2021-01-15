/**
 * @class Conversation
 *
 * A conversation is one fully contained set of entries that are displayed to communicate
 * to the player through a dynamic content presentation system.
 */
#ifndef CORE_CONVERSATION_H
#define CORE_CONVERSATION_H

#include "Event/ConversationEntry.h"
#include "Event/ConversationEntryIndex.h"
#include "Event/ConversationEntryNone.h"
#include "Event/ConversationEntryText.h"
#include "Persistence/XmlData.h"
#include "Persistence/XmlWriter.h"

namespace core
{
  class Conversation
  {
  public:
    /* Constructor function */
    Conversation();

    /* Copy constructor */
    Conversation(const Conversation& source);

    /* Destructor function */
    ~Conversation();

  private:
    /* Starting conversation entry, top of the decision tree */
    ConversationEntry* root_entry = new ConversationEntryNone();

    /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_ENTRY;
    const static std::string kKEY_ENTRY_ID;
    const static std::string kKEY_ENTRY_LEGACY;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Copy function, to be called by a copy constructor or assignment operator */
    void cloneSource(const Conversation& source);

    /* Create the first entry, if one doesn't exist */
    void createFirstEntry();

    /* Recursive entry fetch to traverse the tree and return the entry at the index */
    ConversationEntry& getEntry(ConversationEntry& previous_entry,
                                const ConversationEntryIndex& index,
                                uint16_t group_max, uint16_t group = 0) const;

    /* Recursive entry fetch to traverse the tree and return the entry at the index or create it */
    ConversationEntry& getOrAddEntry(ConversationEntry& previous_entry,
                                     const ConversationEntryIndex& index,
                                     uint16_t group_max, uint16_t group = 0) const;

    /* Saves an individual conversation entry into the XML writer */
    void save(XmlWriter* writer, const ConversationEntryIndex& index,
              ConversationEntry& entry) const;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Deletes a single entry at the index in the conversation tree */
    void deleteEntry(const ConversationEntryIndex& index);

    /* Returns a single entry at the index in the conversation tree */
    ConversationEntry& getEntry(const ConversationEntryIndex& index) const;

    /* Returns the top level, first conversation entry */
    ConversationEntry& getFirstEntry() const;

    /* Returns if a single valid entry is at the index in the conversation tree */
    bool hasEntry(const ConversationEntryIndex& index) const;

    /* Inserts a single entry at the index in the conversation tree */
    void insertEntry(const ConversationEntryIndex& index, ConversationEntry& entry);

    /* Loads conversation data from the XML entry */
    void load(XmlData data, int index);

    /* Saves all conversation data into the XML writer */
    void save(XmlWriter* writer) const;

    /* Sets a single entry at the index in the conversation tree */
    void setEntry(const ConversationEntryIndex& index, ConversationEntry& entry);

  /*=============================================================================
   * OPERATOR FUNCTIONS
   *============================================================================*/
  public:
    Conversation& operator=(const Conversation& source);
  };
};

#endif // CORE_CONVERSATION_H
