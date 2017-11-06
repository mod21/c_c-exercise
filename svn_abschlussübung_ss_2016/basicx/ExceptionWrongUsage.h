#ifndef WRONGUSAGEEXCEPTION_H
#define WRONGUSAGEEXCEPTION_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when the program is called with invalid arguments.
//
class WrongUsageException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::WRONG_USAGE.c_str();
  }
};

#endif
