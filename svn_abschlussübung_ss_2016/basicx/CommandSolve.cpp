#include "CommandSolve.h"
#include "Direction.h"
#include "Exceptions.h"
#include "Messages.h"
#include "Game.h"
#include "Level.h"
#include "LevelIO.h"
#include "Player.h"
#include "Solver.h"

#include <iostream>

const string CommandSolve::NAME = "solve";
//------------------------------------------------------------------------------
CommandSolve::CommandSolve() : Command(NAME)
{
}

//------------------------------------------------------------------------------
CommandSolve::~CommandSolve()
{
}

//------------------------------------------------------------------------------
bool CommandSolve::execute(Game& game, std::vector<std::string>& params)
{
  bool silent = false;
  if (params.size() == 0)
  {
    silent = false;
  }
  else if(params.size() == 1)
  {
    if(params.at(0) == "silent")
    {
      silent = true;
    }
    else
    {
      throw WrongParameterException();
    }
  }
  else
  {
    throw WrongParameterCountException();
  }

  Level* level = game.getLevel();

  if (level == nullptr)
  {
    throw NoMazeLoadedException();
  }

  Player* player = level->getPlayer();

  if (player->isFinished())
  {
    throw AlreadySolvedException();
  }

  if (!player->hasStepsLeft())
  {
    level->respawnPlayer();
    throw OutOfStepsException();
  }

  int old_steps = player->getRemainingSteps();

  vector<Direction*>* steps = Solver(level).solve();

  if(steps == nullptr)
  {
    throw NoPathException();
  }

  level->fastMove(*steps);
  player = level->getPlayer();
  int steps_taken = old_steps - player->getRemainingSteps();
  player->checkFinished();
  LevelIO::saveToFile(level, level->getFilename() + "Solved");

  std::cout << "The maze was solved in " << steps_taken << " steps."
    << std::endl;

  if(!silent)
  {
    std::cout << "Found path: ";
    for(Direction* direction: *steps)
    {
      std::cout << direction->getChar();
    }
    std::cout << std::endl;
  }

  delete steps;

  return false;
}
