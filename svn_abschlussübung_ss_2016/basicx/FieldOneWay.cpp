#include "FieldOneWay.h"
#include "Direction.h"
#include "Player.h"

//------------------------------------------------------------------------------
FieldOneWay::FieldOneWay(char symbol, Direction* direction) :
  Field(symbol), direction_(direction)
{
}

//------------------------------------------------------------------------------
bool FieldOneWay::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  player->move(direction);
  return true;
}

//------------------------------------------------------------------------------
bool FieldOneWay::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return direction == direction_;
}

//------------------------------------------------------------------------------
FieldOneWay::~FieldOneWay()
{

}
