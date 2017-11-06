#include "FieldHole.h"
#include "Direction.h"
#include "Player.h"
#include "Level.h"
#include "Map.h"

//------------------------------------------------------------------------------
FieldHole::FieldHole() :
  Field('s')
{
}

//------------------------------------------------------------------------------
bool FieldHole::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  player->teleportToSpawn();
  return true;
}

//------------------------------------------------------------------------------
bool FieldHole::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
FieldHole::~FieldHole()
{
}
