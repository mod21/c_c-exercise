#ifndef COMMANDSOLVE_H
#define COMMANDSOLVE_H

#include "Command.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

//------------------------------------------------------------------------------
// Solves the current level.
//
class CommandSolve : public Command
{
private:

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  // @param original Instance to be copied.
  //
  CommandSolve(const CommandSolve& original);

  //----------------------------------------------------------------------------
  // Private assignment operator - Should not be used.
  // @param original Instance to be assigned from.
  //
  CommandSolve& operator=(const CommandSolve& original);

public:

  //----------------------------------------------------------------------------
  // Default constructor - creates a new instance.
  //
  CommandSolve();

  //----------------------------------------------------------------------------
  // Deletes this instance.
  //
  virtual ~CommandSolve();

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
