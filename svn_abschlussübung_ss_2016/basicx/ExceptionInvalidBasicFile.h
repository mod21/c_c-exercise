#ifndef EXCEPTIONSINVALIDBASICFILE_H
#define EXCEPTIONSINVALIDBASICFILE_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when an invalid file is loaded.
//
class InvalidBasicFileException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::INVALID_FILE.c_str();
  }
};

#endif
