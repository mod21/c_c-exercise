#include "CommandLoad.h"
#include "Exceptions.h"
#include "Game.h"
#include "Level.h"

#include <string>

const string CommandLoad::NAME = "load";

//------------------------------------------------------------------------------
CommandLoad::CommandLoad() : Command(NAME)
{
}

//------------------------------------------------------------------------------
CommandLoad::~CommandLoad()
{
}

//------------------------------------------------------------------------------
bool CommandLoad::execute(Game& game, std::vector<std::string>& params)
{
  if (params.size() != 1)
  {
    throw WrongParameterCountException();
  }

  game.loadAndInitializeLevel(params.at(0));

  return false;
}
