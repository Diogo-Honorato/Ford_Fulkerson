#include <stdio.h>
#include <stdlib.h>
#include "GraphLib.h"

char *dfs(Grafo *grafo, char verticeInicial, char verticeAlvo)
{

    Pilha *pilha = criarPilha();

    Celula *iterador;

    int visitados[26] = {0};

    int chaveVertice;

    int indiceVisitado;

    int indiceCaminho = 0;

    char *caminho = (char*)malloc(26 * sizeof(char));

    for(int i = 0; i < 26; i++){
        caminho[i] = '-';
    }


    push(pilha, verticeInicial);

    while (pilhaVazia(pilha))
    {
        char verticeRemovido = pop(pilha);

        if (verticeRemovido == verticeAlvo)
        {
            indiceVisitado = verticeRemovido - 'A';
            visitados[indiceVisitado] = 1;

            caminho[indiceCaminho] = verticeRemovido;

            return caminho;
            break;
        }

        indiceVisitado = verticeRemovido - 'A';

        visitados[indiceVisitado] = 1;

        caminho[indiceCaminho++] = verticeRemovido;

        chaveVertice = buscarVertice(grafo, verticeRemovido);

        // detalhe para tratar vertices que nao possuem arestas de saída.
        if (chaveVertice == -1)
        {
            continue;
        }

        iterador = grafo->array[chaveVertice].primeiro;

        while (iterador)
        {
            indiceVisitado = iterador->verticeAdjacente - 'A';

            if (visitados[indiceVisitado] == 0)
            {
                push(pilha, iterador->verticeAdjacente);
            }

            iterador = iterador->proximo;
        }
    }

    liberarMemoriaPilha(pilha);

    return NULL;
}

void liberarMemoriaDfs(char *caminhoDfs){

    free(caminhoDfs);
}