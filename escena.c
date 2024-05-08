#include <stdio.h>
#include "escena.h"

void init_escena(Escena *escena,  char *nombre,  char *descripcion, char *decision) {
    strcpy(escena->nombre, nombre);
    strcpy(escena->descripcion, descripcion);
    strcpy(escena->decision, decision);
    
}

void print_escena(const Escena *escena) {
    printf("Nombre: %s\n", escena->nombre);
    printf("Descripción: %s\n", escena->descripcion);
    printf("Decisión: %s\n", escena->decision);
}

void free_escena(Escena *escena) {
    if (escena!=NULL)
    {
        free(escena);
    }
    
}