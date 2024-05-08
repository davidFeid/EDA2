#include <stdio.h>
#include "escena.h"

/* void init_escena(Escena *escena,  char *nombre,  char *descripcion, char *decision) {
    strcpy(escena->nombre, nombre);
    strcpy(escena->descripcion, descripcion);
    strcpy(escena->decisión, decision);
    
} */

/* void print(const Escena *escena) {
    printf("Nombre: %s\n", escena->nombre);
    printf("Descripción: %s\n", escena->descripción);
    printf("Decisión: %s\n", escena->decisión);
} */

void freeEscena(Escena *escena) {
    if (escena!=NULL)
    {
        free(escena);
    }
    
}