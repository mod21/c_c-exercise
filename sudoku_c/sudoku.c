/*<sudoku solver>
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

static void outp(int *x);
static int brutef(int *x, int);
static void slove(const char *s);

int main(void)
{
slove(	  "... ... ..1"
          "... ... .23"
          "..4 ..5 ..."
          "... 1... ..."
          "... .3. 6.."
          "..7 ... 56."
          "... .67 ..."
          ".1. ..4 ..."
          "52. ... ..."	);
 
return 0;
}

/*funcition for output*/
static void outp(int *x)
{
  int i, j;
  for (i = 0; i < 9; i++) 
  {
    if (!(i % 3)) putchar('\n');
    for (j = 0; j < 9; j++) printf(j % 3 ? "%2d" : "%3d", *x++);
    putchar('\n');
  }
}
 
/*funcition for brute force*/
static int brutef(int *x, int pos)
{
  int row = pos / 9;
  int col = pos % 9;
  int i, j, used = 0;
 
  if (pos == 81) return 1;
  if (x[pos]) return brutef(x, pos + 1);
 
  for (i = 0; i < 9; i++) used |= 1 << (x[i * 9 + col] - 1);
 
  for (j = 0; j < 9; j++) used |= 1 << (x[row * 9 + j] - 1);
 
  row = row / 3 * 3;
  col = col / 3 * 3;
  
  for (i = row; i < row + 3; i++)
  {
    for (j = col; j < col + 3; j++) used |= 1 << (x[i * 9 + j] - 1);
  }
  for (x[pos] = 1; x[pos] <= 9; x[pos]++, used >>= 1) 
    if (!(used & 1) && brutef(x, pos + 1)) return 1;
 
  x[pos] = 0;
  return 0;
}
 
/*funcition for solve */
static void slove(const char *s)
{
  int i, x[81];
  for (i = 0; i < 81; i++) x[i] = s[i] >= '1' && s[i] <= '9' ? s[i] - '0' : 0;
 
  if (brutef(x, 0)) outp(x);
  else puts("no solution");
}