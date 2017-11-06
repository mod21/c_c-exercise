#include "CommandSave.h"
#include "Exceptions.h"
#include "Game.h"
#include "LevelIO.h"
#include "Util.h"

const string CommandSave::NAME = "save";

//------------------------------------------------------------------------------
CommandSave::CommandSave() : Command(NAME)
{
}

//------------------------------------------------------------------------------
CommandSave::~CommandSave()
{
}

//------------------------------------------------------------------------------
bool CommandSave::execute(Game& game, std::vector<std::string>& params)
{
  if (params.size() != 1)
  {
    throw WrongParameterCountException();
  }

  string filename = params.at(0);

  if (!Util::checkFileName(filename))
  {
    throw WrongParameterException();
  }

  LevelIO::saveToFile(game.getLevel(), filename);

  return false;
}
