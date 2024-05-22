#include "parada.h"
#include <cstdlib>
#include <iostream>

Parada::Parada(int posicion) : posicion(posicion) {}

void Parada::llegadaPasajero() {
     if (static_cast<double>(rand()) / RAND_MAX <= 10.0 / 3600.0) {
        int destino;
        do {
            destino = rand() % 25;  
        } while (destino == posicion/400);

        pasajeros.emplace_back(destino);
        //std::cout << "Pasajero llego a la parada " << posicion/400 << " con destino a " << destino << std::endl;
    }
}

int Parada::getPosicion() const {
    return posicion;
}

std::vector<Pasajero>& Parada::pasajerosEsperando() {
    return pasajeros;
}