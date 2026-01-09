#include <emscripten.h>
#include "InverseMatrix.hpp" // Replace with your actual .hpp filename

// This is the "Engine Room"
extern "C" {

    EMSCRIPTEN_KEEPALIVE
    void init_sim(double initial_z) {
        // This calls the setup from your header files
        // Example: reset_vectors(); 
    }

    EMSCRIPTEN_KEEPALIVE
    double step_physics(double dt, double thrust) {
        // This is where your high-IQ math happens
        // It returns the altitude to the JavaScript
        return 10.5; // Placeholder for your actual logic
    }

    int main() {
        return 0;
    }
}
