#ifndef EXCEPTIONNOPATH_H
#define EXCEPTIONNOPATH_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when the maze is already solved.
//
class NoPathException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::NO_PATH_FOUND.c_str();
  }
};

#endif
