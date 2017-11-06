#include "CoordPair.h"
#include "Map.h"
#include "VisitsMap.h"

//------------------------------------------------------------------------------
VisitsMap::VisitsMap(Map* map) :
  visits_(new long[map->getArea()]), size_x_(map->getSizeX()),
  size_y_(map->getSizeY()), area_(map->getArea())
{
  for(int index = map->getArea() - 1; index >= 0; index--)
  {
    visits_[index] = 0;
  }
}

//------------------------------------------------------------------------------
VisitsMap::VisitsMap(const VisitsMap& map) :
  visits_(new long[map.area_]), size_x_(map.size_x_), size_y_(map.size_y_), area_(map.area_)
{
  for(int index = map.area_ - 1; index >= 0; index--)
  {
    visits_[index] = map.visits_[index];
  }
}

//------------------------------------------------------------------------------
int VisitsMap::encodeCoords(CoordPair pair)
{
  return pair.getX() + pair.getY() * size_x_;
}

//------------------------------------------------------------------------------
long VisitsMap::getVisitsAt(CoordPair pair)
{
  return isWithinBounds(pair) ? visits_[encodeCoords(pair)] : 0;
}

//------------------------------------------------------------------------------
void VisitsMap::visit(CoordPair pair)
{
  if (isWithinBounds(pair))
  {
    visits_[encodeCoords(pair)]++;
  }
}

//------------------------------------------------------------------------------
VisitsMap::~VisitsMap()
{
  delete visits_;
}

//------------------------------------------------------------------------------
bool VisitsMap::isWithinBounds(CoordPair pair)
{
  return pair.getX() >= 0 && pair.getY() >= 0 &&
    pair.getX() < size_x_ && pair.getY() < size_y_;
}

