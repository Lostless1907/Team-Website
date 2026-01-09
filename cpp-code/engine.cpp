#include <emscripten.h>
#include "InverseMatrix.hpp" // Ensure this matches your .hpp filename

// Global state for the Inverse Matrix engine
double altitude = 0.0;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    void init_sim(double initial_z) {
        altitude = initial_z;
    }

    EMSCRIPTEN_KEEPALIVE
    double step_physics(double dt, double thrust) {
        // Simple physics logic until you expand your .hpp
        altitude += (thrust - 9.8) * dt;
        if (altitude < 0) altitude = 0;
        return altitude;
    }

    int main() {
        return 0;
    }
}
