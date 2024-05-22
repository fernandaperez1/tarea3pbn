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
    bool busEnParada(Parada& parada, Bus& bus_actual);

private:
    std::vector<Parada> paradas;
    std::vector<Bus> buses;
    int tiempo;

    void calcularCoeficienteDeBunching() const;
};

#endif