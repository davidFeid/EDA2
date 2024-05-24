#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <stdio.h>
#include "common.h"
#include "habilidad.h"

typedef struct{
    char nombre[NOMBRE] ;
    int vida;
    int ataque;
    int defensa;
<<<<<<< HEAD
    Habilidad* habilidadesAtaque[4];
    Habilidad* habilidadesDefensa[4];
=======
    Habilidad *habilidadesAtaque[2];
    Habilidad *habilidadesDefensa[2];
>>>>>>> parent of d732088 (solo compila ataque normal)
}Personaje;

void init_personaje(Personaje *personaje, Habilidad *habilidadesAtaque, int numHabilidadesAtaque, Habilidad *habilidadesDefensa, int numHabilidadesDefensa);
void print_personaje(Personaje *personaje);
void free_personaje(Personaje *personaje);

#endif