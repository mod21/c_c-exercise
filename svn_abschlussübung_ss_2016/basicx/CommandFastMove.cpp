#include "CommandFastMove.h"
#include "Direction.h"
#include "Exceptions.h"
#include "Game.h"
#include "Player.h"
#include "Level.h"

#include <string>

const string CommandFastMove::NAME = "fastmove";

//------------------------------------------------------------------------------
CommandFastMove::CommandFastMove() : Command(NAME)
{
}

//------------------------------------------------------------------------------
CommandFastMove::~CommandFastMove()
{
}

//------------------------------------------------------------------------------
bool CommandFastMove::execute(Game& game, vector<string>& params)
{
  if (params.size() != 1)
  {
    throw WrongParameterCountException();
  }

  vector<Direction*> steps;
  string step_string = params.at(0);

  for (unsigned int index = 0; index < step_string.size(); index++)
  {
    Direction* direction = Direction::getDirectionByChar(step_string.at(index));
    if (direction == nullptr)
    {
      throw WrongParameterException();
    }
    steps.push_back(direction);
  }

  Level* level = game.getLevel();
  if (level == nullptr)
  {
    throw NoMazeLoadedException();
  }

  if (level->getPlayer()->isFinished())
  {
    throw InvalidMoveException();
  }

  if (!level->getPlayer()->hasStepsLeft())
  {
    level->respawnPlayer();
    throw OutOfStepsException();
  }

  if (!level->fastMove(steps))
  {
    throw InvalidMoveException();
  }

  game.autoSave();
  level->print(false, false);
  level->getPlayer()->checkFinished();

  return false;
}
