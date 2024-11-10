#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Enemigo.h"
using namespace std;

class Player {
    private:
        string Nombre;
        int Fuerza;
        int Vida;
        int EnvenenadoEstado;
        int EnvenenadoCooldown;

    public:
        Player() {
            Nombre = "Link";
            Fuerza = 5;
            Vida = 10;
            EnvenenadoEstado = 0;
            EnvenenadoCooldown = 0;
        }

        Player(string _Nombre) {
            Nombre = _Nombre;
            Fuerza = 5;
            Vida = 10;
        }

        void set_Nombre(string _Nombre) {
            Nombre = _Nombre;
        }

        string get_Nombre() {
            return Nombre;
        }

        void set_Vida(int _Vida) {
            Vida = _Vida;
        }

        int get_Vida() {
            return Vida;
        }

        int get_Fuerza(){
            return Fuerza;
        } 

        void set_EnvenenadoEstado(int _EnvenenadoEstado) {
            EnvenenadoEstado = _EnvenenadoEstado;
        }

        void set_EnvenenadoCooldown(int _EnvenenadoCooldown) {
            EnvenenadoCooldown = _EnvenenadoCooldown;
        }

    void Envenenado(Enemigo enemy) {
        if (EnvenenadoEstado == 1) {
            Vida = Vida - enemy.get_Envenenamiento();
            EnvenenadoCooldown = EnvenenadoCooldown - 1;
            if (EnvenenadoCooldown == 0) {
                EnvenenadoEstado = 0;
            }
        }
    }
};

#endif
