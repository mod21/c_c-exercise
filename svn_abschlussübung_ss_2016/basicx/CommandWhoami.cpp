#include "CommandWhoami.h"
#include "Exceptions.h"
#include "Messages.h"
#include "Game.h"

#include <iostream>

const string CommandWhoami::NAME = "whoami";
//------------------------------------------------------------------------------
CommandWhoami::CommandWhoami() : Command(NAME)
{
}

//------------------------------------------------------------------------------
CommandWhoami::~CommandWhoami()
{
}

//------------------------------------------------------------------------------
bool CommandWhoami::execute(Game& game, std::vector<std::string>& params)
{
  if (params.size() != 0)
  {
    throw WrongParameterCountException();
  }
  std::cout << DomainMessages::NAME;
  return false;
}
