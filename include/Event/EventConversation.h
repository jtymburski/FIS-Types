/**
 * @class EventConversation
 *
 * A conversation event definition is simply the starting point to begin a conversation
 * action sequence with the interacting party (likely the player) and take over control
 * of the display.
 */
#ifndef CORE_EVENTCONVERSATION_H
#define CORE_EVENTCONVERSATION_H

#include "Event/Conversation.h"
#include "Event/EventType.h"
#include "Event/ExecutableEvent.h"

namespace core
{
  class EventConversation : public ExecutableEvent
  {
  private:
    /* Conversation data to display when triggered */
    Conversation conversation;

  /*=============================================================================
   * PRIVATE FUNCTIONS
   *============================================================================*/
  private:
    /* Loads event data from the XML entry, specific to the event type (sub-class) */
    void loadForType(std::string element, XmlData data, int index) override;

    /* Saves all event data into the XML writer, specific to the event type (sub-class) */
    void saveForType(XmlWriter* writer) const override;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the conversation data to display when triggered */
    Conversation& getConversation();

    /* Returns event type classification */
    EventType getType() const override;

    /* Sets the conversation data to display when triggered */
    void setConversation(Conversation& conversation);
  };
};

#endif // CORE_EVENTCONVERSATION_H
