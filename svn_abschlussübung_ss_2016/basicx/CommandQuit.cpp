#include "CommandQuit.h"
#include "Exceptions.h"
#include "Messages.h"
#include "Game.h"

#include <iostream>

const string CommandQuit::NAME = "quit";

//------------------------------------------------------------------------------
CommandQuit::CommandQuit() : Command(NAME)
{
}

//------------------------------------------------------------------------------
CommandQuit::~CommandQuit()
{
}

//------------------------------------------------------------------------------
bool CommandQuit::execute(Game& game, std::vector<std::string>& params)
{
  if (params.size() != 0)
  {
    throw WrongParameterCountException();
  }
  std::cout << DomainMessages::BYE;
  return true;
}
