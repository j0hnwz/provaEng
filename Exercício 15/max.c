#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define N 10

int acheMaximo(int vetor[], int tam);

int main()
{
    int vetor[N];
    int i;

    srand(time(0));

    for (i = 0; i < N; i++)
        vetor[i] = rand() % 100;

    printf("Vetor = { ");

    for (i = 0; i < N; i++)
        printf("%d ", vetor[i]);

    printf("}\n");

    printf("Max: %d", acheMaximo(vetor, N));

    return 0;
}

int acheMaximo(int vetor[], int tam)
{
    int max = 0;

    if ( tam == 1)
    {
        return vetor[tam - 1];
    }

    max = acheMaximo(vetor, tam - 1);

    return (vetor[tam-1] > max) ? vetor[tam-1] : max;
}
