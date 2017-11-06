#include "FieldPath.h"
#include "Direction.h"
#include "Player.h"

//------------------------------------------------------------------------------
FieldPath::FieldPath() :
  Field(' ')
{
}

//------------------------------------------------------------------------------
bool FieldPath::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  player->move(direction);
  return true;
}

//------------------------------------------------------------------------------
bool FieldPath::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
FieldPath::~FieldPath()
{

}
