#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <string>
using namespace std;


class Enemigo {
private:
    string Nombre;
    int Fuerza;
    int Vida;
    int Curacion;
    int Envenenamiento;
    int EnvenenamientoCooldown;
    int Tipo_De_Enemigo;

public:
    Enemigo() {
        Nombre = "Muerto";
        Fuerza = 0;
        Vida = 0;
        Curacion = 0;
        Envenenamiento = 0;
        EnvenenamientoCooldown = 0;
        Tipo_De_Enemigo = 0;
    }

    Enemigo(string _Nombre, int _Fuerza, int _Vida, int _Curacion, int _Envenenamiento, int _EnvenenamientoCooldown, int _Tipo_De_Enemigo) {
        Nombre = _Nombre;
        Fuerza = _Fuerza;
        Vida = _Vida;
        Curacion = _Curacion;
        Envenenamiento = _Envenenamiento;
        EnvenenamientoCooldown = _EnvenenamientoCooldown;
        Tipo_De_Enemigo = _Tipo_De_Enemigo;
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

    int get_Tipo_De_Enemigo() {
        return Tipo_De_Enemigo;
    }

    int get_Envenenamiento() {
        return Envenenamiento;
    }

    int get_EnvenenamientoCooldown() {
        return EnvenenamientoCooldown;
    }

    int get_Fuerza(){
        return Fuerza;
    }


    void Curar(Enemigo& enemy1, Enemigo& enemy2, Enemigo& enemy3) {
        if (enemy1.get_Vida() > 0) {
            int VidaNueva = enemy1.get_Vida() + Curacion;
            enemy1.set_Vida(VidaNueva);
            cout <<"El enemigo curo a sus aliados" << endl;
        }
        if (enemy2.get_Vida() > 0) {
            int VidaNueva = enemy2.get_Vida() + Curacion;
            enemy2.set_Vida(VidaNueva);
            cout <<"El enemigo curo a sus aliados" << endl;
        }
        if (enemy3.get_Vida() > 0) {
            int VidaNueva = enemy3.get_Vida() + Curacion;
            enemy3.set_Vida(VidaNueva);
            cout <<"El enemigo curo a sus aliados" << endl;
        }
    }

};

#endif
