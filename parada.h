#ifndef PARADA_H
#define PARADA_H

#include <vector>
#include "pasajero.h"

class Parada {
public:
    Parada(int posicion);
    void llegadaPasajero();
    int obtenerPosicion() const;
    std::vector<Pasajero>& obtenerPasajeros();

private:
    int posicion;
    std::vector<Pasajero> pasajeros;
};

#endif
