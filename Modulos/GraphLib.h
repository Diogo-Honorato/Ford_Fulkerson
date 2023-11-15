#ifndef GRAPH_LIB
#define GRAPH_LIB

typedef struct Celula
{

    char verticeAdjacente;
    int peso;
    int fluxoElementar;
    struct Celula *proximo;
    struct Celula *anterior;

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

void liberarMemoriaGrafo(Grafo *grafo);

int gerarChave(char verticeChave);

int fatorCargaArray(Grafo *grafo);

int calcularNovoTamanhoArray();

void gerarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta);

Grafo *aumentarTamanhoArray(Grafo *grafo);

Grafo *adicionarAresta(Grafo *grafo, char verticeOrigem, char verticeDestino, int pesoAresta);

int buscarVertice(Grafo *grafo, char vertice);

void imprimirGrafo(Grafo *grafo);

Grafo *removerAresta(Grafo *grafo, char vertice, char verticeAdajcente);


//LeitorArquivo
int contadorLinha(const char *nomeArquivo);

char **arquivoArestas(const char *nomeArquivo);


//LeitorArquivoArestas
Grafo *leitorArquivo(Grafo *grafo,const char *nomeArquivo);

void liberarMemoriaMatriz(char **matriz, int linhas);

//Pilha.h
typedef Lista Pilha;

Pilha *criarPilha();

char pop(Pilha *pilha);

void push(Pilha *pilha, char vertice);

int pilhaVazia(Pilha *pilha);

void liberarMemoriaPilha(Pilha *pilha);

//Dfs
char *dfs(Grafo *grafo, char verticeInicial, char verticeAlvo);

void liberarMemoriaDfs(char *caminhoDfs);

//FordFulkerson
Grafo *inverterAresta(Grafo *grafo, char verticeOrigem, char verticeAdjacente,int peso);

#endif