#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulos/GraphLib.h"

int main(int argc, char *argv[]) {

    char source,sink;

    if (argc == 1) {

        source = 'S';
        sink = 'T';
        printf("\nSource: %c\nSink: %c\n", source, sink);

    } else if (argc == 3) {

        source =(char)*argv[1];
        sink = (char)*argv[2];
        printf("Source: %c\nSink: %c\n", source, sink);

    } else{
        printf("Uso: 'make run source=VERTICE sink=VERTICE' ou 'make just-run'\n");
        return 1;
    }

    Grafo *G = criarGrafo();

    G = leitorArquivo(G, "testes/input.txt"); 
    
    G = fordFulkerson(G,source,sink);
    
    liberarMemoriaGrafo(G);

    return 0;
}
    
