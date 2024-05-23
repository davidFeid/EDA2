#include <stdio.h>
#include "common.h"

typedef struct 
{
    char nombre[50];
    char descripcion[100];
    char decision[25];
}Escena;

void init_escena(Escena *escena,  char *nombre,  char *descripcion, char *decision);

void print_escena(const Escena *escena)

void free_escena(Escena *escena);
