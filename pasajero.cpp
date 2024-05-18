#include "Pasajero.h"

Pasajero::Pasajero(int destino) : destino(destino) {}

int Pasajero::getDestino() const {
    return destino;
}