/*<quicksort algorithmus>
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

void qs (int *a, unsigned int leng) 
{
  if (leng < 2) return;
 
  int pivot = a[leng / 2];
 
  int i, j;
  for (i = 0, j = leng - 1; ; i++, j--) 
  {
    while (a[i] < pivot) i++;
    while (a[j] > pivot) j--;
    
    if (i >= j) break;
    
    int temp = a[i];
    a[i]     = a[j];
    a[j]     = temp;
  }
 
  qs(a, i);
  qs(a + i, leng - i);
}