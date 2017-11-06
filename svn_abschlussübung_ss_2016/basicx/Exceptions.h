#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <typeinfo>
#include <iostream>

#include "Messages.h"
#include "ExceptionAlreadySolved.h"
#include "ExceptionInvalidMove.h"
#include "ExceptionInvalidBasicFile.h"
#include "ExceptionUnknownCommand.h"
#include "ExceptionWrongParameter.h"
#include "ExceptionWrongParameterCount.h"
#include "ExceptionNoMazeLoaded.h"
#include "ExceptionNoPath.h"
#include "ExceptionFileLoad.h"
#include "ExceptionFileWrite.h"
#include "ExceptionOutOfSteps.h"
#include "ExceptionInvalidPath.h"
#include "ExceptionWrongUsage.h"

using std::exception;
using std::string;

//------------------------------------------------------------------------------
// Used to process exceptions correctly and display the error message.
// @return If the returned value is not 0, it should be the return value
//         of the program.
//
inline const int processErrorMessage(const exception& ex)
{
  if (typeid(ex) == typeid(std::bad_alloc))
  {
    std::cout << DomainMessages::OUT_OF_MEMORY;
    return 1;
  }
  else if (typeid(ex) == typeid(std::ios_base::failure))
  {
    std::cout << DomainMessages::IOS_FAILURE;
    return 0;
  }
  std::cout << ex.what();
  return typeid(ex) == typeid(WrongUsageException) ? 2 : 0;
}

#endif
