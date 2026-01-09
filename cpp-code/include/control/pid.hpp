#pragma once
#include <algorithm>

namespace control {

class PID {
public:
    PID(double kp, double ki, double kd, double max_out)
        : kp_(kp), ki_(ki), kd_(kd), max_out_(max_out) {}

    double update(double setpoint, double measurement, double dt) {
        double error = setpoint - measurement;
        integral_ += error * dt;
        double derivative = (error - prev_error_) / dt;

        // Anti-windup clamping
        integral_ = std::max(-max_out_, std::min(integral_, max_out_));

        double output = (kp_ * error) + (ki_ * integral_) + (kd_ * derivative);
        
        // Output clamping
        output = std::max(-max_out_, std::min(output, max_out_));

        prev_error_ = error;
        return output;
    }

private:
    double kp_, ki_, kd_, max_out_;
    double integral_ = 0.0;
    double prev_error_ = 0.0;
};

} // namespace control
