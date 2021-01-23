/**
 * @class MapThing
 *
 * The MapThing is the generic on-map object that need additional state definition, beyond normal
 * tiles or on-screen images. It includes in-sync animation across the full matrix along with
 * passability, events, etc. It also acts as the parent class to a host of other specific use
 * cases, like Items, Persons, NPCs.
 */
#ifndef CORE_MAPTHING_H
#define CORE_MAPTHING_H

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

#include "Event/Event.h"
#include "Foundation/Frame.h"
#include "Foundation/SpriteMatrix.h"
#include "Map/MapObjectType.h"

namespace core
{
  class MapThing
  {
  public:
    /* Constructor, from an ID */
    MapThing(uint32_t id);

  private:
    /* Is the thing active? Defines if the object is even rendered or updated in game at all */
    std::optional<bool> active;

    /* Base thing reference which is used as the default configuration but can be overriden */
    std::weak_ptr<MapThing> base_thing;

    /* Single line description for the map object */
    std::optional<std::string> description;

    /* Render-ready image info for the dialog snapshot of the object */
    std::optional<Frame> dialog_image;

    /* Object general event, triggered during interaction by the player */
    std::unique_ptr<Event> event;

    /* Game level reference ID. This represents the game wide class, like Thing or Player */
    std::optional<uint32_t> game_id;

    /* Object unique identifier */
    uint32_t id;

    /* Name for the map object */
    std::optional<std::string> name;

    /* Time before respawning the object after becoming inactive */
    std::optional<uint16_t> respawn_time_ms;

    /* Associated sound identifier, tied to the map object */
    std::optional<uint32_t> sound_id;

    /* Map sprite matrix, with passability, defining the render component of the object */
    std::optional<SpriteMatrix> sprite_matrix;

    /* Tile grid X (horizontal) location, in the current map section */
    std::optional<uint16_t> tile_horizontal;

    /* Tile grid Y (vertical) location, in the current map section */
    std::optional<uint16_t> tile_vertical;

    /* Is the thing visible? Defines if the object will be rendered and visible on map */
    std::optional<bool> visible;

    /*------------------- Constants -----------------------*/
  private:
    /* Default object states */
    const static bool kDEFAULT_ACTIVE = true;
    const static bool kDEFAULT_VISIBLE = true;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the base thing reference for defining the underlying reference definition */
    std::weak_ptr<MapThing> getBase() const;

    /* Returns the single line description for the map object */
    std::string getDescription() const;

    /* Returns the render-ready image info for the dialog snapshot of the object */
    const Frame& getDialogImage() const;

    /* Returns the associated object event, triggered during interaction by the player */
    const Event& getEvent() const;

    /* Returns the game level reference ID, representing the game-wide class (e.g. Thing) */
    uint32_t getGameId() const;

    /* Returns the object unique identifier */
    uint32_t getId() const;

    /* Returns the name for the map object */
    std::string getName() const;

    /* Returns the time before respawning the object after becoming inactive */
    uint16_t getRespawnTimeMilliseconds() const;

    /* Returns the associated sound identifier, tied to the map object */
    uint32_t getSoundId() const;

    /* Returns the map sprite matrix defining the render component of the object */
    const SpriteMatrix& getSpriteMatrix() const;

    /* Returns the tile grid X (horizontal) location, in the current map section */
    uint16_t getTileHorizontal() const;

    /* Returns the tile grid Y (vertical) location, in the current map section */
    uint16_t getTileVertical() const;

    /* Returns the map object type classification of the implementation */
    MapObjectType getType() const;

    /* Returns if the starting map thing is active */
    bool isActive() const;
    bool isActiveSet(bool check_base = true) const;

    /* Returns if the base thing reference is set */
    bool isBaseSet() const;

    /* Return if the single line description for the map object is set */
    bool isDescriptionSet(bool check_base = true) const;

    /* Returns if the render-ready image info for the dialog snapshot of the object is set */
    bool isDialogImageSet(bool check_base = true) const;

