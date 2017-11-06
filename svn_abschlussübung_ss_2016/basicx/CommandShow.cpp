#include "CommandShow.h"
#include "Exceptions.h"
#include "Game.h"
#include "Level.h"

const string CommandShow::NAME = "show";

//------------------------------------------------------------------------------
CommandShow::CommandShow() : Command(NAME)
{
}

//------------------------------------------------------------------------------
CommandShow::~CommandShow()
{
}

//------------------------------------------------------------------------------
bool CommandShow::execute(Game& game, std::vector<std::string>& params)
{
  bool more = false;
  bool nopath = false;
  if (params.size() > 2)
  {
    throw WrongParameterCountException();
  }
  if (params.size() >= 1)
  {
    if (params.at(0) != "more")
    {
      throw WrongParameterException();
    }
    more = true;
  }
  if (params.size() >= 2)
  {
    if (params.at(1) != "nopath")
    {
      throw WrongParameterException();
    }
    nopath = true;
  }

  Level* level = game.getLevel();

  if (level == nullptr)
  {
    throw NoMazeLoadedException();
  }

  level->print(more, nopath);

  return false;
}
