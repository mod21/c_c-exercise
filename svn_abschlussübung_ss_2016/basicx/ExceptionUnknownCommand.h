#ifndef EXPECTIONUNKNOWNCOMMAND_H
#define EXPECTIONUNKNOWNCOMMAND_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when an unknown command is entered.
//
class UnknownCommandException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::UNKNOWN_COMMAND.c_str();
  }
};

#endif
