#include "escenario.h"

void init_escenario(Escenario *escenario, char *nombre, char *descripcion, Decision *decision) {
    strcpy(escenario->nombre, nombre);
    strcpy(escenario->descripcion, descripcion);
    escenario->decision = malloc( sizeof(Decision *));
    escenario->decision = decision;
    
}

void print_escenario(Escenario *escenario) {
    printf("Nombre del escenario: %s\n", escenario->nombre);
    printf("Descripción del escenario: %s\n", escenario->descripcion);
    
}

// Función para liberar memoria de un escenario
void free_escenario(Escenario *escenario) {
    if (escenario->decision != NULL) {
        free(escenario->decision);
    }
}