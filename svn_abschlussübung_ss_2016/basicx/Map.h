#ifndef MAP_H
#define MAP_H

//------------------------------------------------------------------------------
// Using field class.
//
class Field;

//------------------------------------------------------------------------------
// Using coordpair class.
//
class CoordPair;

//------------------------------------------------------------------------------
// Holds the structural information of a level.
//
class Map
{
private:

  //----------------------------------------------------------------------------
  // A one dimensional array containing the fields of the map.
  //
  Field** fields_;

  //----------------------------------------------------------------------------
  // Stores the width of the map.
  //
  int size_x_;

  //----------------------------------------------------------------------------
  // Stores the height of the map.
  //
  int size_y_;

  //----------------------------------------------------------------------------
  // Stores the area of the map.
  //
  int area_;

  //----------------------------------------------------------------------------
  // Default constructor - Should not be used.
  //
  Map() = delete;

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  //
  Map(Map &);

  //----------------------------------------------------------------------------
  // Checks if the given coord pair is within the boundaries of this map.
  // @param pair The coordinates to check.
  // @return If it's within the boundaries.
  //
  bool isWithinBounds(CoordPair pair);

  //----------------------------------------------------------------------------
  // Checks if all fields on the border are walls.
  // @returns Whether the map is surrounded by walls.
  //
  bool checkWall();

public:

  //----------------------------------------------------------------------------
  // Creates a new instance.
  // @param fields The structural information of this map.
  // @param sizeX The width of the map.
  // @param sizeY The height of the map.
  //
  Map(Field** fields, int sizeX, int sizeY);

  //----------------------------------------------------------------------------
  // Checks if the map has one finish field, one start field, zero or two
  // teleporters of each kind and if it's surrounded by walls.
  // @returns If the map is valid.
  //
  bool validate();

  //----------------------------------------------------------------------------
  // Returns the field at the given coordinates.
  // @return A field. Returns nullptr if the coordinates are outside the map's
  //         boundaries.
  Field* getFieldAt(CoordPair pair);

  //----------------------------------------------------------------------------
  // Finds and returns the position where the given field is located.
  // @param field The field to search for.
  // @returns A coord pair.
  //
  const CoordPair getFieldPosition(Field* field);

  //----------------------------------------------------------------------------
  // Finds and returns the position where the starting field is located.
  // @returns A coord pair.
  //
  const CoordPair getStartingPosition();

  //----------------------------------------------------------------------------
  // Returns the width of the map.
  // @return A positive number.
  //
  int getSizeX();

  //----------------------------------------------------------------------------
  // Returns the height of the map.
  // @return A positive number.
  //
  int getSizeY();

  //----------------------------------------------------------------------------
  // Calculates the area of the map.
  // @return width * height.
  //
  int getArea();

  //----------------------------------------------------------------------------
  // Returns the position of the portal on the other side.
  // @position The position of the entrance.
  // @return The position of the exit.
  //
  CoordPair getPortalEnd(CoordPair position);

  //----------------------------------------------------------------------------
  // Converts a coordinate pair to a one dimensional number.
  // @param The coordinate pair.
  // @return The index in the fields-array.
  //
  inline int encodeCoords(CoordPair pair);

  //----------------------------------------------------------------------------
  // Deletes this instance.
  //
  ~Map();
};

#endif
