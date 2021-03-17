#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define N 10

int acheMaximo(int vetor[], int inicio, int fim);

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

    printf("Max: %d", acheMaximo(vetor, 0, N));

    return 0;
}

int acheMaximo(int vetor[], int inicio, int fim)
{
    int esquerda, direita, meio, max = 0;

    if (fim - inicio == 1)
    {
        return vetor[inicio];
    }

    meio = (inicio + fim) / 2;
    esquerda = acheMaximo(vetor, inicio, meio);
    direita = acheMaximo(vetor, meio, fim);

    if (esquerda > direita)
    {
        max = esquerda;
    }
    else
    {
        max = direita;
    }

    return max;
}
