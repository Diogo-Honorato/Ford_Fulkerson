#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "GraphLib.h"

int contadorLinha(const char *nomeArquivo)
{
    FILE *file;
    int numeroLinhas = 0;
    char verticeOrigem, verticeAdjacente;
    int pesoAresta;


    file = fopen(nomeArquivo, "r");

    if (file == NULL)
    {
        printf("\nERRO AO ABRIR O ARQUIVO: FUNÇAO: 'contadorLinha'\n\n");
        exit(0);
    }

    while (fscanf(file, " %c %c %d", &verticeOrigem, &verticeAdjacente, &pesoAresta) == 3)
    {
        numeroLinhas++;
    }

    fclose(file);

    return numeroLinhas;
}

char **arquivoArestas(const char *nomeArquivo)
{
    FILE *fileTxt;
    int i = 0;

    int numeroConexoes = contadorLinha(nomeArquivo);

    char **edges = (char **)malloc(numeroConexoes * sizeof(char *));

    for (int j = 0; j < numeroConexoes; j++)
    {
        edges[j] = (char *)malloc(3 * sizeof(char));
    }

    fileTxt = fopen(nomeArquivo, "r");

    if (fileTxt == NULL)
    {
        printf("\nERRO AO ABRIR O ARQUIVO: FUNÇAO 'arquivoArestas'\n\n");
        exit(0);
    }

    while (fscanf(fileTxt," %c %c %hhd",&edges[i][0],&edges[i][1],&edges[i][2]) == 3)
    {
        i++;
    }

    fclose(fileTxt);

    return edges;
}
