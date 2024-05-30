#include "escenario.h"

void init_escenario(Escenario *escenario, char *nombre, char *descripcion, Decision *decisiones[], int num_decisiones) {
    strcpy(escenario->nombre, nombre);
    strcpy(escenario->descripcion, descripcion);
    escenario->decisiones = malloc(num_decisiones * sizeof(Decision *));
    for (int i = 0; i < num_decisiones; i++) {
        escenario->decisiones[i] = decisiones[i];
    }
    escenario->num_decisiones = num_decisiones;
}

void print_escenario(Escenario *escenario) {
    printf("Nombre del escenario: %s\n", escenario->nombre);
    printf("Descripción del escenario: %s\n", escenario->descripcion);
    
}

// Función para liberar memoria de un escenario
void free_escenario(Escenario *escenario) {
    if (escenario->decisiones != NULL) {
        free(escenario->decisiones);
    }
}

void jugar_escenario(Personaje* personaje, Escenario *escenario,Movimiento** historial) {
        int opcion_idx;
        int vida = personaje->vida;
        int defensa = personaje->defensa;
        // Mostrar el escenario 
        print_escenario(escenario);

        // Simular elección de opción
        printf("%s\n",escenario->decisiones[0]->texto_pregunta);
        printf("Elige (1-Izquierda, 2-Medio, 3-Derecha) [1-%d]: ", escenario->decisiones[0]->num_opciones);
        scanf("%d", &opcion_idx);

        if (opcion_idx <= 0 || opcion_idx > escenario->decisiones[0]->num_opciones) {
            printf("Opción no válida.\n");
            return;
        }

        Opcion *opcion = escenario->decisiones[0]->opciones[opcion_idx-1];
        print_opcion(opcion);

        // Aplicar efectos de la opción
        if (opcion->num_enemigos > 0) {
           // printf(opcion->narracion_antes);
           for (int i = 0; i < opcion->num_enemigos; i++)
           {
                int res = combate(personaje,opcion->enemigos[i], historial);

                while(res == 1){
                    printf("Quieres reiniciar el combate? Si/No (Si dices que no el juego acabará\n");
                    int op;
                    printf("Selecciona una opción: \n 1.Si\n 2.No\n");
                    scanf("%d", &op);
                    if(op == 1){
                        personaje->vida = vida;
                        personaje->defensa = defensa;
                        res = combate(personaje,opcion->enemigos[i], historial);
                    }else{
                        printf("El juego ha terminado.\n");
                        exit(0);
                    }
                }
           }
        }

        personaje->vida = vida;
        personaje->defensa = defensa;

        printf("\n Narración después: %s\n", opcion->narracion_despues);
        
}