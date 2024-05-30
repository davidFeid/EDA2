#ifndef GRAFO_H
#define GRAFO_H

#include "common.h"
#include "escenario.h"

#define MAX_NODOS 4

typedef struct {
    int grafo[MAX_NODOS][MAX_NODOS]; // Matriz de adyacencia para representar el grafo
    int historial[MAX_NODOS]; // Array para almacenar el historial de nodos visitados
    int nodo_actual; // Nodo actual
} Grafo;

void imprimir_opciones(Grafo *grafo,Escenario *escenarios[]);
void mover(Grafo *grafo, int opcion);
void mostrar_historial(Grafo *grafo,Escenario *escenarios[]);
void init_grafo(Grafo *grafo);

#endif
