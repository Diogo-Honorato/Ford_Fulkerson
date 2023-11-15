#include <stdio.h>
#include <stdlib.h>
#include "GraphLib.h"

Grafo *inverterAresta(Grafo *grafo, char verticeOrigem, char verticeAdjacente,int peso){

    grafo = removerAresta(grafo,verticeOrigem,verticeAdjacente);

    grafo = adicionarAresta(grafo,verticeAdjacente,verticeOrigem,peso);

    return grafo;
}
/*
Grafo *fordFulkerson(){
    
}
*/