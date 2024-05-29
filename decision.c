#include "decision.h"

// Función para inicializar una decisión con una pregunta y opciones
void init_decision(Decision *decision, char *texto_pregunta, Opcion *opciones[], int num_opciones) {
    
    strcpy(decision->texto_pregunta, texto_pregunta);
    // Asignar memoria para las opciones de la decisión
    decision->opciones = malloc(num_opciones * sizeof(Opcion *));
    // Copiar las opciones proporcionadas a la estructura 
    for (int i = 0; i < num_opciones; i++) {
        decision->opciones[i] = opciones[i];
    }
    decision->num_opciones = num_opciones;
}

// Función para imprimir una decisión y sus opciones
void print_decision(Decision *decision) {
    printf("Pregunta: %s\n", decision->texto_pregunta);
    printf("Opciones:\n");
    for (int i = 0; i < decision->num_opciones; i++) {
        printf("  Opción %d:\n", i+1);
        // Llamar a la función print_opcion para imprimir cada opción
        print_opcion(decision->opciones[i]);
    }
}

// Función para liberar la memoria asignada a una decisión
void free_decision(Decision *decision) {
    
    if (decision != NULL) {
        free(decision);
    }

}
