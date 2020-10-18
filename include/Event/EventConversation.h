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
#include "Event/Event.h"
#include "Event/EventType.h"

namespace core
{
  class EventConversation : public Event
  {
  private:
    /* Conversation data to display when triggered */
    Conversation conversation;

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
