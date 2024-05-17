#include "parada.h"
#include <random>

Parada::Parada(int posicion) : posicion(posicion) {}

void Parada::llegadaPasajero() {
    static std::default_random_engine generador;
    static std::uniform_real_distribution<double> distribucion(0.0, 1.0);

    if (distribucion(generador) < 10.0 / 3600.0) {
        static std::uniform_int_distribution<int> paradas_disponibles(0, 24);
        int destino;
        do {
            destino = paradas_disponibles(generador);
        } while (destino == posicion);

        pasajeros.emplace_back(destino);
    }
}

int Parada::obtenerPosicion() const {
    return posicion;
}

std::vector<Pasajero>& Parada::obtenerPasajeros() {
    return pasajeros;
}