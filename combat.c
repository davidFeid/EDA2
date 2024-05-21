#include "personaje.h"
#include "enemigo.h"
#include "opcion.h"
#include "decision.h"
#include "escenario.h"
#include "common.h"
#include "habilidad.h"
#include "turno.h"
#include <time.h>
#include <stdlib.h>



void mostrar_habilidades(Habilidad* habilidades_ataque[2], Habilidad* habilidades_defensa[2]) {
    printf("Habilidades disponibles:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i+1, habilidades_ataque[i]->nombre,habilidades_defensa[i]->nombre);
    }
}

int seleccionar_habilidad() {
    int opcion;
    printf("Elige una habilidad: ");
    scanf("%d", &opcion);
    return opcion;
}

void ataque_normal_personaje(Personaje* atacante, Enemigo* objetivo) {
    printf("¡El ataque normal golpea al enemigo!\n");
    objetivo->vida -= atacante->ataque;
    printf("Al enemigo le queda %d\n",objetivo->vida,"de vida");
}

void habilidad_ataque_personaje(Personaje* atacante, Enemigo* objetivo, int indicehabilidad) {
    printf("¡El jugador utiliza su habilidad especial!\n");
    objetivo->vida -= atacante->habilidadesAtaque->modificadordevida;
    printf("Al enemigo le queda %d\n",objetivo->vida,"de vida");
}
void habilidad_defensa_personaje(Personaje* atacante, Enemigo* objetivo, int indicehabilidad) {
    printf("¡El jugador utiliza su habilidad especial!\n");
    objetivo->ataque -= atacante->habilidadesDefensa->modificadordeataque;
    printf("Al enemigo le queda %d\n",objetivo->vida,"de vida");
}

void playHumanTurn(Personaje* personaje, Enemigo* enemigo) {
    printf("Es tu turno. Elige una acción:\n");
    mostrar_habilidades(personaje->habilidadesAtaque,personaje->habilidadesDefensa);
    int opcion = seleccionar_habilidad();

    switch (opcion){
        case 1:
            ataque_normal_personaje(personaje,enemigo);
            break;
        case 2:
            habilidad_ataque_personaje(personaje,enemigo,opcion-1);
            break;
        case 3:
            habilidad_defensa_personaje(personaje,enemigo,opcion-2);
            break;
        default:
            printf("Opcion no válida!, acabas de perder tu turno");
            break;
    }
}

void randomHabilidad_enemigo(Personaje* personaje, Enemigo* enemigo){
    srand(time(NULL));
    int opcion = rand() % 2;
    if(opcion == 0){
        ataque_normal_enemigo(personaje,enemigo);
    }else{
        habilidad_ataque_enemigo(personaje,enemigo);
    }
}
void ataque_normal_enemigo(Personaje*atacante, Enemigo*objetivo) {
    printf("¡El enemigo te golpea con un ataque normal!\n");
    atacante->vida -= objetivo->ataque;
    printf("Te queda %d\n",atacante->vida,"de vida");
}

void habilidad_ataque_enemigo(Personaje* atacante, Enemigo* objetivo){
    printf("¡El enemigo utiliza su habilidad especial!\n");
    atacante->vida -= objetivo->habilidadesAtaque->modificadordevida;
    printf("Te queda %d\n",atacante->vida,"de vida");
}
void playMachineTurn(Personaje* personaje, Enemigo* enemigo) {
    printf("Es el turno del enemigo.\n");
    randomHabilidad_enemigo(personaje,enemigo);
}