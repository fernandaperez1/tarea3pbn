#ifndef PASAJERO_H
#define PASAJERO_H

class Pasajero {
public:
    Pasajero(int destino);
    int getDestino() const;

private:
    int destino;
};

#endif