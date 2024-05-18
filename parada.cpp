#include "parada.h"
#include <cstdlib>

Parada::Parada(int posicion) : posicion(posicion) {}

void Parada::llegadaPasajero() {
     if (static_cast<double>(rand()) / RAND_MAX < 10.0 / 3600.0) {
        int destino;
        do {
            destino = rand() % 25;  
        } while (destino == posicion);

        pasajeros.emplace_back(destino);
    }
}

int Parada::getPosicion() const {
    return posicion;
}

std::vector<Pasajero>& Parada::pasajerosEsperando() {
    return pasajeros;
}