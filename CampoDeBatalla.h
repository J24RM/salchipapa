#ifndef CAMPODEBATALLA_H
#define CAMPODEBATALLA_H

#include "Player.h"
#include "Enemigo.h"

class CampoDeBatalla {
private:
    string clima;
    int turnoActual;
    Player player;
    Enemigo enemy1;
    Enemigo enemy2;
    Enemigo enemy3;
    Enemigo enemy4;

public:
    CampoDeBatalla(string _clima, Player _player, Enemigo _enemy1,Enemigo _enemy2, Enemigo _enemy3, Enemigo _enemy4){
        clima = _clima;
        player = _player;
        enemy1 = _enemy1;
        enemy2 = _enemy2;
        enemy3 = _enemy3;
        enemy4 = _enemy4;

    }

    void incrementarTurno() {
        turnoActual++;
    }

    // Efecto de tormenta cada 2 turnos
    void Tormenta() {
        if (clima == "tormenta" && turnoActual % 2 == 0) {
            cout << "¡Un rayo cae sobre todos los personajes! Todos pierden 5 puntos de vida." << endl;
            player.set_vida(player.get_vida() - 5);
            if (enemy1.get_Vida() > 0) enemy1.set_Vida(enemy1.get_Vida() - 5);
            if (enemy2.get_Vida() > 0) enemy2.set_Vida(enemy2.get_Vida() - 5);
            if (enemy3.get_Vida() > 0) enemy3.set_Vida(enemy3.get_Vida() - 5);
            if (enemy4.get_Vida() > 0) enemy4.set_Vida(enemy4.get_Vida() - 5);
        }
    }
};

#endif
