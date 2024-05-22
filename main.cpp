#include "simulacion.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Simulacion sim;
    sim.comenzarSimulacion(43200);
    return 0;
}