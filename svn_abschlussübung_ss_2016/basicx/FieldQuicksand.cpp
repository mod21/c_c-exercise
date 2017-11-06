#include "FieldQuicksand.h"
#include "Direction.h"
#include "Player.h"

//------------------------------------------------------------------------------
FieldQuicksand::FieldQuicksand(int malus) :
  Field('f' - 1 + (char) malus), malus_(malus)
{
}

//------------------------------------------------------------------------------
bool FieldQuicksand::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  player->move(direction);
  player->takeRemainingSteps(malus_);
  return true;
}

//------------------------------------------------------------------------------
bool FieldQuicksand::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
FieldQuicksand::~FieldQuicksand()
{
}
