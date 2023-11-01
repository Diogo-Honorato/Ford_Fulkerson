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

    Celula *primeiro;
    Celula *ultimo;

} Lista;

typedef struct Grafo
{

    Lista *array;

} Grafo;

Grafo *criarGrafo(Grafo *grafo, int tamanho)
{

    grafo = (Grafo *)malloc(sizeof(Grafo));

    if (grafo == NULL)
    {
        perror("Falha na alocação de memória");
        exit(1);
    }

    grafo->array = (Lista *)malloc(tamanho * sizeof(Lista));

    for (int i = 0; i < tamanho; i++)
    {

        grafo->array[i].primeiro = NULL;

        grafo->array[i].ultimo = NULL;
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

int gerarChave(char verticeOrigem, int tamanho)
{

    int numeroInteiro = verticeOrigem - 'A';

    return numeroInteiro % tamanho;
}

int buscarVertice(Grafo *grafo, char vertice){
    
    // Fazer um if-else para verificar se existe ou nao o vertice, se existe retorne o indice se nao retorne 0.

}

void adicionarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta, int tamanho)
{

    int condicaoChave;
    int chave = gerarChave(verticeOrigem, tamanho);

    Celula *novaCelula = alocarCelula(verticeDestino,pesoAresta);

    // Verificar se o vertice de origem em questao ja possui uma lista.

    condicaoChave = buscarVertice(grafo,verticeOrigem);
    
    if (condicaoChave)
    {
        grafo->array[condicaoChave].ultimo->proximo = novaCelula;
        grafo->array[condicaoChave].ultimo = novaCelula;
    }
    else
    {
        while (grafo->array[chave].primeiro != NULL)
        {
            chave = gerarChave(verticeOrigem + 1, tamanho);
        }

        grafo->array[chave].primeiro = novaCelula;
        grafo->array[chave].ultimo = novaCelula;
    }
}