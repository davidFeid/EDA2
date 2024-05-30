
#include "combat.h"

//Inicialitzarem la següent funció per tal de que al iniciar una batalla apareguin quines son les habilitats disponibles per utilitzar en el teu torn
void mostrar_habilidades(Habilidad* habilidades_ataque[2], Habilidad* habilidades_defensa[2]) {
    printf("Habilidades disponibles:\n");
    printf("1. Ataque normal\n");
    for (int i = 0; i < 2; i++) {
        printf("%d. Ataque: %s\n", i + 2, habilidades_ataque[i]->nombre); //Recorrerà tota la array de les habilitats d'atac decidides al crear el personatge al principi del joc per una part
    }
    for (int i = 0; i < 2; i++) {
        printf("%d. Defensa: %s\n", i + 4, habilidades_defensa[i]->nombre);//També recorrerà totes les habilitats de defensa i les printejará per una altre part
    }
     for (int i = 0; i < 1; i++) {
        printf("%d. HABILIDAD DEFINITIVA (1 sola vez): %s\n", i + 6, "Tiempo Mental"); //Aquesta habilitat será de un ús, així que anirá apart del array de les habilitats
    }
}

//Inicialitzarem la funció amb la qual passarem les opcions a l'hora d'escollir que volem fer en el nostre torn
int seleccionar_habilidad() {
    int opcion; //Variable que guardará el valor que haguem escollit
    printf("Elige una habilidad: ");
    scanf("%d", &opcion); //Escanejará el valor posat per teclat amb l'scanf
    return opcion;
}

//Per una part, declararem la funció que recollirá l'atac normal del nostre personatge, es a dir, sense utilitzar cap de les habilitats
void ataque_normal_personaje(Personaje* atacante, Enemigo* objetivo) {
    if(objetivo->defensa >= atacante->ataque){ //Aquest if comprovará si la defensa del enemic es més gran que el nostre atac, de manera que la quantitat de atac del nostre personatge anirá destinat a trencar la defensa del enemic
        printf("¡El ataque normal golpea la defensa del enemigo!\n");
        objetivo->defensa -= atacante->ataque; //S'haurá de trencar la defensa del enemic per tal de que poguem pegar definitvament a la vida del nostre enemic
        printf("Al enemigo le queda %d de defensa",objetivo->defensa);
    }else{
        printf("¡El ataque normal golpea al enemigo!\n");
        objetivo->vida -= atacante->ataque - objetivo->defensa; //Una vegada haguem superat la seva defensa, ja podrem donar pas a restar la verdadera vida al enemic
        printf("Al enemigo le queda %d de vida",objetivo->vida);
    }
}
//Ara inicialitzarem les funcions d'habilitats especials del nostre personatge, començant per les d'atac
void habilidad_ataque_personaje(Personaje* atacante, Enemigo* objetivo, int i) {
    if(objetivo->defensa >= atacante->habilidadesAtaque[i]->modificadorAtaque){ //Com abans, jugarem amb la defensa del enemic fins a acabar amb ella y poder treure vida finalment
        printf("¡El jugador utiliza %s contra la defensa del enemigo!\n", atacante->habilidadesAtaque[i]->nombre);
        objetivo->defensa -= atacante->habilidadesAtaque[i]->modificadorAtaque; //Recorrarem l'array de les habilitats d'atac amb la variable opció que haguem escollit, de forma que s'efectuará la habilitat desitjada
        printf("Al enemigo le queda %d de defensa",objetivo->defensa);
    }else{
        printf("¡El jugador utiliza su habilidad especial!\n");
        objetivo->vida -= atacante->habilidadesAtaque[i]->modificadorAtaque - objetivo->defensa; //Una vegada s'acabi la defensa, l'atac actuará contra la vida del enemic
        printf("Al enemigo le queda %d de vida",objetivo->vida);
    }
}
//Acabant amb les del personatge, inicialitzem les habilitats que augmentaran tant la defensa o la vida del nostre usuari
void habilidad_defensa_personaje(Personaje* atacante, Enemigo* objetivo, int i) {
    printf("¡El jugador utiliza %s!\n",atacante->habilidadesDefensa[i]->nombre);
    atacante->defensa += atacante->habilidadesDefensa[i]->modificadorDefensa; //Haurem de sumar-li els valors que haguem establit de defensa en cada habilitat a la defensa principal del personatge, fent així que els torns tinguin sentit
    printf("Te has subido la defensa! Ahora tienes %d de defensa",atacante->defensa);
}


//Separarem les accions del jugador per una part i les del enemic per un altre, on les del jugador recollirán
//les funcions d'habilitat que hem vist abans y s'aplicarán segons la decisió de cada usuari a l'hora de jugar
void accion_jugador(Personaje* personaje, Enemigo* enemigo, Movimiento** historial) {
    printf("Es tu turno. Elige una acción:\n");
    mostrar_habilidades(personaje->habilidadesAtaque, personaje->habilidadesDefensa); //printejarán les habilitats que hagi escollit l'usuari al inici del joc
    int opcion = seleccionar_habilidad(); //S'iniciará la funció per tal d'escollir l'opció en combat

    switch (opcion) { //Amb un sistema switch/case, les habilitats s'utilitzarán segons quin valor hagi posat l'usuari per teclat, de forma que les habilitats anirán treient vida/defensa als enemics mentres es van posicionant a una pila que servirá per la habilitat definitiva.
        case 1:
            ataque_normal_personaje(personaje, enemigo);
            push(historial, "Ataque normal");
            break;
        case 2:
            habilidad_ataque_personaje(personaje, enemigo, opcion - 2);
            push(historial, personaje->habilidadesAtaque[opcion - 2]->nombre);
            break;
        case 3:
            habilidad_ataque_personaje(personaje, enemigo, opcion - 2);
            push(historial, personaje->habilidadesAtaque[opcion - 2]->nombre);
            break;
        case 4:
            habilidad_defensa_personaje(personaje, enemigo, opcion - 4);
            push(historial, personaje->habilidadesDefensa[opcion - 4]->nombre);
            break;
        case 5:
            habilidad_defensa_personaje(personaje, enemigo, opcion - 4);
            push(historial, personaje->habilidadesDefensa[opcion - 4]->nombre);
            break;
        case 6:
            golpe_de_tiempo(*historial, personaje, enemigo); //Aquesta habilitat definitiva, escollirá de totes les habilitats ficades a la pila, una random la qual provocará que el seu atac es vegi proporcionat *2. Només és podra utilitzar una vegada per combat
            break;
    }
}

