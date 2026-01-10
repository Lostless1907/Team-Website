#pragma once
#include <functional>
#include "Vec3.hpp"

namespace physics {

// Generic RK4 solver for a state vector of size N
// State derivative function signature: f(t, state) -> d_state/dt
template <typename State, typename DerivativeFunc>
State rk4_step(const State& current, double t, double dt, DerivativeFunc func) {
    State k1 = func(t, current);
    State k2 = func(t + 0.5*dt, current + k1 * (0.5*dt));
    State k3 = func(t + 0.5*dt, current + k2 * (0.5*dt));
    State k4 = func(t + dt, current + k3 * dt);

    return current + (k1 + k2*2.0 + k3*2.0 + k4) * (dt / 6.0);
}

}
