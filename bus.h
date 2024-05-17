#ifndef BUS_H
#define BUS_H

#include <vector>
#include "Pasajero.h"
#include "Parada.h"

class Bus {
public:
    Bus(int id, int posicion);
    void mover();
    void parar(Parada& parada);
    int obtenerPosicion() const;
    int obtenerID() const;
    std::vector<Pasajero>& obtenerPasajeros();

private:
    int bus_id;
    int posicion;
    std::vector<Pasajero> pasajeros;
    int tiempo_de_espera;
    static const int capacidad = 40;

    void bajarPasajeros(Parada& parada);
    void subirPasajeros(Parada& parada);
};

#endif
