					<Tictactoe>
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

#include <stdio.h>
#include <stdlib.h>
int b[3][3]; 
int cw ();
void sb();
int best_i, best_j;
int tm(int, int);
const char* game(int);
 

 /* -1: computer 
  * 1: human */
int main()
{
  int first = 0;
  while (1) printf("%s", game(first = !first));
  return 0;
}

int cw()
{
  int i;
  for (i = 0; i < 3; i++) 
  {
    if (b[i][0] && b[i][1] == b[i][0] && b[i][2] == b[i][0])
    return b[i][0];
    if (b[0][i] && b[1][i] == b[0][i] && b[2][i] == b[0][i])
    return b[0][i];
  }
  if (!b[1][1]) return 0;
 
  if (b[1][1] == b[0][0] && b[2][2] == b[0][0]) return b[0][0];
  if (b[1][1] == b[2][0] && b[0][2] == b[1][1]) return b[1][1];
 
  return 0;
}

void sb()
{
  const char *t = "X O";
  int i, j;
  for (i = 0; i < 3; i++, putchar('\n'))
  {
    for (j = 0; j < 3; j++)	printf("%c ", t[ b[i][j] + 1 ]);
  }
 printf("-----\n");
}

int tm(int val, int depth)
{
  int i, j, score;
  int best = -1, changed = 0;
 
  if ((score = cw())) return (score == val) ? 1 : -1;
 
  for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) 
  {
    if (b[i][j]) continue;
    
    changed = b[i][j] = val;
    score = -tm(-val, depth + 1);
    b[i][j] = 0;
    
    if (score <= best) continue;
    if (!depth) 
    {
      best_i = i;
      best_j = j;
    }
    
    best = score;
  }
 
  return changed ? best : 0;
}

const char* game(int user)
{
  printf("Feldnummer wie folgt:\n1 2 3\n4 5 6\n7 8 9\n");
  printf("Du hast O, Ich habe X.\n\n");
  
  int i, j, k, move, win = 0;
  for (i = 0; i < 3; i++) 
  {
    for (j = 0; j < 3; j++) b[i][j] = 0;
  }
  
for (k = 0; k < 9; k++, user = !user) 
  {
    while(user) 
    {
      printf("dein zug: ");
      
      if (!scanf("%d", &move)) 
      {
        scanf("%*s");
        continue;
      }
      
      if (--move < 0 || move >= 9) continue;
      if (b[i = move / 3][j = move % 3]) continue;
 
      b[i][j] = 1;
      break;
    }

  if (!user) 
  {
    if (!k) 
    { 
      best_i = rand() % 3;
      best_j = rand() % 3;
  } else tm(-1, 0);
 
  b[best_i][best_j] = -1;
  printf("mein zug: %d\n", best_i * 3 + best_j + 1);
}
 
sb();
  if ((win = cw())) return win == 1 ? "Du hast gewonne\n\n": "Ich habe gewonnen\n\n";
6  return "Unentschieden\n\n";
}