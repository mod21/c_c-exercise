#include "CommandLineArgumentParser.h"
#include "Exceptions.h"
#include "Util.h"

//------------------------------------------------------------------------------
CommandLineArgumentParser::CommandLineArgumentParser() :
  isAutoSave_(false), isDefaultLoad_(false)
{
}

//------------------------------------------------------------------------------
CommandLineArgumentParser::~CommandLineArgumentParser()
{
}

//------------------------------------------------------------------------------
bool CommandLineArgumentParser::isAutoSave()
{
  return isAutoSave_;
}

//------------------------------------------------------------------------------
bool CommandLineArgumentParser::isDefaultLoad()
{
  return isDefaultLoad_;
}

//------------------------------------------------------------------------------
string CommandLineArgumentParser::getAutoSavePath()
{
  return autoSavePath_;
}

//------------------------------------------------------------------------------
string CommandLineArgumentParser::getDefaultLoadPath()
{
  return defaultLoadPath_;
}

//------------------------------------------------------------------------------
void CommandLineArgumentParser::parseArguments(int argc, char* argv[])
{
  string checkm("-m");
  string checks("-s");

  if (argc <= 1)
  {
    return;
  }

  argc--;

  if ((argc & 1) != 0)
  {
    throw WrongUsageException();
  }

  for (int index = 0; index < argc >> 1; index++)
  {
    string flag = argv[index << 1 | 1];
    string value = argv[(index + 1) << 1];
    if (checkm.compare(flag) == 0)
    {
      if (isDefaultLoad_ || checks.compare(value) == 0)
      {
        throw WrongUsageException();
      }
      isDefaultLoad_ = true;
      defaultLoadPath_ = value;
    }
    else if (checks.compare(flag) == 0)
    {
      if (isAutoSave_ || checkm.compare(value) == 0)
      {
        throw WrongUsageException();
      }
      isAutoSave_ = true;
      autoSavePath_ = value;
    }
    else
    {
      throw WrongUsageException();
    }
  }
}
