#include<stdio.h>
#include<stdlib.h>
#include"GraphLib.h"

Pilha *criarPilha(){

    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));

    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
    pilha->verticeOrigem = '0';

    return pilha;
}

Celula *pop(Pilha *pilha){

    Celula *removeItem = pilha->primeiro;
    
    Celula *lixo;

    lixo->peso = removeItem->peso;
    lixo->verticeAdjacente = removeItem->verticeAdjacente;
    lixo->proximo = NULL;
    
    pilha->primeiro = pilha->primeiro->proximo;

    free(removeItem);

    return lixo;
}

void push(Pilha *pilha, char vertice, int peso){

    Celula *novaCelula = alocarCelula(vertice,peso);

    if(pilha->primeiro == NULL){

        pilha->primeiro = novaCelula;
        pilha->ultimo = novaCelula;
    
    }else{

        novaCelula->proximo = pilha->primeiro;
        pilha->primeiro = novaCelula;
    }
}

void liberarPilha(Pilha *pilha)
{

    Celula *atual = pilha->primeiro;

    while (atual)
    {
        Celula *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(pilha);
}