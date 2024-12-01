//Creación 23 nov 2024 
//Modificación 29 nov 2024
//Autor: Jesús Rodriguez Mendoza A01713550

//Descripción Clase Hija de Enemigo, El goblin es un tipo de enemigo que ataca al jugador con golpes


#ifndef GOBLIN_H
#define GOBLIN_H
#include <iostream>
#include <string>
#include "Enemigo.h"
using namespace std;

class Goblin: public Enemigo{
	private:
		int fuerza;

	public:
		//Constructores
		Goblin():Enemigo(){
			fuerza = 0;
		}

		Goblin(int _fuerza,string _nombre,int _vida): Enemigo(_nombre,_vida){
			fuerza = _fuerza;
		}

		//Metodos

		// Función atacar sirve para que el goblin pueda atacar al player,los parametros que le llegan es al objetivo que va a atacar y regresa un void 
		void Atacar(Player& player){
    		int vida_Nueva = player.get_Vida() - fuerza;
    		player.set_Vida(vida_Nueva);
    		cout << "El enemigo te quito:" << fuerza << " De Vida" << endl;

		}

};

#endif
