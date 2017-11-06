#ifndef EXCEPTIONALREADYSOLVED_H
#define EXCEPTIONALREADYSOLVED_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when the maze is already solved.
//
class AlreadySolvedException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::ALREADY_SOLVED.c_str();
  }
};

#endif
