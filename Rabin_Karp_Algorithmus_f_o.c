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