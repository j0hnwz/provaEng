#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define N 40000

int acheMaximo1(int vetor[], int tam);
int acheMaximo2(int vetor[], int inicio, int fim);
float calculaTempo(int vetor[]);

int main()
{
    int vetor[N];
    int i, j;

    srand(time(0));

    for (i = 0; i < N; i++)
        vetor[i] = rand() % 100;

    for (j = 0; j < 10; j++)
        calculaTempo(vetor);

    return 0;
}

int acheMaximo1(int vetor[], int tam)
{
    int max = 0;

    if (tam == 1)
    {
        return vetor[tam - 1];
    }

    max = acheMaximo1(vetor, tam - 1);

    return (vetor[tam - 1] > max) ? vetor[tam - 1] : max;
}

int acheMaximo2(int vetor[], int inicio, int fim)
{
    int esquerda, direita, meio, max = 0;

    if (fim - inicio == 1)
    {
        return vetor[inicio];
    }

    meio = (inicio + fim) / 2;
    esquerda = acheMaximo2(vetor, inicio, meio);
    direita = acheMaximo2(vetor, meio, fim);

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

float calculaTempo(int vetor[])
{

    clock_t t;

    t = clock();
    printf("Max: %d ", acheMaximo1(vetor, N));
    t = clock() - t;
    printf("V[%d] - Metodo 1 - %f segundos\n", N, ((float)t) / CLOCKS_PER_SEC);

    clock_t t2;

    t2 = clock();
    printf("Max: %d ", acheMaximo2(vetor, 0, N));
    t2 = clock() - t2;
    printf("Vetor[%d] - Metodo 2 - %f segundos.\n", N, ((float)t2) / CLOCKS_PER_SEC);
}