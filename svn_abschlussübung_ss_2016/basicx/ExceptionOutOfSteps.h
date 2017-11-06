#ifndef EXCEPTIONOUTOFSTEPS_H
#define EXCEPTIONOUTOFSTEPS_H

#include <exception>

//------------------------------------------------------------------------------
// Thrown when the player has no more steps available.
//
class OutOfStepsException : public std::exception
{
  virtual const char* what() const throw ()
  {
    return DomainMessages::OUT_OF_STEPS.c_str();
  }
};

#endif
