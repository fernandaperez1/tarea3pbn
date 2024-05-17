#include "Pasajero.h"

Pasajero::Pasajero(int destino) : destino(destino) {}

int Pasajero::obtenerDestino() const {
    return destino;
}