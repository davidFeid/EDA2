#include "opcion.h"

void printOpcion(Opcion *opcion) {
    printf("Texto de respuesta: %s\n", opcion->texto_respuesta);
    printf("Narración antes de enfrentarse a los enemigos: %s\n", opcion->texto_narracion_antes);
    printf("Enemigos:\n");
    for (int i = 0; i < opcion->num_enemigos; ++i) {
        printf("- %s (Nivel %d)\n", opcion->enemigos[i].nombre, opcion->enemigos[i].nivel);
    }
    printf("Narración después de enfrentarse a los enemigos: %s\n", opcion->texto_narracion_despues);
}

void freeOpcion(Opcion *opcion){
    if(opcion != NULL) free(opcion);
}