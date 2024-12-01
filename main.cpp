//Creacion 9 nov 2024
//Modificación 29 nov 2024
//Autor: Jesús Rodriguez Mendoza A01713550

//Descripción: Main: se maneja toda la logica de los combates y el codigo 


#include <iostream>
#include <string>
using namespace std;
#include "CampoDeBatalla.h"
#include "Goblin.h"
#include "Mago.h"

// El jugador ataca a un enemigo quitandole vida, el parametro de entrada es al enemigo que va a atacar
void AtaqueDePlayer(Player& player, Enemigo& enemy) {
    int VidaNueva = enemy.get_Vida() - player.get_Fuerza();
    enemy.set_Vida(VidaNueva);
    cout << "Atacaste al " << enemy.get_Nombre() << " ,Vida del " << enemy.get_Nombre() << ":" << enemy.get_Vida() << endl;
}

int main() {

    int comprobarSiEsaOpcionExiste;
    int playerSiguevivo;
    int opc;
    int objetivo;

   // Crear jugador y configurar nombre
    Player player;
    string nombreJugador;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombreJugador;
    player.set_Nombre(nombreJugador);

    // Crear enemigos
    Goblin goblin1(1, "Goblin Juan", 5);
    Goblin goblin2(1, "Goblin Pepe", 10);
    Mago mago1(10, "Mago Lazaro", 10);
    Mago mago2(10, "Mago KiKo", 5);

    CampoDeBatalla campo = CampoDeBatalla("tormenta");


    // Ciclo principal
    playerSiguevivo = 0;
    while (playerSiguevivo == 0 && (goblin1.get_Vida() > 0 || goblin2.get_Vida() > 0 || mago1.get_Vida() > 0 || mago2.get_Vida() > 0)) {
        //Efectos de campo
        campo.incrementarTurno();
        campo.Tormenta(player, goblin1, goblin2, mago1, mago2);

        comprobarSiEsaOpcionExiste= 0;
        //Player menu para atacar
        while (comprobarSiEsaOpcionExiste == 0) {
            cout << "Vida del Jugador:" << player.get_Vida() << endl;
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
                comprobarSiEsaOpcionExiste = 1;
            } 
            else if (objetivo == 2 && goblin2.get_Vida() > 0) {
                AtaqueDePlayer(player ,goblin2);
                comprobarSiEsaOpcionExiste = 1;
            } 
            else if (objetivo == 3 && mago1.get_Vida() > 0) {
                AtaqueDePlayer(player ,mago1);
                comprobarSiEsaOpcionExiste = 1;
            } 
            else if (objetivo == 4 && mago2.get_Vida() > 0) {
                AtaqueDePlayer(player ,mago2);
                comprobarSiEsaOpcionExiste = 1;
            } 
            else {
                cout << "No existe esa opción" << endl;
            }
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
            if (player.get_Vida() < 0){
                playerSiguevivo = 1;
                cout << "Moriste" << endl;
            }

    }

    return 0;
}