//Ara ve l'apartat de les habilitats del enemic, on tot es decidirá de manera aleatoria, així que ho recollirem en aquesta funció
void randomHabilidad_enemigo(Personaje* personaje, Enemigo* enemigo){
    int opcion = rand() % 3; //Opció jugará entre els valors 0,1,2 per tal de printejar les diferents habilitats dins de la funció 
    if (opcion == 0) {
        ataque_normal_enemigo(personaje, enemigo); //Si es 0, efectuará un atac normal contra l'usuari
    }else{
        habilidad_enemigo(enemigo,personaje,opcion-1); //En el cas contrari, passará a utilitzar les habilitats que cada enemic tingui
    }
}

//Recollirem totes les habilitats especials del enemic dins de una sola funció
void habilidad_enemigo(Enemigo* objetivo, Personaje* atacante, int i){
    if (objetivo->habilidades[i]->modificadorAtaque > 0){ 
        if(atacante->defensa >= objetivo->habilidades[i]->modificadorAtaque){ //Com hem vist abans, la defensa del usuari també s'ha de tenir en compte contra els enemics, així que fins que no et treguin la defensa, no et podrán matar
            printf("¡El enemigo utiliza %s contra tu defensa! \n", objetivo->habilidades[i]->nombre);
            atacante->defensa -= objetivo->habilidades[i]->modificadorAtaque; //Així que s'anirá restant la teva defensa fins que aquesta sigui zero
            printf("Te queda %d de defensa",atacante->defensa);  
        }else{
            printf("¡El enemigo utiliza %s con lo que te ataca con todo su poder! \n", objetivo->habilidades[i]->nombre);
            atacante->vida -= objetivo->habilidades[i]->modificadorAtaque - atacante->defensa; //Quan sigui zero, llavors tots els atacs del enemic s'efectuarán contra la teva salud principal, així que s'anirá restant fins que estiguis en zero
            printf("Te queda %d de vida",atacante->vida);
        }
    }else if(objetivo->habilidades[i]->modificadorDefensa > 0){
        printf("¡El enemigo utiliza %s con el que se sube la defensa! \n", objetivo->habilidades[i]->nombre);
        objetivo->defensa += objetivo->habilidades[i]->modificadorDefensa; //En el cas de que hagi decidit la màquina augmentarse la defensa, se li anirá sumant a les seves estadístiques
        printf("Al enemigo le queda %d de defensa",objetivo->defensa);
    }
    
}

//Aquesta funció será la mateixa que hem vist per a l'usuari principal, pero en aquest cas s'inverteixen els ordres de les variables ja que es de l'enemic al protagonista
void ataque_normal_enemigo(Personaje*atacante, Enemigo*objetivo) {
    if(atacante->defensa >= objetivo->ataque){
        printf("El enemigo golpea con un ataque normal tu defensa");
        atacante->defensa -= objetivo->ataque;
        printf("Te queda %d de defensa", atacante->defensa);
    }else{
        printf("¡El enemigo te golpea con un ataque normal!\n");
        atacante->vida -= objetivo->ataque -atacante->defensa;
        printf("Te queda %d de vida",atacante->vida);
    }
}


void accion_enemigo(Enemigo* enemigo,Personaje* personaje){
    printf("Es el turno del enemigo.\n");
    randomHabilidad_enemigo(personaje,enemigo);
}

int combate(Personaje* personaje, Enemigo* enemigo,Movimiento** historial){
    ColaTurnos cola;
    init_cola_turnos(&cola);
    inicializar_turnos(&cola);

    printf("Iniciando combate:\n");
    printf("Jugador: %s, Vida: %d\n", personaje->nombre, personaje->vida);
    printf("Enemigo: %s, Vida: %d\n", enemigo->nombre, enemigo->vida);

    while (!is_empty(&cola) && personaje->nombre > 0 && enemigo->vida > 0) {
        TipoTurno tipo = desencolar_turno(&cola);
        if (tipo == JUGADOR) {
            printf("\nTurno del personaje:\n");
            accion_jugador(personaje, enemigo,historial);
        } else {
            printf("\nTurno del enemigo:\n");
            //accion_enemigo(enemigo, personaje);
            //accion_enemigo(enemigo,personaje);
            accion_enemigo(enemigo,personaje);
        }
    }
    liberar_cola_turnos(&cola);
    if (personaje->vida > 0 && enemigo->vida <= 0) {
        return 0;
    } else if (enemigo->vida > 0 && personaje->vida <= 0) {
        printf("\n¡El enemigo ha ganado!\n");
    } else {
        printf("\n¡La batalla ha terminado en empate!\n");
    }
    return 1;
    
}