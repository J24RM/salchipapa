//Creacion 9 nov 2024
//Modificación 29 nov 2024
//Autor: Jesús Rodriguez Mendoza A01713550

//Descripción Clase Padre de los enemigos



#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <string>
#include "Player.h"
using namespace std;
#include <iostream>



class Enemigo {
protected:
    string nombre;
    int vida;

public:
    //Constructores
    Enemigo() {
        nombre = "Muerto";
        vida = 0;
    }

    Enemigo(string _nombre,int _vida) {
        nombre = _nombre;
        vida = _vida;
    }

    //Getters
    string get_Nombre() {
        return nombre;
    }

    int get_Vida() {
        return vida;
    }

    //Setters
    void set_Vida(int _vida) {
        vida = _vida;
    }

    void set_Nombre(string _nombre) {
        nombre = _nombre;
    }

};

#endif
