#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

//------------------------------------------------------------------------------
// Game class declaration.
//
class Game;

//------------------------------------------------------------------------------
// Used for command logic.
//
class Command
{
private:

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  // @param original Instance to be copied.
  //
  Command(const Command& original);

  //----------------------------------------------------------------------------
  // Private assignment operator - Soulh not be used.
  // @param original Instance to be assigned from.
  //
  Command& operator=(const Command& original);

  //----------------------------------------------------------------------------
  // Name of this command.
  //
  std::string command_name_;

public:

  //----------------------------------------------------------------------------
  // Default Constructor - Should not be used.
  //
  Command() = delete;

  //----------------------------------------------------------------------------
  // Copy constructor.
  // @param name The name of the command to be copied.
  //
  Command(std::string name);

  //----------------------------------------------------------------------------
  // Deletes this instance.
  //
  virtual ~Command();

  //----------------------------------------------------------------------------
  // Executes the command. Abstract method.
  // @param game The game where action should be performed on.
  // @param params Possible parameters needed for the execution.
  // @return Whether the command should terminate the program.
  //
  virtual bool execute(Game& game, std::vector<std::string>& params) = 0;

  //----------------------------------------------------------------------------
  // Returns the name of this command.
  // @return The name of this command.
  //
  const std::string& getName() const;
};

#endif
