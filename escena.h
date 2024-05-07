#include <stdio.h>
#include "common.h"

typedef struct 
{
    char nombre[50];
    char déscripción[100];
    char decisión[25];
}Escena;

void init_escena(Escena *escene);

void finish_escena(Escena *escene);
