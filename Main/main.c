#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Modulos/GraphLib.h"

int main()
{
    Grafo *G = criarGrafo();

    G = leitorArquivo(G, "../testes/input.txt"); 
    
    G = fordFulkerson(G,'S','T');
    
    liberarMemoriaGrafo(G);
    
}