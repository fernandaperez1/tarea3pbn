#ifndef PARADA_H
#define PARADA_H

#include <vector>
#include "pasajero.h"

class Parada {
public:
    Parada(int posicion);
    void llegadaPasajero();
    int getPosicion() const;
    std::vector<Pasajero>& pasajerosEsperando();

private:
    int posicion;
    std::vector<Pasajero> pasajeros;
};

#endif