#include <stdio.h>
#include "personaje.h"

/* void init_prota(Personaje *personaje,  char *nombre, int vida, int ataque, int defensa,  char habilidades[4][50]) {
    strcpy(personaje->nombre, nombre);
    personaje->vida = vida;
    personaje->ataque = ataque;
    personaje->defensa = defensa;
    for (int i = 0; i < 4; i++) {
        strcpy(personaje->habilidades[i], habilidades[i]);
    }
} */
void init_personaje(Personaje *personaje, Habilidad *habilidadesAtaque, int numHabilidadesAtaque, Habilidad *habilidadesDefensa, int numHabilidadesDefensa)  {
    printf("¡Bienvenido! Vamos a configurar a tu personaje.\n");
    
    // Solicitar y almacenar el nombre del personaje
    printf("Ingresa el nombre de tu personaje: ");
    scanf("%s", personaje->nombre);

    // Solicitar y almacenar los puntos de vida, ataque y defensa
    printf("Ingresa los puntos de vida de tu personaje: ");
    scanf("%d", &personaje->vida);

    printf("Ingresa los puntos de ataque de tu personaje: ");
    scanf("%d", &personaje->ataque);

    printf("Ingresa los puntos de defensa de tu personaje: ");
    scanf("%d", &personaje->defensa);

     // Mostrar habilidades de ataque disponibles y permitir la selección
    printf("Escoge dos de estas habilidades de ataque:\n");
    for (int i = 0; i < numHabilidadesAtaque; i++) {
        printf("%d. %s: %s\n", i + 1, habilidadesAtaque[i].nombre, habilidadesAtaque[i].descripcion);
    }

    int seleccionAtaque1, seleccionAtaque2;
    printf("Ingresa el número de tu primera habilidad de ataque: ");
    scanf("%d", &seleccionAtaque1);
    printf("Ingresa el número de tu segunda habilidad de ataque: ");
    scanf("%d", &seleccionAtaque2);

    // Validar las selecciones de ataque
    if (seleccionAtaque1 < 1 || seleccionAtaque1 > numHabilidadesAtaque || seleccionAtaque2 < 1 || seleccionAtaque2 > numHabilidadesAtaque || seleccionAtaque1 == seleccionAtaque2) {
        fprintf(stderr, "Selección inválida. Por favor, reinicia el programa y selecciona habilidades válidas.\n");
        exit(EXIT_FAILURE);
    }

    // Almacenar las habilidades de ataque seleccionadas en el personaje
    personaje->habilidadesAtaque[0] = &habilidadesAtaque[seleccionAtaque1 - 1];
    personaje->habilidadesAtaque[1] = &habilidadesAtaque[seleccionAtaque2 - 1];

    // Mostrar habilidades de defensa disponibles y permitir la selección
    printf("Escoge dos de estas habilidades de defensa:\n");
    for (int i = 0; i < numHabilidadesDefensa; i++) {
        printf("%d. %s: %s\n", i + 1, habilidadesDefensa[i].nombre, habilidadesDefensa[i].descripcion);
    }

    int seleccionDefensa1, seleccionDefensa2;
    printf("Ingresa el número de tu primera habilidad de defensa: ");
    scanf("%d", &seleccionDefensa1);
    printf("Ingresa el número de tu segunda habilidad de defensa: ");
    scanf("%d", &seleccionDefensa2);

    // Validar las selecciones de defensa
    if (seleccionDefensa1 < 1 || seleccionDefensa1 > numHabilidadesDefensa || seleccionDefensa2 < 1 || seleccionDefensa2 > numHabilidadesDefensa || seleccionDefensa1 == seleccionDefensa2) {
        fprintf(stderr, "Selección inválida. Por favor, reinicia el programa y selecciona habilidades válidas.\n");
        exit(EXIT_FAILURE);
    }

    // Almacenar las habilidades de defensa seleccionadas en el personaje
    personaje->habilidadesDefensa[0] = &habilidadesDefensa[seleccionDefensa1 - 1];
    personaje->habilidadesDefensa[1] = &habilidadesDefensa[seleccionDefensa2 - 1];

}

void print_personaje(Personaje *personaje) {
    printf("\nNombre: %s\n", personaje->nombre);
    printf("Vida: %d\n", personaje->vida);
    printf("Ataque: %d\n", personaje->ataque);
    printf("Defensa: %d\n", personaje->defensa);
    printf("Habilidades de ataque:\n");
    for (int i = 0; i < 2; i++) {
        printHabilidad( personaje->habilidadesAtaque[i]);
    }
    printf("Habilidades de defensa:\n");
    for (int i = 0; i < 2; i++) {
        printHabilidad( personaje->habilidadesDefensa[i]);
    }
}

void free_personaje(Personaje *personaje){
    if (personaje!=NULL)
    {
        free(personaje);
    }
    
}