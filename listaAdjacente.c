#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

typedef struct Celula{

    char vertice;
    int peso;
    struct Celula *proximo;

}Celula;

typedef struct Lista{

    Celula *primeiro;
    Celula *ultimo;

}Lista;

typedef struct Grafo{
    
    Lista *array;

}Grafo;


Grafo *criarGrafo(Grafo *grafo, int tamanho){

    grafo = (Grafo*)malloc(sizeof(Grafo));

    if (grafo == NULL) {
        perror("Falha na alocação de memória");
        exit(1);
    }

    grafo->array = (Lista*)malloc(tamanho * sizeof(Lista));

    for(int i = 0; i < tamanho; i++){

        grafo->array[i].primeiro = NULL;
   
        grafo->array[i].ultimo = NULL;
    }

    return grafo;
}

Celula *alocarCelula(char verticeAdjacente,int peso){

    Celula *novaCelula = (Celula*)malloc(sizeof(Celula));

    novaCelula->peso = peso;
    novaCelula->vertice = verticeAdjacente;
    novaCelula->proximo = NULL;

    if (novaCelula == NULL) {
        perror("Falha na alocação de memória");
        exit(1);
    }

    return novaCelula;
}


int gerarChave(char verticeOrigem, int tamanho){

    int numeroInteiro = verticeOrigem - 'A';

    return numeroInteiro % tamanho;
}

void adicionarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta,int tamanho){
    

}