//Creacion 9 nov 2024
//Modificación 29 nov 2024
//Autor: Jesús Rodriguez Mendoza A01713550

//Descripción: Clase del jugador, en esta clase se maneja todo lo que tenga que ver con el jugador
//el ataque del jugador se hace desde el main por que si llamo a la clase enemigo aqui se crea una dependencia circular

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player {
    private:
        string nombre;
        int fuerza;
        int vida;

    public:
        //Constructores
        Player() {
            nombre = "Link";
            fuerza = 5;
            vida = 50;

        }

        //Setters
        void set_Nombre(string _vombre) {
            nombre = _vombre;
        }

        void set_Vida(int _vida) {
            vida = _vida;
        }

        //Getters

         string get_Nombre(){
            return nombre;
         }

        int get_Vida() {
            return vida;
        }

        int get_Fuerza(){
            return fuerza;
        } 
    
};

#endif

