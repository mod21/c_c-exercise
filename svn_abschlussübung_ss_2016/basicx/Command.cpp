#include "Command.h"
#include "Game.h"

//------------------------------------------------------------------------------
Command::Command(std::string name) :
  command_name_(name)
{
}

//------------------------------------------------------------------------------
Command::~Command()
{
}

//------------------------------------------------------------------------------
const std::string& Command::getName() const
{
  return command_name_;
}
