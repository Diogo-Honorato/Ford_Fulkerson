#ifndef GRAPH_LIB
#define GRAPH_LIB


typedef struct Celula
{

    char verticeAdjacente;
    int peso;
    struct Celula *proximo;

} Celula;

typedef struct Lista
{

    char verticeOrigem;
    Celula *primeiro;
    Celula *ultimo;

} Lista;

typedef struct Grafo
{
    Lista *array;
    float quantidadeVertices;

} Grafo;


//ListaAdjacente.c
Grafo *criarGrafo();

Celula *alocarCelula(char verticeAdjacente, int peso);

void liberarMemoria(Grafo *grafo);

int gerarChave(char verticeChave);

int fatorCargaArray(Grafo *grafo);

int calcularNovoTamanhoArray();

void gerarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta);

Grafo *aumentarTamanhoArray(Grafo *grafo);

Grafo *adicionarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta);

void imprimirGrafo(Grafo *grafo);


//LeitorArquivo
int contadorLinha(const char *nomeArquivo);

char **arquivoArestas(const char *nomeArquivo);


//LeitorArquivoArestas
Grafo *LeitorArquivo(Grafo *grafo,const char *nomeArquivo);

void liberarMatriz(char **matriz, int linhas);


#endif