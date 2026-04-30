CC = gcc
EXE = Eje4
OBJ = main.o funciones.o
CFLAGS = -Wall -Wextra -O2 -I.

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)
main.o: main.c funciones.h
	$(CC) $(CFLAGS) -c main.c
fuciones.o: funciones.c fuciones.h
	$(CC) $(CFLAGS) -c funciones.c

clean:
	rm -f *.o $(EXE)