cmake_minimum_required(VERSION 3.15)
project(AeroRoboticsPhysics VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Main Example Simulation
add_executable(quad_sim src/examples/quadrotor_sim.cpp)
