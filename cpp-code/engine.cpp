#include <emscripten.h>
#include "physics/Vec3.hpp"
#include "physics/integrators.hpp"
// #include "control/pid.hpp"  // Uncomment if you have this file

// Global state for the Inverse Matrix engine
double altitude = 0.0;
double velocity = 0.0;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    void init_sim(double initial_z) {
        altitude = initial_z;
        velocity = 0.0;
    }
    
    EMSCRIPTEN_KEEPALIVE
    double step_physics(double dt, double thrust) {
        // Simple physics: F = ma, a = F/m - g
        const double mass = 1.0;  // kg
        const double g = 9.81;    // gravity
        
        // Calculate acceleration
        double accel = (thrust / mass) - g;
        
        // Update velocity and position
        velocity += accel * dt;
        altitude += velocity * dt;
        
        // Ground constraint
        if (altitude < 0) {
            altitude = 0;
            velocity = 0;
        }
        
        return altitude;
    }
    
    EMSCRIPTEN_KEEPALIVE
    double get_velocity() {
        return velocity;
    }
    
    EMSCRIPTEN_KEEPALIVE
    double get_altitude() {
        return altitude;
    }
    
    int main() {
        return 0;
    }
}
