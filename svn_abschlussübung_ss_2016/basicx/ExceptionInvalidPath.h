#ifndef EXCEPTIONINVALIDPATH_H
#define EXCEPTIONINVALIDPATH_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when there's an invalid path.
//
class InvalidPathException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::INVALID_PATH.c_str();
  }
};

#endif
