#include "FieldFinish.h"
#include "Direction.h"
#include "Player.h"

//------------------------------------------------------------------------------
FieldFinish::FieldFinish() :
  Field('x')
{
}

//------------------------------------------------------------------------------
bool FieldFinish::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  player->move(direction);
  return true;
}

//------------------------------------------------------------------------------
bool FieldFinish::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
FieldFinish::~FieldFinish()
{

}
