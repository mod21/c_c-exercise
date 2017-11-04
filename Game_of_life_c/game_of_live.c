#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void game (int, int); // Funktion Spielablauf
void outp (void *, unsigned int, unsigned int); //Output Funktion
void evo (void *, unsigned int, unsigned int);  //Funktion Evulution


int main(int c, char **v)
{
  unsigned int b = 30, h = 30;
  /*if (c > 1) w = atoi(v[1]);
  if (c > 2) h = atoi(v[2]);
  if (w <= 0) w = 30;
  if (h <= 0) h = 30;*/
  game(b, h);
}

// Funktion Spielablauf
void game(int b, int h)
{
  unsigned univ[h][b];
  //Random Strartwerte
  for (int x = 0; x < b; x++)
  {
    for (int y = 0; y < h; y++) univ[y][x] = rand() < RAND_MAX / 5 ? 1 : 0; 
  }

//Game durchlauf  
  while (1) 
  {
    //Ausgabe Aktuelle Matrix
    outp (univ, b, h);
    //Entwicklung
    evo (univ, b, h);
    //Timingfunktion
    usleep(200000);
  }
}

//Output Funktion
void outp (void *u, unsigned int b, unsigned int h)
{
  int (*univ)[b] = u;

  printf("\033[H");

  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < b; x++) printf(univ[y][x] ? "\033[07m  \033[m" : "  ");
    printf("\033[E");
  }
  fflush(stdout);
}

//Funktion Evulution
void evo(void *u, unsigned int b, unsigned int h)
{
  unsigned (*univ)[b] = u;
  unsigned new[h][b];
 
  for (int y = 0; y < h; y++) for (int x = 0; x < b; x++) 
  {
    int n = 0;
    for (int y1 = y - 1; y1 <= y + 1; y1++)
    {
      for (int x1 = x - 1; x1 <= x + 1; x1++)
      {
        if (univ[(y1 + h) % h][(x1 + b) % b])	n++;
      } 
    }
    if (univ[y][x]) n--;
    new[y][x] = (n == 3 || (n == 2 && univ[y][x]));
  }
  
  for (int y = 0; y < h; y++) for (int x = 0; x < b; x++) univ[y][x] = new[y][x];
}