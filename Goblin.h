#ifndef GOBLIN_H
#define GOBLIN_H
#include <iostream>
#include <string>
#include "Enemigo.h"
using namespace std;

class Goblin: public Enemigo{
	private:
		int Fuerza;

	public:
		Goblin():Enemigo(){
			Fuerza = 0;
		}

		Goblin(int _Fuerza,string _Nombre,int _Vida): Enemigo(_Nombre,_Vida){
			Fuerza = _Fuerza;
		}

		void Atacar(Player& player)
		{
    		int VidaNueva = player.get_vida() - Fuerza;
    		player.set_vida(VidaNueva);
    		cout << "El enemigo ataco al jugador" << endl;

		}

};

#endif
