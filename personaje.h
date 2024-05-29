#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "common.h"
#include "habilidad.h"

typedef struct{
    char nombre[NOMBRE]; 
    int vida;            
    int ataque;          
    int defensa;         
    Habilidad *habilidadesAtaque[2]; // Habilidades de ataque del personaje (se permite un máximo de 2)
    Habilidad *habilidadesDefensa[2]; // Habilidades de defensa del personaje (se permite un máximo de 2)
} Personaje;

void init_personaje(Personaje *personaje, Habilidad *habilidadesAtaque, int numHabilidadesAtaque, Habilidad *habilidadesDefensa, int numHabilidadesDefensa);
void print_personaje(Personaje *personaje);
void free_personaje(Personaje *personaje);

#endif