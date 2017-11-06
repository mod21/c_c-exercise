#ifndef COMMANDSAVE_H
#define COMMANDSAVE_H

#include "Command.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

//----------------------------------------------------------------------------
// Saves the current game to a specific file.
//
class CommandSave : public Command
{
private:

  //--------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  // @param original Instance to be copied.
  //
  CommandSave(const CommandSave& original);

  //--------------------------------------------------------------------------
  // Private assignment operator - Should not be used.
  // @param original Instance to be assigned from.
  //
  CommandSave& operator=(const CommandSave& original);

public:

  //--------------------------------------------------------------------------
  // Default constructor - creates a new instance.
  //
  CommandSave();

  //--------------------------------------------------------------------------
  // Deletes this instance.
  //
  virtual ~CommandSave();

  //--------------------------------------------------------------------------
  // Executes the command. Abstract method.
  // @param game The game where action should be performed on.
  // @param params Possible parameters needed for the execution.
  // @return Whether the command should terminate the program.
  //
  virtual bool execute(Game& game, vector<string>& params);

  //----------------------------------------------------------------------------
  //The name of the command
  static const string NAME;
};

#endif
