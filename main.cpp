#include <iostream>
#include <string>
using namespace std;
#include "CampoDeBatalla.h"
#include "Goblin.h"
#include "Mago.h"


void AtaqueDePlayer(Player& player, Enemigo& enemy) {
    int VidaNueva = enemy.get_Vida() - player.get_Fuerza();
    enemy.set_Vida(VidaNueva);
}

int main() {

    int x;
    int y;
    int opc;
    int objetivo;

   // Crear jugador y configurar nombre
    Player player;
    string nombreJugador;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombreJugador;
    player.set_Nombre(nombreJugador);

    // Crear enemigos
    Goblin goblin1(3, "Goblin Juan", 5);
    Goblin goblin2(4, "Goblin Pepe", 10);
    Mago mago1(10, "Mago Lazaro", 10);
    Mago mago2(8, "Mago KiKo", 5);

    CampoDeBatalla campo("tormenta",player,goblin1,goblin2,mago1,mago2);


    // Ciclo principal
    y = 0;
    cout << "Hay tormenta electrica cada 2 turnos le cae un rayo a cada peleador" << endl;
    while (y == 0 && (goblin1.get_Vida() > 0 || goblin2.get_Vida() > 0 || mago1.get_Vida() > 0 || mago2.get_Vida() > 0)) {
        campo.incrementarTurno();
        campo.Tormenta(); // Aplicar efecto de tormenta en cada turno
        x = 0;
        while (x == 0) {
            cout << "Vida del Jugador:" << player.get_vida() << endl;
            cout << "1.- Atacar" << endl;
            cin >> opc;

            if (opc == 1) {
                cout << "Elije un objetivo" << endl;
            if (goblin1.get_Vida() > 0) {
                cout << "1.-" << goblin1.get_Nombre() << " Vida:" << goblin1.get_Vida() << endl;
                }
            if (goblin2.get_Vida() > 0) {
                cout << "2.-" << goblin2.get_Nombre() << " Vida:" << goblin2.get_Vida() << endl;
                }
            if (mago1.get_Vida() > 0) {
                cout << "3.-" << mago1.get_Nombre() << " Vida:" << mago1.get_Vida() << endl;
                }
            if (mago2.get_Vida() > 0) {
                cout << "4.-" << mago2.get_Nombre() << " Vida:" << mago2.get_Vida() << endl;
            }
            cin >> objetivo;

            if (objetivo == 1 && goblin1.get_Vida() > 0) {
                AtaqueDePlayer(player ,goblin1);
                x = 1;
            } 
            else if (objetivo == 2 && goblin2.get_Vida() > 0) {
                AtaqueDePlayer(player ,goblin2);
                x = 1;
            } 
            else if (objetivo == 3 && mago1.get_Vida() > 0) {
                AtaqueDePlayer(player ,mago1);
                x = 1;
            } 
            else if (objetivo == 4 && mago2.get_Vida() > 0) {
                AtaqueDePlayer(player ,mago2);
                x = 1;
            } 
            else {
                cout << "No existe esa opción" << endl;
            }
            }         
            else {
                cout << "No existe esa opción" << endl;
            }
        }
 
            // Ataques enemigos
            if (goblin1.get_Vida() > 0) {
                goblin1.Atacar(player);
            }
            
            if (goblin2.get_Vida() > 0) {
                goblin2.Atacar(player);
            }
                
            if (mago1.get_Vida() > 0) {
                if(mago1.get_Magia() > 5){
                    mago1.Hechizo(player);
                }
                else{
                    mago1.regenerar_Magia();
                }

            }
            if (mago2.get_Vida() > 0) {
                if(mago1.get_Magia() > 5){
                    mago2.Hechizo(player);
                }
                else{
                    mago2.regenerar_Magia();
                }
            }
            if (player.get_vida() < 0){
                y = 1;
                cout << "Moriste" << endl;
            }
    }

    return 0;
}


