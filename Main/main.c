#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Modulos/GraphLib.h"

int main()
{

    Grafo *G = criarGrafo();

    char *caminho;

    G = leitorArquivo(G, "../inputs/grafo_1.txt");

    caminho = dfs(G, 'A', 'W');

    if(caminho == NULL){
        printf("\nNao existe caminho ate esse Vertice\n\n");
        exit(0);
    }
    for (int i = 0; caminho[i] != '\0'; i++)
    {
        printf("%c - ", caminho[i]);
    }
    printf("\n");

    liberarMemoriaGrafo(G);
    liberarMemoriaDfs(caminho);
}