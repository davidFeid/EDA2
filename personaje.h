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
    Habilidad* habilidadesAtaque[4];
    Habilidad* habilidadesDefensa[4];
}Personaje;

void init_personaje(Personaje *personaje, Habilidad *habilidadesAtaque, int numHabilidadesAtaque, Habilidad *habilidadesDefensa, int numHabilidadesDefensa);
void print_personaje(Personaje *personaje);
void free_personaje(Personaje *personaje);

#endif