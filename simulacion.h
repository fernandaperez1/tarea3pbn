#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "bus.h"
#include "parada.h"

class Simulacion {
public:
    Simulacion();
    void comenzarSimulacion(int tiempo_total);
    void estadoSimulacion();

private:
    std::vector<Parada> paradas;
    std::vector<Bus> buses;
    int tiempo;

    void calcularCoeficienteDeBunching() const;
};

#endif
