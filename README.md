## Descrição
Este é um código escrito na linguagem C, feito no sistema operacional Linux, para resolver o problema de fluxo máximo, que se concentra em encontrar o máximo de fluxo que pode passar por uma rede direcionada, onde há um nó de origem (source) e um nó de destino (sink), além de arestas que conectam esses nós, cada uma com uma capacidade específica.

## Como usar
### Para executar o algoritmo:
1. Navegue até o diretório atual onde se encontram os arquivos correspondentes do programa, usando o terminal.
2. Existe duas opções para executar
   
   1:'`make just-run`', executa o programa com os vértices 'S' e 'T' como o source e sink respectivamente.
   
   2:'`make run source= sink=`',executa o programa com os vértices source e sink da sua escolha.
   
    Exemplo:'`make run source=A sink=T`','`make run source=G sink=T`'


### Para utilizar novos testes:
1. Navegue até a pasta `testes`.
1. Modifique o arquivo `input.txt` com o grafo desejado, ou sustitua por outro arquivo mas modifique o nome do arquivo atual para `input.txt`
   - Cada linha deve possuir três colunas:
     - A primeira referente a um vértice origem
     - A segunda referente a um vértice destino
     - A terceira referente à capacidade da aresta
     - Exemplo de input:
```bash
S B 10
S C 5
S D 15
B C 4
B F 15
B E 9
C F 8
C D 4
D G 16
E F 15
E T 10
F G 15
F T 10
G C 6
G T 10
```
