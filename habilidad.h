#include "common.h"

typedef struct Habilidad {
    char nombre[NOMBRE];
    char descripcion[TEXTO];
    bool esTemporal; // Verdadero si es un modificador temporal, falso si es un ataque directo
    int duracion;    // Duración en turnos (solo si es temporal)
    int modificadorAtaque;
    int modificadorDefensa;
    int modificadorHP;
} Habilidad;

//Funciones

void init_habilidad(Habilidad *habilidad,
                    char *nombre,
                    char *descripcion,
                    bool esTemporal,
                    int duracion,
                    int modificadorAtaque,
                    int modificadorDefensa,
                    int modificadorHP);

void printHabilidad(Habilidad *habilidad);

void freeHabilidad(Habilidad *habilidad);