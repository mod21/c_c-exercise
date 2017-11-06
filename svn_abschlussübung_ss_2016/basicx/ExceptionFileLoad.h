#ifndef EXCEPTIONFILELOAD_H
#define EXCEPTIONFILELOAD_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when there's an error in the file IO.
//
class FileLoadException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::IOS_FAILURE.c_str();
  }
};

#endif
