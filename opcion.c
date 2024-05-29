#include "opcion.h"

// Función para crear una opción

void init_opcion(Opcion *opcion, char *texto_respuesta, char *narracion_antes, Enemigo *enemigos[], int num_enemigos, char *narracion_despues) {
    strcpy(opcion->texto_respuesta, texto_respuesta);
    strcpy(opcion->narracion_antes, narracion_antes);
    
    // Asignar memoria para el array de enemigos de la opción
    opcion->enemigos = malloc(num_enemigos * sizeof(Enemigo *));
    // Copiar los punteros a enemigos proporcionados como argumentos a la estructura opción
    for (int i = 0; i < num_enemigos; i++) {
        opcion->enemigos[i] = enemigos[i];
    }
    
    opcion->num_enemigos = num_enemigos;
    strcpy(opcion->narracion_despues, narracion_despues);
}

// Función para imprimir una opción
void print_opcion(Opcion *opcion) {
    printf("        Texto de respuesta: %s\n", opcion->texto_respuesta);
    printf("        Narración antes: %s\n", opcion->narracion_antes);
    // Si hay enemigos asociados a esta opción, imprimir información sobre ellos
    if (opcion->num_enemigos > 0) {
        printf("        Enemigos:\n");
        for (int i = 0; i < opcion->num_enemigos; i++) {
            printf("            Enemigo %d:\n", i+1);
            print_enemigo(opcion->enemigos[i]);
        }
    }
}

// Función para liberar memoria de una opción
void free_opcion(Opcion *opcion) {
    if (opcion != NULL) {
        free(opcion);
    }
}