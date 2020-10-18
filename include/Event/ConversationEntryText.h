/**
 * @class ConversationEntryText
 *
 * Text display entry that contains readable text with optional time to show and trigger event.
 * It is modeled to both handle single entries, one after the other, and multi (option decisions)
 * by branching at an entry with the options on the next entries. This simplification was a legacy
 * decision and will be maintained until the entries can be remodeled.
 */
#ifndef CORE_CONVERSATIONENTRYTEXT_H
#define CORE_CONVERSATIONENTRYTEXT_H

#include <cstdint>
#include <string>

#include "Event/ConversationEntry.h"
#include "Event/ConversationEntryType.h"
#include "Event/Event.h"
#include "Event/EventNone.h"

namespace core
{
  class ConversationEntryText : public ConversationEntry
  {
  public:
    /* Destructor function */
    ~ConversationEntryText() override;

  private:
    /* Delay time in milliseconds to force the message to be displayed to the player */
    uint32_t delay_ms = 0;

    /* Event to trigger along with the entry */
    Event* event = new EventNone();

    /* Readable text to display */
    std::string message;

    /* Unique identifier for the thing presenting the message */
    int32_t thing_id = kINITIATING_THING_ID;

    /*------------------- Constants -----------------------*/

    /* Special ID for the initiating thing (event source) */
    const static int32_t kINITIATING_THING_ID = -1;

  public:
    /* Returns the delay time for the message to be displayed, in milliseconds */
    uint32_t getDelayMilliseconds() const;

    /* Returns the event triggered along with the entry */
    Event& getEvent() const;

    /* Returns the readable text to display */
    std::string getMessage() const;

    /* Returns the thing ID that is presenting the message */
    int32_t getThingId() const;

    /* Returns entry type classification */
    ConversationEntryType getType() const override;

    /* Sets the delay time for the message to be displayed, in milliseconds */
    void setDelayMilliseconds(uint32_t delay_ms);

    /* Sets the event triggered along with the entry */
    void setEvent(Event& event);

    /* Sets the readable text to display */
    void setMessage(std::string message);

    /* Sets the thing ID that is presenting the message */
    void setThingId(int32_t thing_id);
  };
};

#endif // CORE_CONVERSATIONENTRYTEXT_H
