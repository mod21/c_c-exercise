#ifndef COMMANDSHOW_H
#define COMMANDSHOW_H

#include "Command.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

//------------------------------------------------------------------------------
// Prints the current state of the game.
//
class CommandShow : public Command
{
private:

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  // @param original Instance to be copied.
  //
  CommandShow(const CommandShow& original);

  //----------------------------------------------------------------------------
  // Private assignment operator - Should not be used.
  // @param original Instance to be assigned from.
  //
  CommandShow& operator=(const CommandShow& original);

public:

  //----------------------------------------------------------------------------
  // Default constructor - creates a new instance.
  //
  CommandShow();

  //----------------------------------------------------------------------------
  // Deletes this instance.
  //
  virtual ~CommandShow();

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
