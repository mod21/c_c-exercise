#ifndef EXCEPTIONWRONGPARAMETER_H
#define EXCEPTIONWRONGPARAMETER_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when an invalid parameter is used in a command.
//
class WrongParameterException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::WRONG_PARAMETER.c_str();
  }
};

#endif
