#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "common.h"
#include "habilidad.h"

typedef struct{
    char nombre[NOMBRE] ;
    int vida;
    int ataque;
    int defensa;
    Habilidad *habilidadesAtaque[2];
    Habilidad *habilidadesDefensa[2];
    int usado_golpe_de_tiempo;
}Personaje;

void init_personaje(Personaje *personaje, Habilidad *habilidadesAtaque, int numHabilidadesAtaque, Habilidad *habilidadesDefensa, int numHabilidadesDefensa);
void print_personaje(Personaje *personaje);
void free_personaje(Personaje *personaje);

#endif