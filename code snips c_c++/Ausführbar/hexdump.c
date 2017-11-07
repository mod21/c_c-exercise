/*<hexdump>
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

#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#define colnum  16

static void hexdump(const void * data, size_t size );
 
int main(void) {
  unsigned char ascii[256];
  int f;
  
  for (f = 0; f < sizeof ascii; ++f)
    ascii[f] = f;
  hexdump(ascii, sizeof ascii);
  return 0;
  }

static void hexdump (const void* data, size_t size)
  {
  const unsigned char * p, * q;
  int i;
  p = data;
  
  while (size)
  {
    q = p;
    printf("%p: ", (void *) p);
  
    for (i = 0; i < colnum && size; ++i)
    {
      printf("%02X ", *p);
      ++p;
      --size;
    }
    
    size += i;
  
    while (i < colnum)
      {
        printf("XX ");
        ++i;
      }
  
    printf("| ");
    p=q;
  
    for (i = 0; i < colnum && size; ++i)
    {
      printf("%c", isprint(*p) && !isspace(*p) ? *p : ' ');
      ++p;
      --size;
    }
    
    while (i < colnum)
    {
      printf("");
      ++i;
    }
   printf(" |\n");
  
  }    
return;
}