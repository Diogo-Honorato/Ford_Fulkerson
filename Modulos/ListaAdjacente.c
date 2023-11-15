#include <stdio.h>
#include <stdlib.h>
#include "GraphLib.h"

// Variavel global estatica para controlar o tamanho do array
static int tamanhoArray = 11;


Grafo *criarGrafo()
{

    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));

    grafo->quantidadeVertices = 0;

    grafo->array = (Lista *)malloc(tamanhoArray * sizeof(Lista));

    for (int i = 0; i < tamanhoArray; i++)
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
    novaCelula->verticeAdjacente = verticeAdjacente;
    novaCelula->proximo = NULL;
    novaCelula->anterior = NULL;

    if (novaCelula == NULL)
    {
        perror("Falha na alocação de memória");
        exit(1);
    }

    return novaCelula;
}

void liberarMemoriaGrafo(Grafo *grafo)
{
    for (int i = 0; i < tamanhoArray; i++)
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

    free(grafo);
}

int gerarChave(char verticeChave)
{

    int numeroInteiro = verticeChave - 'A';

    return numeroInteiro % tamanhoArray;
}

int fatorCargaArray(Grafo *grafo)
{

    float fatorCarga = (grafo->quantidadeVertices + 1) / tamanhoArray;

    if (fatorCarga > 0.70)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}

int calcularNovoTamanhoArray()
{

    int verificaPrimo = 0;

    while (verificaPrimo != 2)
    {
        verificaPrimo = 0;

        tamanhoArray++;

        for (int i = 1; i <= tamanhoArray; i++)
        {
            int resultado = tamanhoArray % i;

            if (resultado == 0)
            {
                verificaPrimo++;
            }
        }
    }

    return tamanhoArray;
}

void gerarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta)
{

    char verticeChave = verticeOrigem;

    int chave = gerarChave(verticeOrigem);

    Celula *novaCelula = alocarCelula(verticeDestino, pesoAresta);

    // Verifica se o vertice em questao ja existe ou nao no array.
    while (grafo->array[chave].verticeOrigem != '0' && grafo->array[chave].verticeOrigem != '1' && grafo->array[chave].verticeOrigem != verticeOrigem)
    {
        verticeChave = verticeChave + 1;

        chave = gerarChave(verticeChave);
    }

    // Se existir.
    if (grafo->array[chave].verticeOrigem == verticeOrigem)
    {

        grafo->array[chave].ultimo->proximo = novaCelula;
        novaCelula->anterior = grafo->array[chave].ultimo;
        grafo->array[chave].ultimo = novaCelula;
    }
    else // Se nao existir.
    {

        grafo->array[chave].verticeOrigem = verticeOrigem;
        grafo->array[chave].primeiro = novaCelula;
        grafo->array[chave].ultimo = novaCelula;
        grafo->quantidadeVertices++;
    }
}

Grafo *aumentarTamanhoArray(Grafo *grafo)
{
    int tamanhoAnteriorArray = tamanhoArray;

    tamanhoArray = calcularNovoTamanhoArray();

    Grafo *novoGrafo = criarGrafo();

    Celula *iterador;

    for (int i = 0; i < tamanhoAnteriorArray; i++)
    {

        if (grafo->array[i].verticeOrigem != '0' && grafo->array[i].verticeOrigem != '1')
        {
            iterador = grafo->array[i].primeiro;

            while (iterador)
            {

                gerarAresta(novoGrafo, grafo->array[i].verticeOrigem, iterador->verticeAdjacente, iterador->peso);

                iterador = iterador->proximo;
            }
        }
    }

    // libera a memoria do grafo antigo.
    for (int i = 0; i < tamanhoAnteriorArray; i++)
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
    free(grafo);

    return novoGrafo;
}

Grafo *adicionarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta)
{

    // Verificar primeiro se o array esta com o fator de carga menor que 70%.
    if (fatorCargaArray(grafo))
    {
        grafo = aumentarTamanhoArray(grafo);
    }

    gerarAresta(grafo, verticeOrigem, verticeDestino, pesoAresta);

    return grafo;
}

void imprimirGrafo(Grafo *grafo)
{
    Celula *iterador;

    for (int i = 0; i < tamanhoArray; i++)
    {

        if (grafo->array[i].verticeOrigem != '0' && grafo->array[i].verticeOrigem != '1')
        {
            printf("\n");

            printf("%c: ", grafo->array[i].verticeOrigem);

            iterador = grafo->array[i].primeiro;

            while (iterador)
            {
                printf("[%c,%d] ", iterador->verticeAdjacente, iterador->peso);

                iterador = iterador->proximo;
            }
            printf("\n\n");
        }
    }
}

int buscarVertice(Grafo *grafo, char vertice)
{

    int chave = gerarChave(vertice);

    char iteradorVertice = vertice;

    while (grafo->array[chave].verticeOrigem != vertice)
    {

        if (grafo->array[chave].verticeOrigem == '0')
        {
            return -1;
            break;
        }

        iteradorVertice = iteradorVertice + 1;

        chave = gerarChave(iteradorVertice);
    }

    return chave;
}

Grafo *removerAresta(Grafo *grafo, char vertice, char verticeAdajcente)
{

    int chave = buscarVertice(grafo, vertice);

    Celula *iterador = grafo->array[chave].primeiro;

    while (iterador)
    {

        if (iterador->verticeAdjacente == verticeAdajcente)
        {

            if (iterador->anterior == NULL)
            {

                grafo->array[chave].primeiro = iterador->proximo;

                if (grafo->array[chave].primeiro != NULL)
                {

                    grafo->array[chave].primeiro->anterior = NULL;
                }
                else
                {
                    grafo->array[chave].ultimo = NULL; // Se não há próximo, é o único elemento na lista
                    grafo->array[chave].verticeOrigem = '1';
                    grafo->quantidadeVertices--;
                }

                free(iterador);
            }
            else if (iterador->proximo == NULL)
            {

                grafo->array[chave].ultimo = grafo->array[chave].ultimo->anterior;
                grafo->array[chave].ultimo->proximo = NULL;

                free(iterador);
            }
            else
            {

                iterador->proximo->anterior = iterador->anterior;
                iterador->anterior->proximo = iterador->proximo;

                free(iterador);
            }
        }

        iterador = iterador->proximo;
    }

    return grafo;
}