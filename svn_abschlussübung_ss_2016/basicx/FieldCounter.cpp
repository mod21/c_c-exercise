#include "FieldCounter.h"
#include "Direction.h"
#include "Player.h"
#include "Level.h"

//------------------------------------------------------------------------------
FieldCounter::FieldCounter(int steps) :
  Field('0' + steps), steps_(steps)
{
}

//------------------------------------------------------------------------------
bool FieldCounter::onEnter(Player* player, CoordPair position,
  Direction* direction)
{
  if (player->getFieldVisits(position) >= steps_)
  {
    return false;
  }
  player->move(direction);
  return true;
}

//------------------------------------------------------------------------------
bool FieldCounter::onLeave(Player* player, CoordPair position,
  Direction* direction)
{
  return true;
}

//------------------------------------------------------------------------------
char FieldCounter::getDisplaySymbol(Player* player, CoordPair position)
{
  int visits = player->getFieldVisits(position);
  return visits >= steps_ ? Field::WALL->getSymbol() : getSymbol() - visits;
}

//------------------------------------------------------------------------------
int FieldCounter::getStepCount()
{
  return steps_;
}

//------------------------------------------------------------------------------
FieldCounter::~FieldCounter()
{
}
