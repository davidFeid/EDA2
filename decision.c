#include "decision.h"

void init_decision(Decision *decision, char *texto_pregunta, Opcion *opciones, int num_opciones) {
    // Copiar los valores pasados como argumentos a la estructura decision
    strcpy(decision->texto_pregunta, texto_pregunta);
    decision->opciones = opciones;
    decision->num_opciones = num_opciones;
}

// Función para imprimir una decisión
void print_decision(Decision *decision) {
    printf("Pregunta: %s\n", decision->texto_pregunta);
    printf("Opciones:\n");
    for (int i = 0; i < decision->num_opciones; i++) {
        printf("  Opción %d:\n", i+1);
        print_opcion(&decision->opciones[i]);
    }
}

// Función para liberar memoria de una decisión
void free_decision(Decision *decision) {
    // Liberar memoria de las opciones si es necesario
    if (decision->opciones != NULL) {
        free(decision->opciones);
    }
    // No necesitas liberar memoria para el campo de texto ya que es un array estático
}
