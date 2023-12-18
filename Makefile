CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm
SOURCES = Modulos/Pilha.c Modulos/Dfs.c Modulos/FordFulkerson.c Modulos/ListaAdjacente.c Modulos/LeitorArquivo.c Modulos/LeitorArquivoArestas.c main.c
HEADERS = Modulos/GraphLib.h
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = grafo.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	@./$(EXECUTABLE) $(source) $(sink)

just-run:
	@./$(EXECUTABLE)

clean:
	@rm -f $(OBJECTS) $(EXECUTABLE)