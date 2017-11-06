#ifndef COORDPAIR_H
#define COORDPAIR_H

//------------------------------------------------------------------------------
// Using the direction class
//
class Direction;

//------------------------------------------------------------------------------
// Used to put x and y in one structure.
//
class CoordPair
{
private:

  //----------------------------------------------------------------------------
  // X coordinate.
  //
  int x_;

  //----------------------------------------------------------------------------
  // Y coordinate.
  //
  int y_;

public:

  //----------------------------------------------------------------------------
  // Default constructor - Creates a pair at (0/0).
  //
  CoordPair();

  //----------------------------------------------------------------------------
  // Creates a new instance.
  // @param x X coordinate.
  // @param y Y coordinate.
  //
  CoordPair(int x, int y);

  //----------------------------------------------------------------------------
  // Copy constructor.
  // @param pair The original instance
  //
  CoordPair(const CoordPair& original);

  //----------------------------------------------------------------------------
  // Tests if both coordinates are equal to another pair.
  // @param pair The other pair.
  //
  const bool operator==(const CoordPair& pair);

  //----------------------------------------------------------------------------
  // Tests if this coordinate pair is different to another in some way.
  // @param pair The other pair.
  //
  const bool operator!=(const CoordPair& pair);

  //----------------------------------------------------------------------------
  // Tests if this coordinate pair smaller than the given one.
  // @param pair The other pair.
  //
  const bool operator<(const CoordPair& pair);

  //----------------------------------------------------------------------------
  // Returns the X coordinate.
  // @return A whole number.
  //
  int getX();

  //----------------------------------------------------------------------------
  // Returns the Y coordinate.
  // @return A whole number.
  //
  int getY();

  //----------------------------------------------------------------------------
  // Adds an offset to this pair.
  // @param x X offset.
  // @param y Y offset.
  //
  void add(int x, int y);

  //----------------------------------------------------------------------------
  // Adds an offset of 1 pointing to a specific direction to this pair.
  // @param direction The direction to be added.
  //
  void addDirection(Direction* direction);
};

#endif
