#include "simulacion.h"
#include <iostream>
#include <algorithm>
#include <cmath>

Simulacion::Simulacion() : tiempo(0) {
    for (int i = 0; i < 25; i++) {
        paradas.emplace_back(i * 400);
    }
    for (int i = 0; i < 4; i++) {
        buses.emplace_back(i+1, i * 2500);
    }
}

bool Simulacion::busEnParada(Parada& parada, Bus& bus_actual) {
    for (auto& bus : buses){
        if (bus.getPosicion() == parada.getPosicion() && bus_actual.getID() != bus.getID()){
            return true;
        }
    }
    return false;
}

void Simulacion::comenzarSimulacion(int tiempo_total) {
    for (int t = 0; t <= tiempo_total; t++) {
        tiempo = t;

        if (tiempo % 3600 == 0) {
            estadoSimulacion();
        }

        for (auto& parada : paradas) {
            parada.llegadaPasajero();
        }

        for (auto& bus : buses) {
            if (bus.getPosicion() % 400 == 0 && bus.getTiempoDeEspera() == 0) {
                bus.detener(paradas[bus.getPosicion() / 400]);
            }
            bus.mover();
        }
    }
}

void Simulacion::estadoSimulacion(){
    std::cout << "Hora: " << tiempo / 3600 << std::endl;
    for (auto& parada : paradas) {
        std::cout << "Parada " << parada.getPosicion()/400 + 1 << ": " << parada.pasajerosEsperando().size() << " pasajeros esperando" << std::endl;
    }
    for (auto& bus : buses) {
        std::cout << "Bus " << bus.getID() << ": Posicion " << bus.getPosicion() << ", " << bus.pasajerosABordo().size() << " pasajeros a bordo" << std::endl;
    }
    calcularCoeficienteDeBunching();
}

void Simulacion::calcularCoeficienteDeBunching() const{
    std::vector<int> posiciones;
    for (auto& bus : buses) {
        posiciones.push_back(bus.getPosicion());
    }
    std::sort(posiciones.begin(), posiciones.end());

    std::vector<int> distancias;
    for (size_t i = 0; i < posiciones.size(); ++i) {
        distancias.push_back((posiciones[(i + 1) % posiciones.size()] - posiciones[i] + 10000) % 10000);
    }
    double suma_dist = 0.0;
    for (auto& distancia : distancias) {
        suma_dist += distancia;
    }
    double S = suma_dist / distancias.size();
    double suma_dist_cuadrado = 0.0;
    for (auto& distancia : distancias) {
        suma_dist_cuadrado += std::pow(distancia, 2);
    }
    double Q = suma_dist_cuadrado / distancias.size();
    double C = std::sqrt(Q - std::pow(S, 2)) / S;

    if (S == 0){
        std::cout << "Coeficiente de bunching: " << "1.73205. Los 4 buses se encuentran en la misma posicion." << std::endl;
    }else{
        std::cout << "Coeficiente de bunching: " << C << std::endl;
    }
}