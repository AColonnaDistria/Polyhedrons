#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

typedef double Angle;

struct Vector3d {
    double x;
    double y;
    double z;

    Vector3d();
    Vector3d(double x, double y, double z);
    //int operator=(Vector3d v);
};
typedef Vector3d Vertex;

#endif