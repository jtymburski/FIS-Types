/**
 * @class PersistEvent
 *
 * Event persistence handling class. This handles the loading and saving of a singular event
 * for setting up the correct event object before executing the embedded saving/loading
 * of the KVs embedded within the object.
 */
#include "Event/PersistEvent.h"
using namespace core;

/* Constant Implementation - see header file for descriptions */
const std::string PersistEvent::kKEY_TYPE_BATTLESTART = "startbattle";
const std::string PersistEvent::kKEY_TYPE_CONVERSATION = "conversation";
const std::string PersistEvent::kKEY_TYPE_ITEMGIVE = "giveitem";
const std::string PersistEvent::kKEY_TYPE_ITEMTAKE = "takeitem";
const std::string PersistEvent::kKEY_TYPE_MAPSWITCH = "startmap";
const std::string PersistEvent::kKEY_TYPE_MULTIPLE = "multiple";
const std::string PersistEvent::kKEY_TYPE_NONE = "none";
const std::string PersistEvent::kKEY_TYPE_NOTIFICATION = "notification";
const std::string PersistEvent::kKEY_TYPE_PROPERTY = "propertymod";
const std::string PersistEvent::kKEY_TYPE_SOUND = "justsound";
const std::string PersistEvent::kKEY_TYPE_TELEPORT = "teleportthing";
const std::string PersistEvent::kKEY_TYPE_TRIGGERIO = "triggerio";
const std::string PersistEvent::kKEY_TYPE_UNLOCKIO = "unlockio";
const std::string PersistEvent::kKEY_TYPE_UNLOCKTHING = "unlockthing";
const std::string PersistEvent::kKEY_TYPE_UNLOCKTILE = "unlocktile";

/**
 * Event type enumerator from string key static map.
 */
const std::map<std::string, EventType> PersistEvent::kTYPE_FROM_STRING = {
  { kKEY_TYPE_BATTLESTART,  EventType::BATTLESTART  },
  { kKEY_TYPE_CONVERSATION, EventType::CONVERSATION },
  { kKEY_TYPE_ITEMGIVE,     EventType::ITEMGIVE     },
  { kKEY_TYPE_ITEMTAKE,     EventType::ITEMTAKE     },
  { kKEY_TYPE_MAPSWITCH,    EventType::MAPSWITCH    },
  { kKEY_TYPE_MULTIPLE,     EventType::MULTIPLE     },
  { kKEY_TYPE_NONE,         EventType::NONE         },
  { kKEY_TYPE_NOTIFICATION, EventType::NOTIFICATION },
  { kKEY_TYPE_PROPERTY,     EventType::PROPERTY     },
  { kKEY_TYPE_SOUND,        EventType::SOUND        },
  { kKEY_TYPE_TELEPORT,     EventType::TELEPORT     },
  { kKEY_TYPE_TRIGGERIO,    EventType::TRIGGERIO    },
  { kKEY_TYPE_UNLOCKIO,     EventType::UNLOCKIO     },
  { kKEY_TYPE_UNLOCKTHING,  EventType::UNLOCKTHING  },
  { kKEY_TYPE_UNLOCKTILE,   EventType::UNLOCKTILE   }
};

/**
 * Event type enumerator to string key static map.
 */
