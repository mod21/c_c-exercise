#include "FieldIce.h"
#include "FieldCounter.h"
#include "Direction.h"
#include "Player.h"
#include "Level.h"
#include "Map.h"

//------------------------------------------------------------------------------
FieldIce::FieldIce() :
  Field('+')
{
}

//------------------------------------------------------------------------------
bool FieldIce::onEnter(Player* player, CoordPair position, Direction* direction)
{
  player->move(direction);
  if (player->step(direction, false))
  {
//    Field* field = player->getCurrentField();
    Field* field = player->getLevel()->getMap()->
      getFieldAt(player->getPosition());
    if(typeid(*field) == typeid(FieldCounter))
    {
      player->setIceCounter();
    }
  }
  return true;
}

//------------------------------------------------------------------------------
bool FieldIce::onLeave(Player* player, CoordPair position, Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
FieldIce::~FieldIce()
{

}
