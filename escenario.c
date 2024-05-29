#include "escenario.h"

// Función para crear un escenario
void init_escenario(Escenario *escenario, char *nombre, char *descripcion, Decision *decision) {
    strcpy(escenario->nombre, nombre);
    strcpy(escenario->descripcion, descripcion);
    
    // Asignar la decisión asociada al escenario
    escenario->decision = malloc(sizeof(Decision *));
    escenario->decision = decision; 
}

// Función para imprimir la información de un escenario
void print_escenario(Escenario *escenario) {
    printf("Nombre del escenario: %s\n", escenario->nombre);
    printf("Descripción del escenario: %s\n", escenario->descripcion);
}

// Función para liberar la memoria asignada a un escenario
void free_escenario(Escenario *escenario) {
    if (escenario->decision != NULL) {
        free(escenario->decision);   
        // No necesitas liberar memoria para los campos de texto ya que son arrays estáticos dentro de la estructura Opcion

    }
}