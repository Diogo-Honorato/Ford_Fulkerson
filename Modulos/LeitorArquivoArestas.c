#include<stdio.h>
#include<stdlib.h>
#include"GraphLib.h"

Grafo *LeitorArquivo(Grafo *grafo,const char *nomeArquivo)
{
    char **matrizConexoes = arquivoArestas(nomeArquivo);
    int tamanhoMatriz = contadorLinha(nomeArquivo);
    int i = 0;

    for(i = 0; i < tamanhoMatriz; i++)
    {
        grafo = adicionarAresta(grafo,matrizConexoes[i][0],matrizConexoes[i][1],matrizConexoes[i][2]); 
    }

    return grafo;
}
