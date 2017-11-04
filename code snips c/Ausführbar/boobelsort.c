/*<booblesort algorithmus>
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

void bs (int*, unsigned int);

int main () 
{
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    unsigned int leng = sizeof a / sizeof a[0];
    unsigned int i;
    for (i = 0; i < leng; i++)
        printf("%d%s", a[i], i == leng - 1 ? "\n" : " ");
    bs (a, leng);
    for (i = 0; i < leng; i++)
        printf("%d%s", a[i], i == leng - 1 ? "\n" : " ");
    return 0;
}

void bs (int *a, unsigned int leng) 
{
  int i, t;
  
  for (i = 1; i < leng; i++) 
    {
      if (a[i] < a[i - 1]) 
      {
        t = a[i];
        a[i] = a[i - 1];
        a[i - 1] = t;
      
      }
    }
}