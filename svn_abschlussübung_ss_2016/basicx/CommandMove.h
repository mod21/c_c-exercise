#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H

#include "Command.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

//------------------------------------------------------------------------------
// Moves the player in one direction.
//
class CommandMove : public Command
{
private:

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  // @param original Instance to be copied.
  //
  CommandMove(const CommandMove& original);

  //----------------------------------------------------------------------------
  // Private assignment operator - Should not be used.
  // @param original Instance to be assigned from.
  //
  CommandMove& operator=(const CommandMove& original);

public:

  //----------------------------------------------------------------------------
  // Default constructor - creates a new instance.
  //
  CommandMove();

  //----------------------------------------------------------------------------
  // Deletes this instance.
  //
  virtual ~CommandMove();

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
