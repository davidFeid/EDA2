#include "opcion.h"

void init_opcion(Opcion *opcion, char *texto_respuesta, char *narracion_antes, Enemigo *enemigos[], int num_enemigos, char *narracion_despues) {
    // Copiar los valores pasados como argumentos a la estructura opcion
    strcpy(opcion->texto_respuesta, texto_respuesta);
    strcpy(opcion->narracion_antes, narracion_antes);
    //opcion->enemigos = enemigos;
    // Asignar el puntero de enemigos
    opcion->enemigos = malloc(num_enemigos * sizeof(Enemigo *));
    for (int i = 0; i < num_enemigos; i++) {
        opcion->enemigos[i] = enemigos[i];
    }
    opcion->num_enemigos = num_enemigos;
    strcpy(opcion->narracion_despues, narracion_despues);
    print_enemigo(enemigos[1]);
    print_enemigo(opcion->enemigos[1]);
}

// Función para imprimir una opción
void print_opcion(Opcion *opcion) {
    printf("Texto de respuesta: %s\n", opcion->texto_respuesta);
    printf("Narración antes: %s\n", opcion->narracion_antes);
    printf("Enemigos:\n");
    for (int i = 0; i < opcion->num_enemigos; i++) {
        printf("  Enemigo %d:\n", i+1);
        print_enemigo(&opcion->enemigos[i]);
    }
    printf("Narración después: %s\n", opcion->narracion_despues);
}

// Función para liberar memoria de una opción
void free_opcion(Opcion *opcion) {
    // Liberar memoria de los enemigos si es necesario
    if (opcion->enemigos != NULL) {
        free(opcion->enemigos);
    }
    // No necesitas liberar memoria para los campos de texto ya que son arrays estáticos
}