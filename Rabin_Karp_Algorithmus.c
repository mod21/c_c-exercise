#include <stdio.h>
#include <string.h>

void search(char pat[], char txt[], int q);

int main()
{
    char txt[] = "NERDS FOR NERDS";
    char pat[] = "NERD";
    
    if ((strlen(txt) <= strlen(pat)) && ((strlen (txt) && strlen (pat)) != 0))
    {
        search(pat, txt, q);
    }
    else{printf("wrong parameter \n"};
    
	return 0;
}

void search(char pat[], char txt[], int q)
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
