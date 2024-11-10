#include <iostream>
#include <string>
using namespace std;
#include "Player.h"
#include "Enemigo.h"
#include "CampoDeBatalla.h"
// #include "ControladorDeAtaques.h"


void AtaqueDePlayer(Player& player, Enemigo& enemy) {
    int VidaNueva = enemy.get_Vida() - player.get_Fuerza();
    enemy.set_Vida(VidaNueva);
}

void AtaqueDeEnemigo(Enemigo& enemy, Player& player) {
    int VidaNueva = player.get_Vida() - enemy.get_Fuerza();
    player.set_Vida(VidaNueva);
    cout << "El enemigo ataco al jugador" << endl;
}

void Envenenar(Player& player, Enemigo& enemy) {
    player.set_EnvenenadoEstado(1);
    player.set_EnvenenadoCooldown(enemy.get_EnvenenamientoCooldown());
}


void Combate(Enemigo& enemy1, Enemigo& enemy2, Enemigo& enemy3, Enemigo& enemy4, Player& player, CampoDeBatalla& campo) {
    int opc;
    int x;
    int y;
    int objetivo;
    y = 0;
    cout << "Hay tormenta electrica cada 2 turnos le cae un rayo a cada peleador" << endl;
    while (y == 0 && (enemy1.get_Vida() > 0 || enemy2.get_Vida() > 0 || enemy3.get_Vida() > 0 || enemy4.get_Vida() > 0)) {
        campo.incrementarTurno();
        campo.Tormenta(player, enemy1, enemy2, enemy3, enemy4); // Aplicar efecto de tormenta en cada turno

        if (player.get_Vida() > 0) {
            x = 0;
            while (x == 0) {
                cout << "Vida del Jugador:" << player.get_Vida() << endl;
                cout << "1.- Atacar" << endl;
                cin >> opc;

                if (opc == 1) {
                    cout << "Elije un objetivo" << endl;
                    if (enemy1.get_Vida() > 0) {
                        cout << "1.-" << enemy1.get_Nombre() << " Vida:" << enemy1.get_Vida() << endl;
                    }
                    if (enemy2.get_Vida() > 0) {
                        cout << "2.-" << enemy2.get_Nombre() << " Vida:" << enemy2.get_Vida() << endl;
                    }
                    if (enemy3.get_Vida() > 0) {
                        cout << "3.-" << enemy3.get_Nombre() << " Vida:" << enemy3.get_Vida() << endl;
                    }
                    if (enemy4.get_Vida() > 0) {
                        cout << "4.-" << enemy4.get_Nombre() << " Vida:" << enemy4.get_Vida() << endl;
                    }
                    cin >> objetivo;

                    if (objetivo == 1 && enemy1.get_Vida() > 0) {
                        AtaqueDePlayer(player ,enemy1);
                        x = 1;
                    } else if (objetivo == 2 && enemy2.get_Vida() > 0) {
                        AtaqueDePlayer(player ,enemy2);
                        x = 1;
                    } else if (objetivo == 3 && enemy3.get_Vida() > 0) {
                        AtaqueDePlayer(player ,enemy3);
                        x = 1;
                    } else if (objetivo == 4 && enemy4.get_Vida() > 0) {
                        AtaqueDePlayer(player ,enemy4);
                        x = 1;
                    } else {
                        cout << "No existe esa opción" << endl;
                    }
                } else {
                    cout << "No existe esa opción" << endl;
                }
            }
        } else {
            y = 1;
        }
        
        // Ataques enemigos
        if (enemy1.get_Vida() > 0) {
            if (enemy1.get_Tipo_De_Enemigo() == 1) {
                AtaqueDeEnemigo(enemy1, player);
            }
            if (enemy1.get_Tipo_De_Enemigo() == 2) {
                enemy1.Curar(enemy2, enemy3, enemy4);
            }
        }
        if (enemy2.get_Vida() > 0) {
            if (enemy2.get_Tipo_De_Enemigo() == 1) {
                AtaqueDeEnemigo(enemy2, player);
            }
            if (enemy2.get_Tipo_De_Enemigo() == 2) {
                enemy2.Curar(enemy1, enemy3, enemy4);
            }
        }
        if (enemy3.get_Vida() > 0) {
            if (enemy3.get_Tipo_De_Enemigo() == 1) {
                AtaqueDeEnemigo(enemy3, player);
            }
            if (enemy3.get_Tipo_De_Enemigo() == 2) {
                enemy3.Curar(enemy2, enemy1, enemy4);
            }
        }
        if (enemy4.get_Vida() > 0) {
            if (enemy4.get_Tipo_De_Enemigo() == 1) {
                AtaqueDeEnemigo(enemy4, player);
            }
            if (enemy4.get_Tipo_De_Enemigo() == 2) {
                enemy4.Curar(enemy2, enemy3, enemy1);
            }
        }
    }
}

int main() {
    Player player;
    Enemigo enemy1("Goblin", 1, 10, 0, 1, 2, 1);
    Enemigo enemy2("Curandero", 1, 10, 3, 2, 2, 2);
    Enemigo enemy3;
    Enemigo enemy4;

    CampoDeBatalla campo("tormenta", "normal");
    Combate(enemy1, enemy2, enemy3, enemy4, player, campo);

    return 0;
}

// ControladorDeAtaques::Envenenar(player, enemy);
