# Definição de variáveis
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm
SOURCES = ../Modulos/ListaAdjacente.c ../Modulos/LeitorArquivo.c ../Modulos/LeitorArquivoArestas.c  main.c

	  
HEADERS = ../Modulos/GraphLib.h
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = grafo_exe

# Regras de compilação
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)