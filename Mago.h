//Creación 23 nov 2024 
//Modificación 29 nov 2024
//Autor: Jesús Rodriguez Mendoza A01713550

//Descripción Clase Hija de Enemigo, El Mago es un tipo de enemgio que ataca con magia, hace más daño que el goblin pero tiene un limite de magia

#ifndef MAGO_H
#define MAGO_H
#include <iostream>
#include <string>
#include "Enemigo.h"
using namespace std;

class Mago: public Enemigo{
	private:
		int magia;

	public:
		//Constructores 
		Mago():Enemigo(){
			magia = 0;
		}

		Mago(int _magia,string _nombre,int _vida): Enemigo(_nombre,_vida){
			magia = _magia;
		}
		//Getter
		int get_Magia(){
			return magia;
		}

		//Metodos

		//Sirve para atacar al enemigo con hechizo, el mago al atacar se le baja 3 de magia, parametro de entrada es al objetivo al que va a atacar
		void Hechizo(Player& player)
		{
			int vida_Nueva = player.get_Vida() - 5;
        	magia -= 3; // Reduce 3 de magia
       		player.set_Vida(vida_Nueva);
       		cout << nombre << " lanzó un hechizo contra " << player.get_Nombre() << " causando 5 de daño!" << endl;
    			
		}

		//Regenera la magia hasta en un maximo de 20.
		void regenerar_Magia(){
			// El mago regenera 5 de mana de 20 
			magia = min(20, magia + 5); // Regenera hasta un máximo de 20
    		cout << nombre << " regeneró 5 puntos de magia. Magia actual: " << magia << endl;
		}

};

#endif
