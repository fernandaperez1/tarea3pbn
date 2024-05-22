#include "bus.h"
#include <iostream>

Bus::Bus(int id, int posicion) : bus_id(id), posicion(posicion), tiempo_de_espera(0) {}

void Bus::mover() {
    if (tiempo_de_espera > 0) {
        tiempo_de_espera--;
        return;
    }
    posicion += 5;
    if (posicion >= 10000) {
        posicion -= 10000;
    }
    if (posicion % 400 == 0) {
        tiempo_de_espera = 10;
    }
}

void Bus::detener(Parada& parada) {
    bajarPasajeros(parada);
    subirPasajeros(parada);
}

void Bus::bajarPasajeros(Parada& parada) {
    auto it = pasajeros.begin();
    while (it != pasajeros.end()) {
        if (it->getDestino() == parada.getPosicion()/400) {
            it = pasajeros.erase(it);
            //std::cout << "se bajo un pasajero" << std::endl;
        } else {
            ++it;
        }
    }
}

void Bus::subirPasajeros(Parada& parada) {
    auto& pasajeros_esperando = parada.pasajerosEsperando();
    auto it = pasajeros_esperando.begin();
    
    while (pasajeros.size() < capacidad && it != pasajeros_esperando.end()) {
        pasajeros.push_back(*it);
        it = pasajeros_esperando.erase(it);
        tiempo_de_espera += 2;
        //std::cout << "Bus " << getID() << " cargo un pasajero en parada " << parada.getPosicion() << std::endl;
    }
}

int Bus::getTiempoDeEspera() {
    return tiempo_de_espera;
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