#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

#ifdef WIN32
#define timer Sleep(2000);
#else 
#define timer usleep(200000);
#endif

static void game (int, int); // funcition game
static void outp (void *, unsigned int, unsigned int); //Output funcition
static void evo (void *, unsigned int, unsigned int);  //funcition evolution


int main()
{
  unsigned int width = 30, height = 30;
  game(width, height);
}

// funcition game
static void game(int width, int height)
{
  unsigned univ[height][width];
  //Random start value
  for (int x = 0; x < width; x++)
  {
    for (int y = 0; y < height; y++) univ[y][x] = rand() < RAND_MAX / 5 ? 1 : 0; 
  }

  //funcition flow path  
  while (1) 
  {
    outp (univ, width, height);
    evo (univ, width, height);
    usleep(200000);
  }
}

//Output funcition
static void outp (void *u, unsigned int width, unsigned int height)
{
  int (*univ)[width] = u;

  printf("\033[H");

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++) printf(univ[y][x] ? "\033[07m  \033[m" : "  ");
    printf("\033[E");
  }
  fflush(stdout);
}

//funcition evolution
static void evo(void *u, unsigned int width, unsigned int height)
{
  unsigned (*univ)[width] = u;
  unsigned new[height][width];
 
  for (int y = 0; y < height; y++) for (int x = 0; x < width; x++) 
  {
    int n = 0;
    for (int y1 = y - 1; y1 <= y + 1; y1++)
    {
      for (int x1 = x - 1; x1 <= x + 1; x1++)
      {
        if (univ[(y1 + height) % height][(x1 + width) % width])	n++;
      } 
    }
    if (univ[y][x]) n--;
    new[y][x] = (n == 3 || (n == 2 && univ[y][x]));
  }
  
  for (int y = 0; y < height; y++) for (int x = 0; x < width; x++) univ[y][x] = new[y][x];
}