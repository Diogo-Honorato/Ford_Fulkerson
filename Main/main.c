#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Modulos/GraphLib.h"

int main()
{
    
    Grafo *G = criarGrafo();

    char *caminho;

    G = leitorArquivo(G, "../inputs/grafo_1.txt");


    caminho = dfs(G,'S','T');

    for(int i = 0; i < 26; i++){

        if(caminho[i] != '\0'){

            printf("%c - ",caminho[i]);
        }
    }printf("\n");


    liberarMemoriaGrafo(G);
    liberarMemoriaDfs(caminho);  
}