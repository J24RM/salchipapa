#ifndef MAGO_H
#define MAGO_H
#include <iostream>
#include <string>
#include "Enemigo.h"
using namespace std;

class Mago: public Enemigo{
	private:
		int Magia;

	public:
		Mago():Enemigo(){
			Magia = 0;
		}

		Mago(int _Magia,string _Nombre,int _Vida): Enemigo(_Nombre,_Vida){
			Magia = _Magia;
		}

		int get_Magia(){
			return Magia;
		}

		void Hechizo(Player& player)
		{
			//ACOMODAR
			int VidaNueva = player.get_vida() - 5;
        	Magia -= 3; // Reduce 3 de maná
       		player.set_vida(VidaNueva);
       		cout << Nombre << " lanzó un hechizo contra " << player.get_Nombre() << " causando 5 de daño!" << endl;
    			
		}

		void regenerar_Magia(){
			// El mago regenera 5 de mana de 20 
			Magia = min(20, Magia + 5); // Regenera hasta un máximo de 20
    		cout << Nombre << " regeneró 5 puntos de magia. Magia actual: " << Magia << endl;
		}

};

#endif