const std::map<EventType, std::string> PersistEvent::kTYPE_TO_STRING = {
  { EventType::BATTLESTART,  kKEY_TYPE_BATTLESTART  },
  { EventType::CONVERSATION, kKEY_TYPE_CONVERSATION },
  { EventType::ITEMGIVE,     kKEY_TYPE_ITEMGIVE     },
  { EventType::ITEMTAKE,     kKEY_TYPE_ITEMTAKE     },
  { EventType::MAPSWITCH,    kKEY_TYPE_MAPSWITCH    },
  { EventType::MULTIPLE,     kKEY_TYPE_MULTIPLE     },
  { EventType::NONE,         kKEY_TYPE_NONE         },
  { EventType::NOTIFICATION, kKEY_TYPE_NOTIFICATION },
  { EventType::PROPERTY,     kKEY_TYPE_PROPERTY     },
  { EventType::SOUND,        kKEY_TYPE_SOUND        },
  { EventType::TELEPORT,     kKEY_TYPE_TELEPORT     },
  { EventType::TRIGGERIO,    kKEY_TYPE_TRIGGERIO    },
  { EventType::UNLOCKIO,     kKEY_TYPE_UNLOCKIO     },
  { EventType::UNLOCKTHING,  kKEY_TYPE_UNLOCKTHING  },
  { EventType::UNLOCKTILE,   kKEY_TYPE_UNLOCKTILE   }
};

/*=============================================================================
 * PRIVATE STATIC FUNCTIONS
 *============================================================================*/

/**
 * Create an empty event object of the given type.
 * @param type event classification
 * @return newly created event object
 */
Event* PersistEvent::createEventFromType(EventType type)
{
  switch(type) {
    case EventType::BATTLESTART:
      return new EventBattleStart();
    case EventType::CONVERSATION:
      return new EventConversation();
    case EventType::ITEMGIVE:
      return new EventItemGive();
    case EventType::ITEMTAKE:
      return new EventItemTake();
    case EventType::MAPSWITCH:
      return new EventMapSwitch();
    case EventType::MULTIPLE:
      return new EventMultiple();
    case EventType::NONE:
      return new EventNone();
    case EventType::NOTIFICATION:
      return new EventNotification();
    case EventType::PROPERTY:
      return new EventProperty();
    case EventType::SOUND:
      return new EventSound();
    case EventType::TELEPORT:
      return new EventTeleport();
    case EventType::TRIGGERIO:
      return new EventTriggerIO();
    case EventType::UNLOCKIO:
      return new EventUnlockIO();
    case EventType::UNLOCKTHING:
      return new EventUnlockThing();
    case EventType::UNLOCKTILE:
      return new EventUnlockTile();
    default:
      throw std::domain_error("Event type mapping for create event is not defined");
  }
}

/*=============================================================================
 * PUBLIC STATIC FUNCTIONS
 *============================================================================*/

/**
 * Loads the individual event data from the XML entry.
 * @param event current event stored locally that either needs to be augmented or thrown away
 * @param data single packet of XML data
 * @param index current index within the line, represents which XML element is currently being read
 * @return augmented event by the load state
 */
Event* PersistEvent::load(Event* event, XmlData data, int index)
{
  std::string element = data.getElement(index);

  auto found_type_pair = kTYPE_FROM_STRING.find(element);
  if(found_type_pair == kTYPE_FROM_STRING.end())
    throw std::domain_error("Event type mapping for load event is not defined");

  EventType type_from_data = found_type_pair->second;

  // Decide if the old event can be used or if a new one need to be created
  Event* event_to_edit;
  if(event->getType() != type_from_data)
    event_to_edit = createEventFromType(type_from_data);
  else
    event_to_edit = event;

  // Call load in the event
  event_to_edit->load(data, index + 1);

  // If a new event was created, delete the old one
  if(event_to_edit != event)
    delete event;

  return event_to_edit;
}

/**
 * Saves the individual event data into the XML writer.
 * @param event persist ready event object
 * @param writer saving file handler interface
 * @param save_if_invalid TRUE to save even if the event is not saveable (subs NONE event in place)
 */
void PersistEvent::save(Event* event, XmlWriter* writer, bool save_if_invalid)
{
  if(event->isSaveable() || save_if_invalid)
  {
    auto found_type_pair = kTYPE_TO_STRING.find(event->getType());
    if(found_type_pair == kTYPE_TO_STRING.end())
      throw std::domain_error("Event type mapping for save event is not defined");

    std::string type_string = found_type_pair->second;
    writer->writeElement(type_string);
    event->save(writer);
    writer->jumpToParent();
  }
}
