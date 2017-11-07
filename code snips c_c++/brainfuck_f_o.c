/*<brainfuck_interpreter>
    Copyright (C) <2017>  <Simperl Tobias>
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void brainfuck_interpreter(const char* instruction, unsigned cnt)
{
  char* const tape = calloc(cnt,1);
  char * ptr = tape;
    
  for (;*instruction != '\0'; ++instruction)
  {
    switch (*instruction)
    {
      case '>': ++ptr; break;
      case '<': --ptr; break;
      case '+': ++*ptr; break;
      case '-': --*ptr; break;
      case '.': putchar(*ptr); break;
      case ',': *ptr = getchar(); break;
      case '[':
        if (!*ptr)
        {
          unsigned c = 1;
          do
          {
            ++instruction;
            if (*instruction == ']') --c;
            else if (*instruction == '[') ++c;
          }
          while (c);
        }
        break;
      case ']':
        if (*ptr)
        {
          unsigned c = 1;
          do
          {
            --instruction;
            if (*instruction == '[') --c;
            else if (*instruction == ']') ++c;
          }
          while (c);
        }
        break;
      
      default:
        
      printf("Invalid character '%c'\n", *instruction);
    }
  }
  free(tape);
}
