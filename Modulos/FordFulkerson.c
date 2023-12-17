#include <stdio.h>
#include <stdlib.h>
#include "GraphLib.h"

Grafo *inverterAresta(Grafo *grafo, char verticeOrigem, char verticeAdjacente)
{

    grafo = removerAresta(grafo, verticeOrigem, verticeAdjacente);

    return grafo;
}

Grafo *gerarArestaVolta(Grafo *grafo, char verticeOrigem, char verticeDestino, int peso){

   int chave = buscarVertice(grafo,verticeOrigem);
   Celula *iterador;

   if(chave != -1){

    iterador = grafo->array[chave].primeiro;

    while (iterador)
    {
        if(iterador->verticeAdjacente == verticeDestino){

            iterador->peso = iterador->peso + peso;
            break;
        }
        iterador = iterador->proximo;
    }

    grafo = adicionarAresta(grafo,verticeOrigem,verticeDestino,peso);
    
   }else{

    grafo = adicionarAresta(grafo,verticeOrigem,verticeDestino,peso);
   }

 return grafo;
}

Grafo *fordFulkerson(Grafo *grafo, char verticeOrigem, char verticeDestino)
{
    int fluxoMaximo = 0;

    int iteradorOrigem;

    int chave;

    int gargalo = 0;

    int capacidadeAtual;

    Celula *buscarVerticeAdjacente;

    char *caminhoAumentante = dfs(grafo, verticeOrigem, verticeDestino);

    while (caminhoAumentante)
    {
        // Busca a menor capacidade atual do caminho.
        for (int i = 1; caminhoAumentante[i] != '\0'; i++)
        {
            
            iteradorOrigem = i - 1;
            chave = buscarVertice(grafo, caminhoAumentante[iteradorOrigem]);

            buscarVerticeAdjacente = grafo->array[chave].primeiro;

            while (1)
            {

                if (buscarVerticeAdjacente->verticeAdjacente == caminhoAumentante[i])
                {

                    capacidadeAtual = buscarVerticeAdjacente->peso;
                    break;
                }

                buscarVerticeAdjacente = buscarVerticeAdjacente->proximo;
            }

            if (gargalo == 0)
            {
                gargalo = capacidadeAtual;
            }
            else if (gargalo > capacidadeAtual)
            {

                gargalo = capacidadeAtual;
            }
        }

        // adiciona o gargalo no fluxo maximo do grafo.
        fluxoMaximo = fluxoMaximo + gargalo;

        // Subtrai o gargalo no peso e adiciona no fluxo elemental das arestas do caminho.
        for (int i = 1; caminhoAumentante[i] != '\0'; i++)
        {

            iteradorOrigem = i - 1;

            chave = buscarVertice(grafo, caminhoAumentante[iteradorOrigem]);

            buscarVerticeAdjacente = grafo->array[chave].primeiro;

            while (1)
            {

                if (buscarVerticeAdjacente->verticeAdjacente == caminhoAumentante[i])
                {

                    buscarVerticeAdjacente->peso = (buscarVerticeAdjacente->peso - gargalo);

                    //cria-se a aresta de volta.
                    grafo = gerarArestaVolta(grafo,buscarVerticeAdjacente->verticeAdjacente,caminhoAumentante[iteradorOrigem],gargalo); 


                    if (buscarVerticeAdjacente->peso == 0)
                    {

                        grafo = inverterAresta(grafo, caminhoAumentante[iteradorOrigem], caminhoAumentante[i]);
                    }
                    break;
                }

                buscarVerticeAdjacente = buscarVerticeAdjacente->proximo;
            }
        }    

        
        caminhoAumentante = dfs(grafo, verticeOrigem, verticeDestino);//Um novo caminho e passado.
        
        gargalo = 0;//Reinicia gargalo para o novo caminho.
    }
    
    printf("\nFluxo maximo do grafo: [%d]\n\n",fluxoMaximo);
    
    imprimirGrafo(grafo);
    
    return grafo;
}
