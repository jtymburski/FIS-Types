/**
 * @class MapPerson
 *
 * The MapPerson extends the thing to enhance by making a movable object that can exist on
 * multiple surfaces and travel in multiple directions.
 */
#include "Map/MapPerson.h"
using namespace core;

/*=============================================================================
 * CONSTRUCTORS / DESTRUCTORS
 *============================================================================*/

/**
 * Constructor, from an ID.
 * @param id reference ID
 */
MapPerson::MapPerson(uint32_t id) : MapThing(id)
{
}

/*=============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/**
 * Returns the sprite matrix associated to the render key. If this implementation does not define
 * the matrix, it will try and use the base reference object (template model).
 * @param key map person render dimensions
 * @return sprite matrix render information, throws if undefined
 */
SpriteMatrix MapPerson::getMatrix(MapPersonRenderKey key) const
{
  auto matrix = matrix_states.find(key);
  if(matrix != matrix_states.end())
    return matrix->second;
  else if(auto base = getBase().lock())
    return std::static_pointer_cast<MapPerson>(base)->getMatrix(key);
  throw std::domain_error("Sprite matrix for provided key is not defined by the map object");
}

/**
 * Returns the animation speed for person movement. If this implementation does not define
 * the speed, it will try and use the base reference object (template model).
 * @return movement speed, {@link #kDEFAULT_SPEED} if undefined
 */
uint16_t MapPerson::getSpeed() const
{
  if(speed.has_value())
    return speed.value();
  else if(auto base = getBase().lock())
    return std::static_pointer_cast<MapPerson>(base)->getSpeed();
  return kDEFAULT_SPEED;
}

/**
 * Returns the starting direction for rendering the person on map load. If this implementation does
 * not define the direction, it will try and use the base reference object (template model).
 * @return facing direction on load, {@link #kDEFAULT_STARTING_DIRECTION} if undefined
 */
Direction MapPerson::getStartingDirection() const
{
  if(starting_direction.has_value())
    return starting_direction.value();
  else if(auto base = getBase().lock())
    return std::static_pointer_cast<MapPerson>(base)->getStartingDirection();
  return kDEFAULT_STARTING_DIRECTION;
}

/**
 * Returns {@link MapObjectType#PERSON} to define the type classification.
 * @return map object type classification enum
 */
MapObjectType MapPerson::getType() const
{
  return MapObjectType::PERSON;
}

/**
 * Describes if the sprite matrix (@link #getMatrix(MapPersonRenderKey)) has been defined.
 * @param key map person render dimensions
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the matrix for the key has been set, FALSE if not
 */
bool MapPerson::isMatrixSet(MapPersonRenderKey key, bool check_base) const
{
  if(matrix_states.find(key) != matrix_states.end())
    return true;
  else if(auto base = getBase().lock())
    return check_base && std::static_pointer_cast<MapPerson>(base)->isMatrixSet(key);
  return false;
}

/**
 * Describes if the animation speed (@link #getSpeed()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the speed has been set, FALSE if not
 */
bool MapPerson::isSpeedSet(bool check_base) const
{
  if(speed.has_value())
    return true;
  else if(auto base = getBase().lock())
    return check_base && std::static_pointer_cast<MapPerson>(base)->isSpeedSet();
  return false;
}

/**
 * Describes if the starting direction (@link #getStartingDirection()) has been defined.
 * @param check_base TRUE to also check the base object, FALSE to only check the local version
 * @return TRUE if the direction has been set, FALSE if not
 */
bool MapPerson::isStartingDirectionSet(bool check_base) const
{
  if(starting_direction.has_value())
    return true;
  else if(auto base = getBase().lock())
    return check_base && std::static_pointer_cast<MapPerson>(base)->isStartingDirectionSet();
  return false;
}

/**
 * Sets the sprite matrix associated to the render key of the object. See
 * {@link #getMatrix(MapPersonRenderKey)} for more info. This defines only the current
 * implementation state. It does not change the base object.
 * @param key map person render dimensions
 * @param sprite_matrix new sprite info associated to the key
 */
void MapPerson::setMatrix(MapPersonRenderKey key, SpriteMatrix& sprite_matrix)
{
  this->matrix_states.at(key) = sprite_matrix;
}

/**
 * Sets the animation speed for person movement of the object. See {@link #getSpeed()} for more
 * info. This defines only the current implementation state. It does not change the base object.
 * @param speed new movement person speed
 */
void MapPerson::setSpeed(uint16_t speed)
{
  this->speed = speed;
}

/**
 * Sets the starting direction for rendering the person on map load of the object. See
 * {@link #getStartingDirection()} for more info. This defines only the current implementation
 * state. It does not change the base object.
 * @param direction new facing direction on load
 */
void MapPerson::setStartingDirection(Direction direction)
{
  this->starting_direction = direction;
}

/**
 * Unsets the implementation (local) sprite matrix associated to the render key. After
 * unset, this will fallback to the base object instead to fetch the matrix, if its defined.
 * @param key map person render dimensions
 */
void MapPerson::unsetMatrix(MapPersonRenderKey key)
{
  matrix_states.erase(key);
}

/**
 * Unsets the implementation (local) animation speed for person movement. After unset, this will
 * fallback to the base object instead to fetch the speed, if its defined.
 */
void MapPerson::unsetSpeed()
{
  speed.reset();
}

/**
 * Unsets the implementation (local) starting direction for rendering the person on map load. After
 * unset, this will fallback to the base object instead to fetch the direction, if its defined.
 */
void MapPerson::unsetStartingDirection()
{
  starting_direction.reset();
}
