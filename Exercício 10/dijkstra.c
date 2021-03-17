#include <stdio.h>
#include <conio.h>

#define MAX 999
#define N 5

void imprime(int noInicial, int distancia[N], int anterior[N])
{
    int i, j;

    printf("-------------------\nCodigo - Cidade\n-------------------\n0 - Sao paulo \n1 - Riberao preto\n2 - Pocos de Caldas\n3 - Campinas\n4 - Rio de Janeiro\n-------------------\n");

    for (i = 0; i < N; i++)
    {
        //(i != noInicial) ? printf("De %d para  %d\nCusto: %d\n", noInicial, i, distancia[i]) : printf("De %d para %d\nCusto: - \n", noInicial, i);
        if (i != noInicial)
        {

            printf("De %d para %d: ", noInicial, i);
            printf("%d", noInicial);

            j = i;

            do
            {

                j = anterior[j];
                if (j != 0)
                {

                    printf(" -> %d", j);
                }
                else
                {
                    printf(" -> %d\n", i);
                }

            } while (j != noInicial);

            printf("Custo: %d\n", distancia[i]);
        }
        else
        {
            printf("De %d para %d: Nao existe \nCusto: - \n", noInicial, i);
        }
    }
}

void dijkstra(int cidades[N][N])
{

    int custo[N][N], distancia[N], anterior[N], visitado[N];
    int contador, distanciaMin, proximono, i, j;
    int noInicial = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (cidades[i][j] == 0)
            {
                custo[i][j] = MAX;
            }
            else
            {
                custo[i][j] = cidades[i][j];
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        distancia[i] = custo[noInicial][i];
        anterior[i] = noInicial;
        visitado[i] = 0;
    }

    distancia[noInicial] = 0;
    visitado[noInicial] = 1;
    contador = 1;

    while (contador < N - 1)
    {
        distanciaMin = MAX;

        for (i = 0; i < N; i++)
        {
            if (distancia[i] < distanciaMin && !visitado[i])
            {
                distanciaMin = distancia[i];
                proximono = i;
            }
        }

        visitado[proximono] = 1;
        for (i = 0; i < N; i++)
        {

            if (!visitado[i])
            {

                if (distanciaMin + custo[proximono][i] < distancia[i])
                {
                    distancia[i] = distanciaMin + custo[proximono][i];
                    anterior[i] = proximono;
                }
            }
        }
        contador++;
    }

    imprime(noInicial, distancia, anterior);
}

int main()
{

    // Matriz de adjacência do grafo das cidades
    int cidades[N][N] = {
        {0, 2, 5, 0, 0},
        {0, 0, 4, 3, 0},
        {0, 0, 0, 0, 6},
        {7, 0, 0, 0, 0},
        {4, 0, 0, 0, 0}};

    dijkstra(cidades);

    return 0;
}
