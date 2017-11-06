#ifndef EXCEPTIONFILEWRITE_H
#define EXCEPTIONFILEWRITE_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when there's an error in the file IO.
//
class FileWriteException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::WRITE_ERROR.c_str();
  }
};

#endif
