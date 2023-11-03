#include <stdio.h>
#include <stdlib.h>
#include "../Modulos/GraphLib.h"

int main()
{

    Grafo *G = criarGrafo();

    G = LeitorArquivo(G, "../inputs/grafo_1.txt");

    imprimirGrafo(G);

    liberarMemoria(G);
}