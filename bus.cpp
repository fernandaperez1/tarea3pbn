#include "Bus.h"

Bus::Bus(int id, int posicion) : bus_id(id), posicion(posicion), tiempo_de_espera(0) {}

void Bus::mover() {
    if (tiempo_de_espera > 0) {
        --tiempo_de_espera;
        return;
    }
    posicion = (posicion + 5) % 10000;
}

void Bus::detener(Parada& parada) {
    tiempo_de_espera = 5;
    bajarPasajeros(parada);
    subirPasajeros(parada);
}

void Bus::bajarPasajeros(Parada& parada) {
    auto i = pasajeros.begin();
    while (i != pasajeros.end()) {
        if (i->getDestino() == parada.getPosicion()) {
            i = pasajeros.erase(i);
        } else {
            ++i;
        }
    }
}

void Bus::subirPasajeros(Parada& parada) {
    while (pasajeros.size() < capacidad && !parada.pasajerosEsperando().empty()) {
        pasajeros.push_back(parada.pasajerosEsperando().front());
        parada.pasajerosEsperando().erase(parada.pasajerosEsperando().begin());
        tiempo_de_espera += 2;
    }
}

int Bus::getPosicion() const {
    return posicion;
}

int Bus::getID() const {
    return bus_id;
}

std::vector<Pasajero>& Bus::pasajerosABordo() {
    return pasajeros;
}
