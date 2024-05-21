#include "personaje.h"
#include "enemigo.h"
#include "opcion.h"
#include "decision.h"
#include "escenario.h"
#include "common.h"
#include "habilidad.h"

void inicializar_habilidades();
void inicializar_enemigos(Habilidad *habilidades[]);
void inicializar_opcion(Enemigo *enemigos[][2]);
void inicializar_decision(Opcion *opciones[][3]);
void inicializar_escenario(Decision *deciones[]);