    /* Returns if the the associated object event is set */
    bool isEventSet(bool check_base = true) const;

    /* Returns if the game level reference ID, representing the game-wide class is set */
    bool isGameIdSet(bool check_base = true) const;

    /* Returns if the name for the map object is set */
    bool isNameSet(bool check_base = true) const;

    /* Returns if the time before respawning the object after becoming inactive is set */
    bool isRespawnTimeSet(bool check_base = true) const;

    /* Returns if the associated sound identifier, tied to the map object is set */
    bool isSoundIdSet(bool check_base = true) const;

    /* Returns if the map sprite matrix defining the render component of the object is set */
    bool isSpriteMatrixSet(bool check_base = true) const;

    /* Returns if the tile grid X (horizontal) location, in the current map section is set */
    bool isTileHorizontalSet(bool check_base = true) const;

    /* Returns if the tile grid Y (vertical) location, in the current map section is set */
    bool isTileVerticalSet(bool check_base = true) const;

    /* Returns if the map object is visible and rendered on-screen */
    bool isVisible() const;
    bool isVisibleSet(bool check_base = true) const;

    /* Sets if the starting map thing is active */
    void setActive(bool active);

    /* Sets the base thing. This becomes the fallback object for any undefined properties */
    void setBase(std::weak_ptr<MapThing> base_thing);

    /* Sets the single line description for the map object */
    void setDescription(std::string description);

    /* Sets the render-ready image info for the dialog snapshot of the object */
    void setDialogImage(Frame& dialog_image);

    /* Sets the associated object event, triggered during interaction by the player */
    void setEvent(std::unique_ptr<Event> event);

    /* Sets the game level reference ID, representing the game-wide class (e.g. Thing) */
    void setGameId(uint32_t game_id);

    /* Sets the object unique identifier */
    void setId(uint32_t id);

    /* Sets the name for the map object */
    void setName(std::string name);

    /* Sets the time before respawning the object after becoming inactive */
    void setRespawnTimeMilliseconds(uint16_t respawn_time_ms);

    /* Sets the associated sound identifier, tied to the map object */
    void setSoundId(uint32_t sound_id);

    /* Sets the map sprite matrix defining the render component of the object */
    void setSpriteMatrix(SpriteMatrix& sprite_matrix);

    /* Sets the tile grid X (horizontal) location, in the current map section */
    void setTileHorizontal(uint16_t tile_horizontal);

    /* Sets the tile grid Y (vertical) location, in the current map section */
    void setTileVertical(uint16_t tile_vertical);

    /* Sets if the map object is visible and rendered on-screen */
    void setVisible(bool visible);

    /* Unsets if the starting map thing is active. Fallback to either base or default */
    void unsetActive();

    /* Unsets the base thing. Once removed, only data from this instance will define the object */
    void unsetBase();

    /* Unsets the implementation single line description for the map object */
    void unsetDescription();

    /* Unsets the implementation render-ready image info for the dialog snapshot of the object */
    void unsetDialogImage();

    /* Unsets the associated object event, triggered during interaction by the player */
    void unsetEvent();

    /* Unsets the implementation game level reference ID, representing the game-wide class */
    void unsetGameId();

    /* Unsets the implementation name for the map object */
    void unsetName();

    /* Unsets the implementation time before respawning the object after becoming inactive */
    void unsetRespawnTime();

    /* Unsets the implementation associated sound identifier, tied to the map object */
    void unsetSoundId();

    /* Unsets the map sprite matrix defining the render component of the object */
    void unsetSpriteMatrix();

    /* Unsets the implementation tile grid X (horizontal) location, in the current map section */
    void unsetTileHorizontal();

    /* Unsets the implementation tile grid Y (vertical) location, in the current map section */
    void unsetTileVertical();

    /* Unsets if the map object is visible and rendered on-screen */
    void unsetVisible();
  };
};

#endif // CORE_MAPTHING_H
