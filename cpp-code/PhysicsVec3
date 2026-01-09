#pragma once
#include <cmath>

namespace physics {

template <typename T>
struct Vector3 {
    T x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

    Vector3 operator+(const Vector3& other) const { return {x + other.x, y + other.y, z + other.z}; }
    Vector3 operator-(const Vector3& other) const { return {x - other.x, y - other.y, z - other.z}; }
    Vector3 operator*(T scalar) const { return {x * scalar, y * scalar, z * scalar}; }
    
    T magnitude() const { return std::sqrt(x*x + y*y + z*z); }
    
    Vector3 normalized() const {
        T mag = magnitude();
        return (mag > 0) ? Vector3(x/mag, y/mag, z/mag) : Vector3();
    }
};

} // namespace physics
