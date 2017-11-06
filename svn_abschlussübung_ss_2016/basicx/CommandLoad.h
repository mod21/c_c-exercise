#ifndef COMMANDLOAD_H
#define COMMANDLOAD_H

#include "Command.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

//------------------------------------------------------------------------------
// Loads a new save file.
//
class CommandLoad : public Command
{
private:

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  // @param original Instance to be copied.
  //
  CommandLoad(const CommandLoad& original);

  //----------------------------------------------------------------------------
  // Private assignment operator - Should not be used.
  // @param original Instance to be assigned from.
  //
  CommandLoad& operator=(const CommandLoad& original);

public:

  //----------------------------------------------------------------------------
  // Default constructor - creates a new instance.
  //
  CommandLoad();

  //----------------------------------------------------------------------------
  // Deletes this instance.
  //
  virtual ~CommandLoad();

  //----------------------------------------------------------------------------
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
