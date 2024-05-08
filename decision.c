#include "decision.h"

/* void init(Decision *decision,  char *pregunta, int num_opciones,  char *opciones[3][100]) {
    strcpy(decision->pregunta, pregunta);
    decision->num_opciones = num_opciones;
    for (int i = 0; i < num_opciones; i++) {
        strcpy(decision->opciones[i], opciones[i]);
    }
} */


void print( Decision *decision) {
    printf("Pregunta: %s\n", decision->pregunta);
    printf("Número de opciones: %d\n", decision->num_opciones);
    printf("Opciones:\n");
    for (int i = 0; i < decision->num_opciones; ++i) {
        printf("%d. %s\n", i + 1, decision->opciones[i]);
    }
}

void free_decision(Decision *decision) {
    if (decision!=NULL)
    {
        free(decision);
    }
    
}
