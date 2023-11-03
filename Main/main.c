#include <stdio.h>
#include <stdlib.h>
#include "../Modulos/GraphLib.h"

int main(){

    Grafo *G = criarGrafo();

    char matriz[8][3] = {{'A','B','8'},{'Z','A','2'},{'V','Z','3'},{'R','Y','9'},{'B','C','7'},{'T','I','1'},{'C','R','5'},{'D','E','4'}};


    for(int i = 0; i < 8; i++){

        G = adicionarAresta(G,matriz[i][0],matriz[i][1],matriz[i][2]);
    }

    imprimirGrafo(G);

    liberarMemoria(G);
}