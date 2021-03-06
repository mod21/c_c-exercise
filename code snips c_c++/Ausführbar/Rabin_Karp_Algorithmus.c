/*<Rabin_Karp algorithmus>
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
#include <string.h>

void search(char pat[], char txt[]);

int main()
{
  char txt[] = "NERDS FOR NERDS";
  char pat[] = "NERD";
    
  if ((strlen(txt) >= strlen(pat)) && ((strlen (txt) && strlen (pat)) != 0))
    {
        
      search(pat, txt);
    }
  else{printf("wrong parameter \n");}
}

void search(char pat[], char txt[])
{
  int M = strlen(pat);
  int N = strlen(txt);
  int i, j;

  for (i = 0; i <= N - M; i++)
    {
      for (j = 0; j < M; j++)
        {
          if (txt[i+j] != pat[j])
          break;
        }
      if (j == M)
        {
          printf("Pattern found at index %d \n", i);
        }
    }
}