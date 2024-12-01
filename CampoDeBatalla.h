//Creacion 9 nov 2024
//Modificación 29 nov 2024
//Autor: Jesús Rodriguez Mendoza A01713550

//Descripción: Clase campo de batalla, se encarga de manejar todos los estados de campo, como una tormenta electrica

#ifndef CAMPODEBATALLA_H
#define CAMPODEBATALLA_H

#include "Player.h"
#include "Enemigo.h"
#include "Goblin.h"
#include "Mago.h"

class CampoDeBatalla {
private:
    string clima;
    int turnoActual;
    Player player;
    Goblin enemy1;
    Goblin enemy2;
    Mago enemy3;
    Mago enemy4;

public:
    //Constructor
    CampoDeBatalla(string _clima){
        clima = _clima;

    }

    //Funcion que incrementa los turnos, lo hace como si fuera paso de tiempo
    void IncrementarTurno() {
        turnoActual++;
    }

    // Realiza un ataca que quita 5 de vida a cada jugador, el rayo cae cada dos turnos
    void Tormenta(Player& player, Goblin& enemy1, Goblin& enemy2, Mago& enemy3, Mago& enemy4) {
        if (clima == "tormenta" && turnoActual % 2 == 0) {
            cout << "¡Un rayo cae sobre todos los personajes! Todos pierden 5 puntos de vida." << endl;
            player.set_Vida(player.get_Vida() - 5);
            enemy1.set_Vida(enemy1.get_Vida() - 5);
            enemy2.set_Vida(enemy2.get_Vida() - 5);
            enemy3.set_Vida(enemy3.get_Vida() - 5);
            enemy4.set_Vida(enemy4.get_Vida() - 5);
        }

    }

};

#endif
