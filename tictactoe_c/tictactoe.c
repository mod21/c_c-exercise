#include <stdio.h>
#include <stdlib.h>
 
int board [3][3]; //arry for game board
static int checkwin(); //check the winner
static void outp(); //output 
int best_i, best_j;
static int kitest(int, int);
static const char* game(int);
 
int main()
{
  int first = 0;
  while (1) printf("%s", game(first = !first));
  return 0;
}

/* funcition to Chekc the winner */
static int checkwin()
{
  int i;
  for (i = 0; i < 3; i++) 
  {
    if (board [i][0] && board[i][1] == board[i][0] && board[i][2] == board[i][0])
    return board[i][0];
    if (board[0][i] && board[1][i] == board[0][i] && board[2][i] == board[0][i])
    return board[0][i];
  }
  if (!board[1][1]) return 0;
 
  if (board[1][1] == board[0][0] && board[2][2] == board[0][0]) return board[0][0];
  if (board[1][1] == board[2][0] && board[0][2] == board[1][1]) return board[1][1];
 
  return 0;
}

/*funcition to output */
static void outp()
{
  const char *t = "X O";
  int i, j;
  for (i = 0; i < 3; i++, putchar('\n'))
  for (j = 0; j < 3; j++) printf("%c ", t[ board[i][j] + 1 ]);
  printf("-----\n");
}

static int kitest(int val, int depth)
{
  int i, j, score;
  int best = -1, changed = 0;
 
  if ((score = checkwin())) return (score == val) ? 1 : -1;
 
  for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) 
  {
    if (board[i][j]) continue;
    
    changed = board[i][j] = val;
    score = -kitest(-val, depth + 1);
    board[i][j] = 0;
 
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

/*funcition for gameplan*/
static const char* game(int user)
{
  int i, j, k, move, win = 0;
  for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) board[i][j] = 0;
 
  printf("Board postions are numbered so:\n1 2 3\n4 5 6\n7 8 9\n");
  printf("You have O, I have X.\n\n");
  for (k = 0; k < 9; k++, user = !user) 
  {
    while(user) 
	  {
      printf("your move: ");
      if (!scanf("%d", &move)) 
      {
        scanf("%*s");
        continue;
      }
    
      if (--move < 0 || move >= 9) continue;
      if (board[i = move / 3][j = move % 3]) continue;
 
      board[i][j] = 1;
      break;
    }
    if (!user) 
    {
      if (!k)
      {
        best_i = rand() % 3;
        best_j = rand() % 3;
      } else
      
      kitest(-1, 0);
      board[best_i][best_j] = -1;
      printf("My move: %d\n", best_i * 3 + best_j + 1);
    }
    
    outp();
    if ((win = checkwin())) 
    return win == 1 ? "You win.\n\n": "I win.\n\n";
  }
	return "A draw.\n\n";
}