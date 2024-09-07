#include "common.hpp"
#include "vector3d.hpp"

Vector3d::Vector3d() {};

Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}