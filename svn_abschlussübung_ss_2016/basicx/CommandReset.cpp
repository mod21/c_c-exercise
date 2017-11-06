#include "CommandReset.h"
#include "Exceptions.h"
#include "Game.h"
#include "Player.h"
#include "Level.h"

const string CommandReset::NAME = "reset";

//------------------------------------------------------------------------------
CommandReset::CommandReset() : Command(NAME)
{
}

//------------------------------------------------------------------------------
CommandReset::~CommandReset()
{
}

//------------------------------------------------------------------------------
bool CommandReset::execute(Game& game, std::vector<std::string>& params)
{
  if (params.size() != 0)
  {
    throw WrongParameterCountException();
  }

  if (game.getLevel() == nullptr)
  {
    throw NoMazeLoadedException();
  }

  game.getLevel()->respawnPlayer();
  game.autoSave();

  return false;
}
