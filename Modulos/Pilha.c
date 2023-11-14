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

char pop(Pilha *pilha){

    Celula *removeItem = pilha->primeiro;
    
    char lixo;

    lixo = removeItem->verticeAdjacente;
      
    pilha->primeiro = pilha->primeiro->proximo;

    free(removeItem);

    return lixo;
}

void push(Pilha *pilha, char vertice){

    Celula *novaCelula = alocarCelula(vertice,0);

    if(pilha->primeiro == NULL){

        pilha->primeiro = novaCelula;
        pilha->ultimo = novaCelula;
    
    }else{

        novaCelula->proximo = pilha->primeiro;
        pilha->primeiro = novaCelula;
    }
}

int pilhaVazia(Pilha *pilha){

    if(pilha->primeiro == NULL){
        
        return 0;
    }

    return 1;
}

void liberarMemoriaPilha(Pilha *pilha)
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