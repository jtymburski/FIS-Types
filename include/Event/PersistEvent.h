/**
 * @class PersistEvent
 *
 * Event persistence handling class. This handles the loading and saving of a singular event
 * for setting up the correct event object before executing the embedded saving/loading
 * of the KVs embedded within the object.
 */
#ifndef CORE_PERSISTEVENT_H
#define CORE_PERSISTEVENT_H

#include <map>

#include "Event/Event.h"
#include "Event/EventBattleStart.h"
#include "Event/EventConversation.h"
#include "Event/EventItemGive.h"
#include "Event/EventItemTake.h"
#include "Event/EventMapSwitch.h"
#include "Event/EventMultiple.h"
#include "Event/EventNone.h"
#include "Event/EventNotification.h"
#include "Event/EventProperty.h"
#include "Event/EventSound.h"
#include "Event/EventTeleport.h"
#include "Event/EventTriggerIO.h"
#include "Event/EventType.h"
#include "Event/EventUnlockIO.h"
#include "Event/EventUnlockThing.h"
#include "Event/EventUnlockTile.h"
#include "Persistence/XmlData.h"
#include "Persistence/XmlWriter.h"

namespace core
{
  class PersistEvent
  {
  /*------------------- Constants -----------------------*/
  private:
    /* Data storage key names */
    const static std::string kKEY_TYPE_BATTLESTART;
    const static std::string kKEY_TYPE_CONVERSATION;
    const static std::string kKEY_TYPE_ITEMGIVE;
    const static std::string kKEY_TYPE_ITEMTAKE;
    const static std::string kKEY_TYPE_MAPSWITCH;
    const static std::string kKEY_TYPE_MULTIPLE;
    const static std::string kKEY_TYPE_NONE;
    const static std::string kKEY_TYPE_NOTIFICATION;
    const static std::string kKEY_TYPE_PROPERTY;
    const static std::string kKEY_TYPE_SOUND;
    const static std::string kKEY_TYPE_TELEPORT;
    const static std::string kKEY_TYPE_TRIGGERIO;
    const static std::string kKEY_TYPE_UNLOCKIO;
    const static std::string kKEY_TYPE_UNLOCKTHING;
    const static std::string kKEY_TYPE_UNLOCKTILE;

    /* Event type enumerator from string key map */
    const static std::map<std::string, EventType> kTYPE_FROM_STRING;

    /* Event type enumerator to string key map */
    const static std::map<EventType, std::string> kTYPE_TO_STRING;

  /*=============================================================================
   * PRIVATE STATIC FUNCTIONS
   *============================================================================*/
  private:
    /* Create an empty event of the given type */
    static Event* createEventFromType(EventType type);

  /*=============================================================================
   * PUBLIC STATIC FUNCTIONS
   *============================================================================*/
  public:
    /* Loads event data from the XML entry */
    static Event* load(Event* event, XmlData data, int index);

    /* Saves all event data into the XML writer */
    static void save(Event* event, XmlWriter* writer, bool save_if_invalid = false);
  };
};

#endif // CORE_PERSISTEVENT_H
