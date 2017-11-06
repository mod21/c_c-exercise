#include "CommandParser.h"
#include "CommandLineArgumentParser.h"
#include "Exceptions.h"
#include "Game.h"
#include "Util.h"
#include "Command.h"

#include <vector>
#include <string>

using std::cout;

//------------------------------------------------------------------------------
// All command line argument related stuff. Also handles errors.
// @param game The current game.
// @param argc Number of arguments given including the program name itself.
// @param argv Array containing the arguments as C-Strings.
// @return Return code.
//
int parseArguments(Game& game, int argc, char* argv[])
{
  CommandLineArgumentParser argumentParser;
  try
  {
    argumentParser.parseArguments(argc, argv);
  }
  catch (const std::exception& exception)
  {
    int result = processErrorMessage(exception);
    if (result)
    {
      return result;
    }
  }
  
  try
  {
    if (argumentParser.isAutoSave())
    {
      game.enableAutoSave(argumentParser.getAutoSavePath());
    }
  }
  catch (const std::exception& exception)
  {
    int result = processErrorMessage(exception);
    if (result)
    {
      return result;
    }
  }
  
  try
  {
    if (argumentParser.isDefaultLoad())
    {
      game.loadAndInitializeLevel(argumentParser.getDefaultLoadPath());
    }
  }
  catch (const std::exception& exception)
  {
    int result = processErrorMessage(exception);
    if (result)
    {
      return result;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Lets the user enter commands and handles their error message. Terminates
// when a fatal exception occurs or when the quit command is dispatched.
// @param game The current game instance.
// @return Return code.
//
int commandLoop(Game& game)
{
  CommandParser parser;
  while (true)
  {
    Command* command = nullptr;
    try
    {
      std::cout << "sep> ";

      parser.readCommand();
      command = parser.getCommand();

      // The user has entered nothing and pressed return
      if (command == nullptr)
      {
        continue;
      }

      auto commandArguments = parser.getParams();
      bool result = command->execute(game, commandArguments);
      delete command;
      command = nullptr;

      if (result)
      {
        return 0;
      }
    }
    catch (const std::exception& exception)
    {
      if (command)
      {
        delete command;
      }
      int result = processErrorMessage(exception);
      if (result)
      {
        return result;
      }
    }
  }
  // No return required at this point
}

//------------------------------------------------------------------------------
// Main function of our program.
// @param argc Number of arguments given including the program name itself.
// @param argv Array containing the arguments as C-Strings.
// @return Return code.
//
int main(int argc, char* argv[])
{
  try
  {
    int result;
    Game game;
    Util::init();

    result = parseArguments(game, argc, argv);
    if (result)
    {
      Util::prepareExit();
      return result;
    }

    result = commandLoop(game);
    Util::prepareExit();
    return result;
  }
  catch (const std::exception& exception)
  {
    Util::prepareExit();
    return processErrorMessage(exception);
  }
}
