#ifndef EXCEPTIONINVALIDMOVE_H
#define EXCEPTIONINVALIDMOVE_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when the player makes an invalid move.
//
class InvalidMoveException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::INVALID_MOVE.c_str();
  }
};

#endif
