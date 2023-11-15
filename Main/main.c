#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Modulos/GraphLib.h"

int main()
{

    Grafo *G = criarGrafo();

    leitorArquivo(G, "../inputs/grafo_1.txt");

    imprimirGrafo(G);

    liberarMemoriaGrafo(G);
}