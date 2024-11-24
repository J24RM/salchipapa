#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <string>
#include "Player.h"
using namespace std;
#include <iostream>



class Enemigo {
protected:
    string Nombre;
    int Vida;

public:
    Enemigo() {
        Nombre = "Muerto";
        Vida = 0;
    }

    Enemigo(string _Nombre,int _Vida) {
        Nombre = _Nombre;
        Vida = _Vida;
    }

    //Getters
    string get_Nombre() {
        return Nombre;
    }

    int get_Vida() {
        return Vida;
    }

    //Setters
    void set_Vida(int _Vida) {
        Vida = _Vida;
    }

    void set_Nombre(string _Nombre) {
        Nombre = _Nombre;
    }

};

#endif
