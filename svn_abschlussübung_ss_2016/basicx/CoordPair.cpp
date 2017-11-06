#include "CoordPair.h"
#include "Direction.h"

//------------------------------------------------------------------------------
CoordPair::CoordPair() :
  x_(0), y_(0)
{
}

//------------------------------------------------------------------------------
CoordPair::CoordPair(const int x, const int y) :
  x_(x), y_(y)
{
}

//------------------------------------------------------------------------------
CoordPair::CoordPair(const CoordPair& pair) :
  x_(pair.x_), y_(pair.y_)
{
}

//------------------------------------------------------------------------------
int CoordPair::getX()
{
  return x_;
}

//------------------------------------------------------------------------------
int CoordPair::getY()
{
  return y_;
}

//------------------------------------------------------------------------------
void CoordPair::add(int x, int y)
{
  x_ += x;
  y_ += y;
}

//------------------------------------------------------------------------------
void CoordPair::addDirection(Direction* direction)
{
  x_ += direction->getX();
  y_ += direction->getY();
}

//------------------------------------------------------------------------------
const bool CoordPair::operator==(const CoordPair& pair)
{
  return x_ == pair.x_ && y_ == pair.y_;
}

//------------------------------------------------------------------------------
const bool CoordPair::operator!=(const CoordPair& pair)
{
  return x_ != pair.x_ || y_ != pair.y_;
}

//------------------------------------------------------------------------------
const bool CoordPair::operator<(const CoordPair& pair)
{
  return y_ == pair.y_ ? x_ < pair.x_ : y_ < pair.y_;
}
