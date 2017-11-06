#ifndef EXCEPTIONNOMAZLOADED_H
#define EXCEPTIONNOMAZLOADED_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when there's no maze loaded.
//
class NoMazeLoadedException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::NO_MAZE_LOADED.c_str();
  }
};

#endif
