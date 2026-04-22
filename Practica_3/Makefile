# ==========================================
# PLANTILLA MAESTRA MAKEFILE (main.c + funciones.c)
# ==========================================

# 1. Variables
CC = gcc
CFLAGS = -Wall -Wextra -O2 -I.
OBJ = main.o funciones.o

# EL NOMBRE DE TU EJECUTABLE (¡Cambia esto en cada ejercicio!)
EXE = ejercicio_ficheros

# 2. Targets Simbólicos
.PHONY: all clean

# 3. Reglas
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $^ -o $@
	@echo "=> Enlace completado. Ejecutable '$(EXE)' listo."

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXE)
	@echo "=> Basura eliminada."