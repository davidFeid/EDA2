#include "main.h"

void inicializar_enemigos(){
    Enemigo fantasma;
    init_enemigo(&fantasma, "Fantasma de soldado", 100, 50, 20);
   
    Enemigo cofretrampa;
    init_enemigo(&cofretrampa, "Cofre Trampa", 225, 100, 200);
    

    Enemigo subordinadoelfo;
    init_enemigo(&subordinadoelfo, "Subordinado elfo", 125, 120, 80);
    

    Enemigo jefoelfe;
    init_enemigo(&jefoelfe, "Elfo Jefe", 400, 150, 300);
    

    Enemigo tortuga;
    init_enemigo(&tortuga, "Tortuga", 205, 110, 500);
    

    Enemigo miniblaze;
    init_enemigo(&miniblaze, "Secuaz de Blaze", 350, 120, 300);
    

    Enemigo blaze;
    init_enemigo(&blaze, "BLAZE", 1000, 400, 600);
    
}

void inicializar_decision(){
    Decision cementerio;
    init_decision(&cementerio,"Después de derrotar a todos los enemigos, te encuentras a la salida del cementerio. Estando todavía desconcertado, no te estás del todo situado en tu antigua vida, asi que no sabes que camino hay que tomar. Por donde deseas ir?", 3, "");
    print(&cementerio);

    Decision bosque;
    init_decision(&bosque, "Perdido dentro del bosque, te encuentras con unos carteles que te dan información sobre que ruta escoger. Una vez leídos, hacía donde decides partir?",3,"");
    print(&bosque);

    Decision lago;
    init_decision(&lago,"Contemplando de una vez el azul claro del agua del lago, observas al frente y ves que hay ciertos caminos que no están en muy buenas condiciones. Estando el camino partido en 3, hacia donde deseas partir para llegar al casitllo?",3,"");
    print(&lago);
}



void inicializar_opcion(){
    Opcion cementerio;
    init_Opcion(&cementerio,)

    
    Opcion bosque;


    Opcion lago;
}
int main(){
    // Crear una instancia de la estructura Personaje
    Personaje miPersonaje;

    // Configurar el personaje
    init_personaje(&miPersonaje);

    // Mostrar los datos del personaje configurado
    print_personaje(&miPersonaje);

    inicializar_enemigos();
    inicializar_decision();
    return 0;
}