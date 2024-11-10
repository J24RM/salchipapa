#ifndef CAMPODEBATALLA_H
#define CAMPODEBATALLA_H

#include "Player.h"
#include "Enemigo.h"

class CampoDeBatalla {
private:
    string clima;
    string terreno;
    int turnoActual;

public:
    CampoDeBatalla(string _clima, string _terreno) : clima(_clima), terreno(_terreno), turnoActual(0) {}

    void incrementarTurno() {
        turnoActual++;
    }

    // Efecto de tormenta cada 2 turnos
    void Tormenta(Player& player, Enemigo& enemy1, Enemigo& enemy2, Enemigo& enemy3, Enemigo& enemy4) {
        if (clima == "tormenta" && turnoActual % 2 == 0) {
            cout << "¡Un rayo cae sobre todos los personajes! Todos pierden 5 puntos de vida." << endl;
            player.set_Vida(player.get_Vida() - 5);
            if (enemy1.get_Vida() > 0) enemy1.set_Vida(enemy1.get_Vida() - 5);
            if (enemy2.get_Vida() > 0) enemy2.set_Vida(enemy2.get_Vida() - 5);
            if (enemy3.get_Vida() > 0) enemy3.set_Vida(enemy3.get_Vida() - 5);
            if (enemy4.get_Vida() > 0) enemy4.set_Vida(enemy4.get_Vida() - 5);
        }
    }
};

#endif
