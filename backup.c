// teste
int main()
{

    Grafo *G = criarGrafo();

    char matriz[11][3] = {{'A', 'B', '1'}, {'Z', 'C', '8'}, {'S', 'D', '3'}, {'B', 'G', '7'}, {'C', 'S', '9'}, {'E', 'D', '5'}, {'F', 'S', '2'}, {'G', 'A', '3'}, {'H', 'G', '9'}, {'I', 'U', '8'}, {'D', 'F', '6'}};

    for (int i = 0; i < 11; i++)
    {
        adicionarAresta(&G, matriz[i][0], matriz[i][1], matriz[i][2] - '0');
    }

    imprimirGrafo(G);

    liberarMemoria(G);
}