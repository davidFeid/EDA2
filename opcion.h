#include "common.h"
#include "enemigo.h"

typedef struct {
    char texto_respuesta[200];
    char texto_narracion_antes[200];
    Enemigo enemigos[2];
    int num_enemigos;
    char texto_narracion_despues[200];
} Opcion;

void printOpcion(Opcion *habilidad);

void freeOpcion(Opcion *opcion);