#include "turno.h"

// Inicializa la cola de turnos
void init_cola_turnos(ColaTurnos *cola) {
    cola->frente = NULL;
    cola->final = NULL;
    cola->size = 0;
}

// Comprueba si la cola está vacía
bool is_empty(ColaTurnos *cola) {
    return cola->size == 0;
}

// Encola un nuevo turno en la cola
void encolar_turno(ColaTurnos *cola, TipoTurno tipo) {
    Turno *nuevo_turno = (Turno *)malloc(sizeof(Turno));
    if (nuevo_turno == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nuevo turno.\n");
        exit(EXIT_FAILURE);
    }
    nuevo_turno->tipo = tipo;
    nuevo_turno->siguiente = NULL;

    if (is_empty(cola)) {
        cola->frente = nuevo_turno;
    } else {
        cola->final->siguiente = nuevo_turno;
    }
    cola->final = nuevo_turno;
    cola->size++;
}

// Desencola el turno del frente de la cola y lo devuelve
TipoTurno desencolar_turno(ColaTurnos *cola) {
    if (is_empty(cola)) {
        fprintf(stderr, "Error: Intentando desencolar de una cola vacía.\n");
        exit(EXIT_FAILURE);
    }

    Turno *turno_a_eliminar = cola->frente;
    TipoTurno tipo = turno_a_eliminar->tipo;
    cola->frente = turno_a_eliminar->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    free(turno_a_eliminar);
    cola->size--;
    return tipo;
}

void inicializar_turnos(ColaTurnos *cola) {
    //srand(time(NULL));
    int jugador = 0;
    for (int i = 0; i < NUM_TURNOS; i++) {
        if (rand() % 2 == 0 && jugador < (NUM_TURNOS/2)) {
            encolar_turno(cola, JUGADOR);
            jugador ++;
        } else {
            encolar_turno(cola, ENEMIGO);
        }
    }
}

// Libera toda la memoria usada por la cola de turnos
void liberar_cola_turnos(ColaTurnos *cola) {
    while (!is_empty(cola)) {
        desencolar_turno(cola);
    }
}
