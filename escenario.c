#include "escenario.h"

void init_escenario(Escenario *escenario, char *nombre, char *descripcion, Decision *decisiones[], int num_decisiones) {
    strcpy(escenario->nombre, nombre);
    strcpy(escenario->descripcion, descripcion);
    escenario->decisiones = malloc(num_decisiones * sizeof(Decision *));
    for (int i = 0; i < num_decisiones; i++) {
        escenario->decisiones[i] = decisiones[i];
    }
    escenario->num_decisiones = num_decisiones;
}

void print_escenario(Escenario *escenario) {
    printf("Nombre del escenario: %s\n", escenario->nombre);
    printf("Descripción del escenario: %s\n", escenario->descripcion);
    for (int i = 0; i < escenario->num_decisiones; i++) {
        printf("Decisión %d:\n", i+1);
        print_decision(escenario->decisiones[i]);
    }
}

// Función para liberar memoria de un escenario
void free_escenario(Escenario *escenario) {
    if (escenario->decisiones != NULL) {
        free(escenario->decisiones);
    }
}