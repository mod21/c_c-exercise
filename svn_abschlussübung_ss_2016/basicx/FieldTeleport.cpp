#include "FieldTeleport.h"
#include "Direction.h"
#include "Player.h"
#include "Map.h"
#include "Level.h"
#include "CoordPair.h"

//------------------------------------------------------------------------------
FieldTeleport::FieldTeleport(char id) :
  Field('A' + id)
{
}

//------------------------------------------------------------------------------
bool FieldTeleport::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  player->teleport(position);
  return true;
}

//------------------------------------------------------------------------------
bool FieldTeleport::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
FieldTeleport::~FieldTeleport()
{
}
