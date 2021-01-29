/**
 * @class MapPerson
 *
 * The MapPerson extends the thing to enhance by making a movable object that can exist on
 * multiple surfaces and travel in multiple directions.
 */
#ifndef CORE_MAPPERSON_H
#define CORE_MAPPERSON_H

#include <cstdint>
#include <optional>
#include <unordered_map>

#include "Foundation/Direction.h"
#include "Foundation/SpriteMatrix.h"
#include "Map/MapPersonRenderKey.h"
#include "Map/MapThing.h"

namespace core
{
  class MapPerson : public MapThing
  {
  public:
    /* Constructor, from an ID */
    MapPerson(uint32_t id);

  private:
    /* All render states for the person, depending on the render key identifier */
    std::unordered_map<MapPersonRenderKey, SpriteMatrix> matrix_states;

    /* Animation speed for person movement (baseline is 8 which is 2 tiles per second) */
    std::optional<uint16_t> speed;

    /* The starting direction, that the person will render when the map initially loads */
    std::optional<Direction> starting_direction;

    /*------------------- Constants -----------------------*/
  private:
    /* Default object states */
    const static uint16_t kDEFAULT_SPEED = 8;
    const static Direction kDEFAULT_STARTING_DIRECTION = Direction::NORTH;

  /*=============================================================================
   * PUBLIC FUNCTIONS
   *============================================================================*/
  public:
    /* Returns the sprite matrix associated to the render key */
    SpriteMatrix getMatrix(MapPersonRenderKey key) const;

    /* Returns the animation speed for person movement */
    uint16_t getSpeed() const;

    /* Returns the starting direction for rendering the person on map load */
    Direction getStartingDirection() const;

    /* Returns the map object type classification of the implementation */
    virtual MapObjectType getType() const override;

    /* Returns if the sprite matrix associated to the render key is set */
    bool isMatrixSet(MapPersonRenderKey key, bool check_base = true) const;

    /* Returns if the animation speed for person movement is set */
    bool isSpeedSet(bool check_base = true) const;

    /* Returns if the starting direction for rendering the person on map load is set */
    bool isStartingDirectionSet(bool check_base = true) const;

    /* Sets the implementation (local) sprite matrix associated to the render key */
    void setMatrix(MapPersonRenderKey key, SpriteMatrix& sprite_matrix);

    /* Sets the implementation (local) animation speed for person movement */
    void setSpeed(uint16_t speed);

    /* Sets the implementation (local) starting direction for rendering the person on map load */
    void setStartingDirection(Direction direction);

    /* Unsets the implementation (local) sprite matrix associated to the render key */
    void unsetMatrix(MapPersonRenderKey key);

    /* Unsets the implementation (local) animation speed for person movement */
    void unsetSpeed();

    /* Unsets the implementation (local) starting direction for rendering the person on map load */
    void unsetStartingDirection();
  };
};

#endif // CORE_MAPPERSON_H
