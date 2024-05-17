#include "Bus.h"

Bus::Bus(int id, int posicion) : bus_id(id), posicion(posicion), tiempo_de_espera(0) {}

void Bus::mover() {
    if (tiempo_de_espera > 0) {
        --tiempo_de_espera;
        return;
    }
    posicion = (posicion + 5) % 10000;
}

void Bus::parar(Parada& parada) {
    tiempo_de_espera = 5;
    bajarPasajeros(parada);
    subirPasajeros(parada);
}

void Bus::bajarPasajeros(Parada& parada) {
    pasajeros.erase(
        std::remove_if(pasajeros.begin(), pasajeros.end(),
                       [&parada](Pasajero& p) { return p.obtenerDestino() == parada.obtenerPosicion(); }),
        pasajeros.end());
}

void Bus::subirPasajeros(Parada& parada) {
    while (pasajeros.size() < capacidad && !parada.obtenerPasajeros().empty()) {
        pasajeros.push_back(parada.obtenerPasajeros().front());
        parada.obtenerPasajeros().erase(parada.obtenerPasajeros().begin());
        tiempo_de_espera += 2;
    }
}

int Bus::obtenerPosicion() const {
    return posicion;
}

int Bus::obtenerID() const {
    return bus_id;
}

std::vector<Pasajero>& Bus::obtenerPasajeros() {
    return pasajeros;
}
