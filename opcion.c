#include "opcion.h"

void init_Opcion(Opcion *opcion, char *texto_respuesta, char *texto_narracion_antes, Enemigo *enemigos, int num_enemigos, char *texto_narracion_despues) {
    strcpy(opcion->texto_respuesta, texto_respuesta);
    strcpy(opcion->texto_narracion_antes, texto_narracion_antes);
    opcion->num_enemigos = num_enemigos;
    for (int i = 0; i < num_enemigos; ++i) {
        opcion->enemigos[i] = enemigos[i];
    }
    strcpy(opcion->texto_narracion_despues, texto_narracion_despues);
}

void freeOpcion(Opcion *opcion){
    if(opcion != NULL) free(opcion);
}