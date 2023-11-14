#include <stdio.h>
#include <stdlib.h>
#include "GraphLib.h"

int verificaConexao(Grafo *grafo, char vertice,char verticeAdjacente){
    Celula *iterador;
    int chave;

    chave = buscarVertice(grafo,vertice);
    iterador = grafo->array[chave].primeiro;

    while(iterador){

        if(iterador->verticeAdjacente == verticeAdjacente){

            return 1;
        }

        iterador = iterador->proximo;
    }

    return 0;
}

char *caminhoVolta(Grafo *grafo, char *caminhoInicial, char verticeInicial, int indiceVerticeAlvo){

    int indiceDireita = indiceVerticeAlvo;
    int indiceEsquerda = indiceVerticeAlvo - 1;
    int existeAresta;
    int tamanhoCaminhoFinal = 0;

    Pilha *pilha = criarPilha();

    push(pilha,caminhoInicial[indiceDireita]);
    tamanhoCaminhoFinal++;

    while(caminhoInicial[indiceDireita] != verticeInicial){
        
        existeAresta = verificaConexao(grafo,caminhoInicial[indiceEsquerda],caminhoInicial[indiceDireita]);

        if(existeAresta){
            push(pilha,caminhoInicial[indiceEsquerda]);
            indiceDireita = indiceEsquerda;
            indiceEsquerda--;
            tamanhoCaminhoFinal++;
        }else{

            indiceEsquerda--;
        }
    }

    char *caminhoFinal = (char*)malloc(tamanhoCaminhoFinal * sizeof(char));
    int i = 0;

    while(pilhaVazia(pilha)){

        caminhoFinal[i++] = pop(pilha);
    }

    return caminhoFinal;
}

char *dfs(Grafo *grafo, char verticeInicial, char verticeAlvo)
{

    Pilha *pilha = criarPilha();

    Celula *iterador;

    int visitados[26] = {0};

    int chaveVertice;

    int indiceVisitado;

    int indiceCaminho = 0;

    char *caminhoFinal;

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

            caminhoFinal = caminhoVolta(grafo,caminho,verticeInicial,indiceCaminho);

            return caminhoFinal;
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