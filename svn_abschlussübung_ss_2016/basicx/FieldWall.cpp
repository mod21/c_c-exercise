#include "FieldWall.h"
#include "Direction.h"
#include "Level.h"

//------------------------------------------------------------------------------
FieldWall::FieldWall() :
  Field('#')
{
}

//------------------------------------------------------------------------------
bool FieldWall::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  return false;
}

//------------------------------------------------------------------------------
bool FieldWall::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
FieldWall::~FieldWall()
{

}
