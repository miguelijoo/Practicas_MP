CC = gcc
EXE = test
OBJ = main.o
CFLAGS = -Wall -Wextra -O2 -I.

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c


clean:
	rm -f *.o $(EXE) *.txt
