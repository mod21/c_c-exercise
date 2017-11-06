#include "FieldStart.h"
#include "Direction.h"
#include "Player.h"

//------------------------------------------------------------------------------
FieldStart::FieldStart() :
  Field('o')
{
}

//------------------------------------------------------------------------------
bool FieldStart::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  player->move(direction);
  return true;
}

//------------------------------------------------------------------------------
bool FieldStart::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
FieldStart::~FieldStart()
{
}
