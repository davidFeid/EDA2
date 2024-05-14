#include "main.h"

void inicializar_enemigos(){
    Enemigo fantasma1;
    init_enemigo(&fantasma1, "Fantasma de soldado", 100, 50, 20);

    Enemigo fantasma2;
    init_enemigo(&fantasma2, "Fantasma de soldado", 100, 50, 20);
   
    Enemigo cofretrampa;
    init_enemigo(&cofretrampa, "Cofre Trampa", 225, 100, 200);

    //Enemigo enemigos_opcion1[] = {fantasma,cofretrampa};
    //inicializar_opcion(enemigos_opcion1);

    Enemigo subordinadoelfo;
    init_enemigo(&subordinadoelfo, "Subordinado elfo", 125, 120, 80);
    
    Enemigo jefoelfe;
    init_enemigo(&jefoelfe, "Elfo Jefe", 400, 150, 300);
    
    Enemigo tortuguita1;
    init_enemigo(&tortuguita1, "Tortugas", 155, 210, 400);

    Enemigo tortuguita2;
    init_enemigo(&tortuguita2, "Tortugas", 155, 210, 400);
    
    Enemigo tortugon;
    init_enemigo(&tortugon, "Tortuga", 205, 110, 500);
    
    Enemigo miniblaze;
    init_enemigo(&miniblaze, "Secuaz de Blaze", 350, 120, 300);
    
    Enemigo blaze;
    init_enemigo(&blaze, "BLAZE", 1000, 400, 600);

    Enemigo enemigos[][2] = {{fantasma1,fantasma2},{cofretrampa},{subordinadoelfo},{jefoelfe},{tortuguita1,tortuguita2},{tortugon},{blaze,miniblaze}};
    inicializar_opcion(enemigos);
}

void inicializar_opcion(Enemigo enemigos[][2]){
    Opcion opcion1_1; 
    init_opcion(&opcion1_1, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[1], 1, "Has derrotado al enemigo.");

    Opcion opcion1_2; 
    init_opcion(&opcion1_2, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[2], 1, "Has derrotado al enemigo.");

    Opcion opcion2_1; 
    init_opcion(&opcion2_1, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[3], 1, "Has derrotado al enemigo.");

    Opcion opcion3_1; 
    init_opcion(&opcion3_1, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[4], 2, "Has derrotado al enemigo.");
    
    Opcion opcion3_2; 
    init_opcion(&opcion3_2, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[5], 1, "Has derrotado al enemigo.");

    //print_opcion(&opcion1_1);
    Opcion opciones[][3] = {{opcion1_1,opcion1_2},{opcion2_1},{opcion3_1,opcion3_2}};
    inicializar_decision(opciones);
}

void inicializar_decision(Opcion opciones[][3]){
    Decision decision1;
    init_decision(&decision1, "¿Qué quieres hacer?", opciones[0], 2);

    Decision decision2;
    init_decision(&decision2, "¿Qué quieres hacer?", opciones[1], 2);

    Decision decision3;
    init_decision(&decision3, "¿Qué quieres hacer?", opciones[2], 2);
    
    Decision decisiones[] = {decision1,decision2,decision3};
    
    //printf("----------------------------------------------------\n");
    //printf("\n Decisioneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeees:\n \n");
    //print_decision(&decision1);
    inicializar_escenario(decisiones);
}

void inicializar_escenario(Decision decisiones[]){
    // Crear el escenario
    
    Escenario escenario2;
    init_escenario(&escenario2, "Escenario 2", "Descripción del escenario 2", &decisiones[0], 1);

    Escenario escenario3;
    init_escenario(&escenario3, "Escenario 3", "Descripción del escenario 3", &decisiones[1], 1);

    Escenario escenario4;
    init_escenario(&escenario4, "Escenario 4", "Descripción del escenario 4", &decisiones[2], 1);

    // Imprimir el escenario
    //printf("----------------------------------------------------\n");
    print_escenario(&escenario2);
}

int main() {
    // Crear una instancia de la estructura Personaje
    Personaje miPersonaje;

    // Configurar el personaje
    init_personaje(&miPersonaje);

    // Mostrar los datos del personaje configurado
    printf("\nPensonaje: \n");
    print_personaje(&miPersonaje);
    printf("----------------------------------------------------\n");
    printf("\nEnemigos:\n \n");
    inicializar_enemigos();
    return 0;
}

