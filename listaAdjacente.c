#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

typedef struct Celula
{

    char vertice;
    int peso;
    struct Celula *proximo;

} Celula;

typedef struct Lista
{

    char verticeOrigem;
    Celula *primeiro;
    Celula *ultimo;

} Lista;

typedef struct Grafo
{

    Lista *array;

} Grafo;

Grafo *criarGrafo(int tamanho)
{

    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));

    grafo->array = (Lista *)malloc(tamanho * sizeof(Lista));

    for (int i = 0; i < tamanho; i++)
    {

        grafo->array[i].primeiro = NULL;

        grafo->array[i].ultimo = NULL;

        grafo->array[i].verticeOrigem = '0';
    }

    return grafo;
}

Celula *alocarCelula(char verticeAdjacente, int peso)
{

    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));

    novaCelula->peso = peso;
    novaCelula->vertice = verticeAdjacente;
    novaCelula->proximo = NULL;

    if (novaCelula == NULL)
    {
        perror("Falha na alocação de memória");
        exit(1);
    }

    return novaCelula;
}

int gerarChave(char verticeChave, int tamanho)
{

    int numeroInteiro = verticeChave - 'A';

    return numeroInteiro % tamanho;
}

void adicionarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta, int tamanho)
{

    char verticeChave = verticeOrigem;

    int chave = gerarChave(verticeOrigem, tamanho);

    Celula *novaCelula = alocarCelula(verticeDestino, pesoAresta);

    // Verificar primeiro se a hash esta com o fator de carga maior que 70%.

    // Verificar se o vertice de origem em questao ja possui uma lista.

    while (grafo->array[chave].verticeOrigem != '0' && grafo->array[chave].verticeOrigem != verticeOrigem)
    {
        verticeChave = verticeChave + 1;

        chave = gerarChave(verticeChave, tamanho);
    }

    if (grafo->array[chave].verticeOrigem == verticeOrigem)
    {

        grafo->array[chave].ultimo->proximo = novaCelula;
        grafo->array[chave].ultimo = novaCelula;
    }
    else
    {

        grafo->array[chave].verticeOrigem = verticeOrigem;
        grafo->array[chave].primeiro = novaCelula;
        grafo->array[chave].ultimo = novaCelula;
    }
}

void liberarMemoria(Grafo *grafo, int tamanho)
{
    for (int i = 0; i < SIZE; i++)
    {
        Celula *atual = grafo->array[i].primeiro;
        while (atual)
        {
            Celula *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    free(grafo->array);
}


void imprimirGrafo(Grafo *grafo, int tamanho)
{
    Celula *iterador;

    for (int i = 0; i < tamanho; i++)
    {

        if (grafo->array[i].verticeOrigem != '0')
        {
            printf("\n");

            printf("%c: ", grafo->array[i].verticeOrigem);

            iterador = grafo->array[i].primeiro;

            while (iterador)
            {

                printf("[%c,%d] ", iterador->vertice, iterador->peso);

                iterador = iterador->proximo;
            }
            printf("\n\n");
        }
    }
}