#include "CoordPair.h"
#include "Field.h"
#include "Map.h"

class Field;
class Map;

//------------------------------------------------------------------------------
Map::Map(Field** fields, int size_x, int size_y) :
  fields_(fields), size_x_(size_x), size_y_(size_y), area_(size_x * size_y)
{
}

//------------------------------------------------------------------------------
int Map::encodeCoords(CoordPair pair)
{
  return pair.getX() + pair.getY() * size_x_;
}

//------------------------------------------------------------------------------
Field* Map::getFieldAt(CoordPair pair)
{
  return isWithinBounds(pair) ? fields_[encodeCoords(pair)] : Field::START;
}

//------------------------------------------------------------------------------
const CoordPair Map::getStartingPosition()
{
  return getFieldPosition(Field::START);
}

//------------------------------------------------------------------------------
const CoordPair Map::getFieldPosition(Field* field)
{
  for (int y = 0; y < size_y_; y++)
  {
    for (int x = 0; x < size_x_; x++)
    {
      CoordPair pair(x, y);
      if (getFieldAt(pair) == field)
      {
        return CoordPair(pair);
      }
    }
  }
  // Should never be reached.
  return CoordPair();
}

//------------------------------------------------------------------------------
CoordPair Map::getPortalEnd(CoordPair position)
{
  Field* field = getFieldAt(position);
  for (int y = 0; y < size_y_; y++)
  {
    for (int x = 0; x < size_x_; x++)
    {
      CoordPair pair(x, y);
      if (pair != position && getFieldAt(pair) == field)
      {
        return pair;
      }
    }
  }
  return CoordPair();
}

//------------------------------------------------------------------------------
int Map::getSizeX()
{
  return size_x_;
}

//------------------------------------------------------------------------------
int Map::getSizeY()
{
  return size_y_;
}

//------------------------------------------------------------------------------
int Map::getArea()
{
  return area_;
}

//------------------------------------------------------------------------------
Map::~Map()
{
  delete fields_;
}

//------------------------------------------------------------------------------
bool Map::isWithinBounds(CoordPair pair)
{
  return pair.getX() >= 0 && pair.getY() >= 0 &&
    pair.getX() < size_x_ && pair.getY() < size_y_;
}

//------------------------------------------------------------------------------
bool Map::validate()
{
  int start_count = 0;
  int finish_count = 0;
  if (!checkWall())
  {
    return false;
  }
  int teleporter_count[Field::NUMBER_OF_TELEPORTER_TYPES];
  for (int index = 0; index < Field::NUMBER_OF_TELEPORTER_TYPES; index++)
  {
    teleporter_count[index] = 0;
  }
  for (int index = size_x_ * size_y_ - 1; index >= 0; index--)
  {
    Field* field = fields_[index];
    if (field == nullptr)
    {
      return false;
    }
    else if (field == Field::START)
    {
      start_count++;
    }
    else if (field == Field::FINISH)
    {
      finish_count++;
    }
    else
    {
      char symbol = field->getSymbol();
      if (symbol >= 'A' && symbol <= 'Z')
      {
        teleporter_count[symbol - 'A']++;
      }
    }
  }
  bool teleporters_valid = true;
  for (int index = 0; index < Field::NUMBER_OF_TELEPORTER_TYPES; index++)
  {
    int count = teleporter_count[index];
    if (count != 0 && count != 2)
    {
      teleporters_valid = false;
      break;
    }
  }
  return start_count == 1 && finish_count == 1 && teleporters_valid;
}

//------------------------------------------------------------------------------
bool Map::checkWall()
{
  for (int x = 0; x < size_x_; x++)
  {
    CoordPair top(x, 0);
    CoordPair bottom(x, size_y_ - 1);
    if (fields_[encodeCoords(top)] != Field::WALL
      || fields_[encodeCoords(bottom)] != Field::WALL)
    {
      return false;
    }
  }

  for (int y = 1; y < size_y_ - 1; y++)
  {
    CoordPair left(0, y);
    CoordPair right(size_x_ - 1, y);
    if (fields_[encodeCoords(left)] != Field::WALL
      || fields_[encodeCoords(right)] != Field::WALL)
    {
      return false;
    }
  }
  return true;
}
