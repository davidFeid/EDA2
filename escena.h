#include <stdio.h>
#include "common.h"

typedef struct 
{
    char nombre[NOMBRE];
    char déscripción[TEXTO];
    char decisión[TEXTO];
}Escena;

void init_escena(Escena *escene);

void finish_escena(Escena *escene);
