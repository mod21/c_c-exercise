#ifndef EXCEPTIONWRONGPARAMETERCOUNT_H
#define EXCEPTIONWRONGPARAMETERCOUNT_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when the parameter count in a command is invalid.
//
class WrongParameterCountException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::WRONG_PARAMETER_COUNT.c_str();
  }
};

#endif
