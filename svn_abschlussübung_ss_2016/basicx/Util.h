#ifndef UTIL_H
#define UTIL_H

#include <algorithm>
#include <string>

using std::string;
using std::all_of;

namespace Util
{
  //----------------------------------------------------------------------------
  // Checks if a string is only composed of digits.
  // @param str The string to check.
  // @return Whether a string is a positive whole number.
  //
  bool checkAllDigits(const string& str);

  //----------------------------------------------------------------------------
  // Removes unnecessary whitespaces from a string.
  // @param str The input string.
  // @param whitespace cCaracter defintion.
  // @return A cleaned up string.
  //
  string trim(const string& str, const string& whitespace = " \t");

  //----------------------------------------------------------------------------
  // Deletes allocated objects before terminating the program.
  //
  void prepareExit();

  //----------------------------------------------------------------------------
  // Initializes all java-style-enums.
  //
  void init();

  //----------------------------------------------------------------------------
  // Checks the given filename for invalid characters.
  // @return Returns whether or not the given filename is valid.
  //
  bool checkFileName(string name);
};

#endif
