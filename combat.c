#include "combat.h"
#include "tiempo.h"


void mostrar_habilidades(Habilidad* habilidades_ataque[2], Habilidad* habilidades_defensa[2]) {
    printf("Habilidades disponibles:\n");
    printf("1. Ataque normal\n");
    for (int i = 0; i < 2; i++) {
        printf("%d. Ataque: %s\n", i + 2, habilidades_ataque[i]->nombre);
    }
    for (int i = 0; i < 2; i++) {
        printf("%d. Defensa: %s\n", i + 4, habilidades_defensa[i]->nombre);
    }
}


int seleccionar_habilidad() {
    int opcion;
    printf("Elige una habilidad: ");
    scanf("%d", &opcion);
    return opcion - 1;
}

void ataque_normal_personaje(Personaje* atacante, Enemigo* objetivo) {
    printf("¡El ataque normal golpea al enemigo!\n");
    objetivo->vida -= atacante->ataque;
    printf("Al enemigo le queda %d\n de vida",objetivo->vida);
}

void habilidad_ataque_personaje(Personaje* atacante, Enemigo* objetivo, int i){
    printf("¡El jugador utiliza su habilidad especial!");
    objetivo->vida -= atacante->habilidadesAtaque[i]->modificadorHP;    
    printf("Al enemigo le queda %d\n de vida",objetivo->vida);
}
void habilidad_defensa_personaje(Personaje* atacante, Enemigo* objetivo, int i) {
    Habilidad* habilidad = atacante->habilidadesDefensa[i];
    printf("¡El jugador utiliza su habilidad especial!\n");
    objetivo->ataque -= habilidad->modificadorAtaque;
    printf("Al enemigo le queda %d\n de vida",objetivo->vida);
}

void accion_jugador(Personaje* personaje, Enemigo* enemigo) {
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
            habilidad_ataque_personaje(personaje,enemigo,opcion-2);
            break;
        case 4:
            habilidad_defensa_personaje(personaje,enemigo,opcion-3);
            break;
        case 5:
            habilidad_defensa_personaje(personaje,enemigo,opcion-4);
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
    printf("Te queda %d\n de vida",atacante->vida);
}

//void habilidad_ataque_enemigo(Personaje* atacante, Enemigo* objetivo){
    //Habilidad* habilidad;
    //printf("¡El enemigo utiliza su habilidad especial!\n");
    //atacante->vida -= habilidad->modificadorHP;
    //printf("Te queda %d\n de vida",atacante->vida);
//} 

void accion_enemigo(Enemigo* enemigo,Personaje* personaje){
    printf("Es el turno del enemigo.\n");
    randomHabilidad_enemigo(personaje,enemigo);
}