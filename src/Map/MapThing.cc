/**
 * @class MapThing
 *
 * The MapThing is the generic on-map object that need additional state definition, beyond normal
 * tiles or on-screen images. It includes in-sync animation across the full matrix along with
 * passability, events, etc. It also acts as the parent class to a host of other specific use
 * cases, like Items, Persons, NPCs.
 */
#include "Map/MapThing.h"
using namespace core;

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Constructor, from an ID.
 * @param id reference ID
 */
MapThing::MapThing(uint32_t id)
{
  setId(id);
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the base thing reference for defining the underlying reference definition. This may
 * be unset or already expired, in which case only the current object class variables will be used.
 * @return weak reference to the base thing. Can be unset
 */
std::weak_ptr<MapThing> MapThing::getBase() const
{
  return base_thing;
}

/**
 * Returns the single line description for the map object. If this implementation does not define
 * the state, it will try and use the base reference object (template model).
 * @return map object description, generally single line
 */
std::string MapThing::getDescription() const
{
  if(description.has_value())
    return description.value();
  else if(auto base = base_thing.lock())
    return base->getDescription();
  return std::string();
}

/**
 * Returns the render-ready image info for the dialog snapshot of the object. If this implementation
 * does not define the state, it will try and use the base reference object (template model).
 * @return dialog image
 */
const Frame& MapThing::getDialogImage() const
{
  if(dialog_image.has_value())
    return dialog_image.value();
  else if(auto base = base_thing.lock())
    return base->getDialogImage();
  throw std::domain_error("Dialog image is not defined by the map object");
}

/**
 * Returns the associated object event, triggered during interaction by the player. If this
 * implementation does not define the state, it will try and use the base reference object
 * (template model).
 * @return event reference
 */
const Event& MapThing::getEvent() const
{
  if(event)
    return *event;
  else if(auto base = base_thing.lock())
    return base->getEvent();
  throw std::domain_error("Event is not defined by the map object");
}

/**
 * Returns the game level reference ID, representing the game-wide class (e.g. Thing). If this
 * implementation does not define the state, it will try and use the base reference object
 * (template model).
 * @return game object identifier, used by the game engine
 */
uint32_t MapThing::getGameId() const
{
  if(game_id.has_value())
    return game_id.value();
  else if(auto base = base_thing.lock())
    return base->getGameId();
  throw std::domain_error("Game ID is not defined by the map object");
}

/**
 * Returns the object unique identifier. This uniquely describes this object, either in the game
 * level template state or the individual map state.
 * @return map unique ID
 */
uint32_t MapThing::getId() const
{
  return id;
}

/**
 * Returns the name for the map object. If this implementation does not define the state, it will
 * try and use the base reference object (template model).
 * @return map object name
 */
std::string MapThing::getName() const
{
  if(name.has_value())
    return name.value();
  else if(auto base = base_thing.lock())
    return base->getName();
  return std::string();
}

/**
 * Returns the time before respawning the object after becoming inactive. If this implementation
 * does not define the state, it will try and use the base reference object (template model).
 * @return respawn time, moving from inactive to active, in milliseconds
 */
uint16_t MapThing::getRespawnTimeMilliseconds() const
{
  if(respawn_time_ms.has_value())
    return respawn_time_ms.value();
  else if(auto base = base_thing.lock())
    return base->getRespawnTimeMilliseconds();
  throw std::domain_error("Respawn time is not defined by the map object");
}

/**
 * Returns the associated sound identifier, tied to the map object. If this implementation
 * does not define the state, it will try and use the base reference object (template model).
 * @return sound identifier, referencing the top level game assets
 */
uint32_t MapThing::getSoundId() const
{
  if(sound_id.has_value())
    return sound_id.value();
  else if(auto base = base_thing.lock())
    return base->getSoundId();
  throw std::domain_error("Sound ID is not defined by the map object");
}

/**
 * Returns the map sprite matrix defining the render component of the object. If this implementation
 * does not define the state, it will try and use the base reference object (template model).
 * @return sprite matrix, defining the full set of sprites and passability
 */
const SpriteMatrix& MapThing::getSpriteMatrix() const
{
  if(sprite_matrix.has_value())
    return sprite_matrix.value();
  else if(auto base = base_thing.lock())
    return base->getSpriteMatrix();
  throw std::domain_error("Sprite matrix is not defined by the map object");
}

/**
 * Returns the tile grid X (horizontal) location, in the current map section. If this implementation
 * does not define the state, it will try and use the base reference object (template model).
 * @return tile horizontal location (X). Only relevant for map level objects
 */
uint16_t MapThing::getTileHorizontal() const
{
  if(tile_horizontal.has_value())
    return tile_horizontal.value();
  else if(auto base = base_thing.lock())
    return base->getTileHorizontal();
  throw std::domain_error("Tile horizontal (X) is not defined by the map object");
}

/**
 * Returns the tile grid Y (vertical) location, in the current map section. If this implementation
 * does not define the state, it will try and use the base reference object (template model).
 * @return tile vertical location (Y). Only relevant for map level objects
 */
uint16_t MapThing::getTileVertical() const
{
  if(tile_vertical.has_value())
    return tile_vertical.value();
  else if(auto base = base_thing.lock())
    return base->getTileVertical();
  throw std::domain_error("Tile vertical (Y) is not defined by the map object");
}

/**
 * Returns {@link MapObjectType#THING} to define the type classification.
 * @return map object type classification enum
 */
MapObjectType MapThing::getType() const
{
  return MapObjectType::THING;
}

/**
 * Returns if the map object is even rendered or updated in game at all. Inactive objects are
 * not processed at all by the game engine. If this implementation does not define the state,
 * it will try and use the base reference object (template model).
 * @return TRUE if the object is active. FALSE if inactive
 */
bool MapThing::isActive() const
{
  if(active.has_value())
    return active.value();
  else if(auto base = base_thing.lock())
    return base->isActive();
  return kDEFAULT_ACTIVE;
}

/**
 * Describes if the active state (@link #isActive()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the active state has been set, FALSE if not
 */
bool MapThing::isActiveSet(bool check_base) const
{
  if(active.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isActiveSet();
  return false;
}

/**
 * Describes if a base thing reference has been defined (a template object).
 * @return TRUE if the base has been set, FALSE if not
 */
bool MapThing::isBaseSet() const
{
  return !base_thing.expired();
}

/**
 * Describes if the description (@link #getDescription()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the description has been set, FALSE if not
 */
bool MapThing::isDescriptionSet(bool check_base) const
{
  if(description.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isDescriptionSet();
  return false;
}

/**
 * Describes if the dialog image (@link #getDialogImage()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the dialog image has been set, FALSE if not
 */
bool MapThing::isDialogImageSet(bool check_base) const
{
  if(dialog_image.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isDialogImageSet();
  return false;
}

/**
 * Describes if the associated object event (@link #getEvent()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the event has been set, FALSE if not
 */
bool MapThing::isEventSet(bool check_base) const
{
  if(event)
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isEventSet();
  return false;
}

/**
 * Describes if the game ID (@link #getGameId()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the game ID has been set, FALSE if not
 */
bool MapThing::isGameIdSet(bool check_base) const
{
  if(game_id.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isGameIdSet();
  return false;
}

/**
 * Describes if the name (@link #getName()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the name has been set, FALSE if not
 */
bool MapThing::isNameSet(bool check_base) const
{
  if(name.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isNameSet();
  return false;
}

/**
 * Describes if the respawn time (@link #getRespawnTimeMilliseconds()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the respawn time has been set, FALSE if not
 */
bool MapThing::isRespawnTimeSet(bool check_base) const
{
  if(respawn_time_ms.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isRespawnTimeSet();
  return false;
}

/**
 * Describes if the sound ID (@link #getSoundId()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the sound ID has been set, FALSE if not
 */
bool MapThing::isSoundIdSet(bool check_base) const
{
  if(sound_id.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isSoundIdSet();
  return false;
}

/**
 * Describes if the sprite matrix (@link #getSpriteMatrix()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the sprite matrix has been set, FALSE if not
 */
bool MapThing::isSpriteMatrixSet(bool check_base) const
{
  if(sprite_matrix.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isSpriteMatrixSet();
  return false;
}

/**
 * Describes if the tile grid horizontal (@link #getTileHorizontal()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the tile grid horizontal has been set, FALSE if not
 */
bool MapThing::isTileHorizontalSet(bool check_base) const
{
  if(tile_horizontal.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isTileHorizontalSet();
  return false;
}

/**
 * Describes if the tile grid vertical (@link #getTileVertical()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the tile grid vertical has been set, FALSE if not
 */
bool MapThing::isTileVerticalSet(bool check_base) const
{
  if(tile_vertical.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isTileVerticalSet();
  return false;
}

/**
 * Returns if the map object is visible and be rendered on the map. Invisible objects are not shown
 * but still have valid passability. If this implementation does not define the state, it will try
 * and use the base reference object (template model).
 * @return TRUE if the object is visible. FALSE if invisible
 */
bool MapThing::isVisible() const
{
  if(visible.has_value())
    return visible.value();
  else if(auto base = base_thing.lock())
    return base->isVisible();
  return kDEFAULT_VISIBLE;
}

/**
 * Describes if the visible state (@link #isVisible()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the visible state has been set, FALSE if not
 */
bool MapThing::isVisibleSet(bool check_base) const
{
  if(visible.has_value())
    return true;
  else if(auto base = base_thing.lock())
    return check_base && base->isVisibleSet();
  return false;
}

/**
 * Sets if the map object will be rendered or update in the game. See {@link #isActive()} for more
 * info. This defines only the current implementation state. It does not change the base object.
 * @param active TRUE if the object should be active. FALSE if it should be inactive
 */
void MapThing::setActive(bool active)
{
  this->active = active;
}

/**
 * Sets the base thing reference for defining the template, underlying reference definition. This
 * may be unset or already expired, in which case only the current object class variables will be
 * used.
 * @param base_thing the new base object to become the inherited parent
 */
void MapThing::setBase(std::weak_ptr<MapThing> base_thing)
{
  if(auto base = base_thing.lock())
  {
    if(base->getType() == getType())
      this->base_thing = base_thing;
    else
      throw std::domain_error("Base thing set does not match the type of the thing object");
  }
  else
  {
    unsetBase();
  }
}

/**
 * Sets the single line description for the map object. See {@link #getDescription()} for more
 * info. This defines only the current implementation state. It does not change the base object.
 * @param description in-game object description
 */
void MapThing::setDescription(std::string description)
{
  this->description = description;
}

/**
 * Sets the render-ready image info for the dialog snapshot of the object. See
 * {@link #getDialogImage()} for more info. This defines only the current implementation state.
 * It does not change the base object.
 * @param dialog_image dialog frame, render-ready image
 */
void MapThing::setDialogImage(Frame& dialog_image)
{
  this->dialog_image = dialog_image;
}

/**
 * Sets the associated object event, triggered during interaction by the player. See
 * {@link #getEvent()} for more info. This defines only the current implementation state.
 * It does not change the base object.
 * @param event unique pointer reference of the event
 */
void MapThing::setEvent(std::unique_ptr<Event> event)
{
  this->event = std::move(event);
}

/**
 * Sets the game level reference ID, representing the game-wide class (e.g. Thing). See
 * {@link #getGameId()} for more info. This defines only the current implementation state.
 * It does not change the base object.
 * @param game_id game reference ID
 */
void MapThing::setGameId(uint32_t game_id)
{
  this->game_id = game_id;
}

/**
 * Sets the object unique identifier. See {@link #getId()} for more info.
 * @param id reference ID
 */
void MapThing::setId(uint32_t id)
{
  this->id = id;
}

/**
 * Sets the name for the map object. See {@link #getName()} for more info. This defines only the
 * current implementation state. It does not change the base object.
 * @param name in-game object name
 */
void MapThing::setName(std::string name)
{
  this->name = name;
}

/**
 * Sets the time before respawning the object after becoming inactive. See
 * {@link #getRespawnTimeMilliseconds()} for more info. This defines only the current implementation
 * state. It does not change the base object.
 * @param respawn_time_ms time, in milliseconds, until the state chnages from inactive to active
 */
void MapThing::setRespawnTimeMilliseconds(uint16_t respawn_time_ms)
{
  this->respawn_time_ms = respawn_time_ms;
}

/**
 * Sets the associated sound identifier, tied to the map object. See {@link #getSoundId()} for
 * more info. This defines only the current implementation state. It does not change the base
 * object.
 * @param sound_id sound reference ID, top level asset
 */
void MapThing::setSoundId(uint32_t sound_id)
{
  this->sound_id = sound_id;
}

/**
 * Sets the map sprite matrix defining the render component of the object. See
 * {@link #getSpriteMatrix()} for more info. This defines only the current implementation state.
 * It does not change the base object.
 * @param sprite_matrix visual, render-supported, asset matrix
 */
void MapThing::setSpriteMatrix(SpriteMatrix& sprite_matrix)
{
  this->sprite_matrix = sprite_matrix;
}

/**
 * Sets the tile grid X (horizontal) location, in the current map section. See
 * {@link #getTileHorizontal()} for more info. This defines only the current implementation state.
 * It does not change the base object.
 * @param tile_horizontal horizontal location, for map implementation of thing
 */
void MapThing::setTileHorizontal(uint16_t tile_horizontal)
{
  this->tile_horizontal = tile_horizontal;
}

/**
 * Sets the tile grid Y (vertical) location, in the current map section. See
 * {@link #getTileVertical()} for more info. This defines only the current implementation state.
 * It does not change the base object.
 * @param tile_vertical vertical location, for map implementation of thing
 */
void MapThing::setTileVertical(uint16_t tile_vertical)
{
  this->tile_vertical = tile_vertical;
}

/**
 * Sets if the map object is visible and rendered on-screen. See {@link #isVisible()} for more
 * info. This defines only the current implementation state. It does not change the base object.
 * @param visible TRUE if the object should be visible on-screen. FALSE if it should be invisible
 */
void MapThing::setVisible(bool visible)
{
  this->visible = visible;
}

/**
 * Unsets (back to default) if the map object will be rendered or updated in the game. This falls
 * back to {@link #kDEFAULT_ACTIVE}, unless the base map object is defined.
 */
void MapThing::unsetActive()
{
  active.reset();
}

/**
 * Unsets (back to default) the map base object. This returns to only the current class
 * implementation to define each class variable.
 */
void MapThing::unsetBase()
{
  base_thing.reset();
}

/**
 * Unsets the implementation single line description for the map object. This falls
 * back to the base map object, if defined.
 */
void MapThing::unsetDescription()
{
  description.reset();
}

/**
 * Unsets the implementation render-ready image info for the dialog snapshot of the object. This
 * falls back to the base map object, if defined.
 */
void MapThing::unsetDialogImage()
{
  dialog_image.reset();
}

/**
 * Unsets the associated object event, triggered during interaction by the player. This
 * falls back to the base map object, if defined.
 */
void MapThing::unsetEvent()
{
  event.reset();
}

/**
 * Unsets the implementation game level reference ID, representing the game-wide class. This
 * falls back to the base map object, if defined.
 */
void MapThing::unsetGameId()
{
  game_id.reset();
}

/**
 * Unsets the implementation name for the map object. This falls back to the base map object,
 * if defined.
 */
void MapThing::unsetName()
{
  name.reset();
}

/**
 * Unsets the implementation time before respawning the object after becoming inactive. This falls
 * back to the base map object, if defined.
 */
void MapThing::unsetRespawnTime()
{
  respawn_time_ms.reset();
}

/**
 * Unsets the implementation associated sound identifier, tied to the map object. This falls
 * back to the base map object, if defined.
 */
void MapThing::unsetSoundId()
{
  sound_id.reset();
}

/**
 * Unsets the map sprite matrix defining the render component of the object. This falls back to
 * the base map object, if defined.
 */
void MapThing::unsetSpriteMatrix()
{
  sprite_matrix.reset();
}

/**
 * Unsets the implementation tile grid X (horizontal) location, in the current map section. This
 * falls back to the base map object, if defined.
 */
void MapThing::unsetTileHorizontal()
{
  tile_horizontal.reset();
}

/**
 * Unsets the implementation tile grid Y (vertical) location, in the current map section. This
 * falls back to the base map object, if defined.
 */
void MapThing::unsetTileVertical()
{
  tile_vertical.reset();
}

/**
 * Unsets if the map object is visible and rendered on-screen. This falls back to the base map
 * object, if defined.
 */
void MapThing::unsetVisible()
{
  visible.reset();
}
