#ifndef BUS_H
#define BUS_H

#include <vector>
#include "pasajero.h"
#include "parada.h"

class Bus {
public:
    Bus(int id, int posicion);
    void mover();
    void detener(Parada& parada);
    int getPosicion() const;
    int getID() const;
    int getTiempoDeEspera();
    std::vector<Pasajero>& pasajerosABordo();

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