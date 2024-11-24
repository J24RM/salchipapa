#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player {
    private:
        string Nombre;
        int Fuerza;
        int Vida;

    public:
        Player() {
            Nombre = "Link";
            Fuerza = 10;
            Vida = 1;

        }

        //Setters
        void set_Nombre(string _Nombre) {
            Nombre = _Nombre;
        }

        void set_vida(int _Vida) {
            Vida = _Vida;
        }

        //Getters

         string get_Nombre(){
            return Nombre;
         }

        int get_vida() {
            return Vida;
        }

        int get_Fuerza(){
            return Fuerza;
        } 
    
};

#endif
