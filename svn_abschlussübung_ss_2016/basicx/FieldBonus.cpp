#include "FieldBonus.h"
#include "Direction.h"
#include "CoordPair.h"
#include "Player.h"

//------------------------------------------------------------------------------
FieldBonus::FieldBonus(int bonus) :
  Field('a' - 1 + (char) bonus), bonus_(bonus)
{
}

//------------------------------------------------------------------------------
bool FieldBonus::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  if (player->getFieldVisits(position) == 0)
  {
    player->grantMoreSteps(bonus_);
  }
  player->move(direction);
  return true;
}

//------------------------------------------------------------------------------
bool FieldBonus::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
char FieldBonus::getDisplaySymbol(Player* player, CoordPair position)
{
  return player->getFieldVisits(position) ? Field::PATH->getSymbol() :
    getSymbol();
}

//------------------------------------------------------------------------------
FieldBonus::~FieldBonus()
{

}
