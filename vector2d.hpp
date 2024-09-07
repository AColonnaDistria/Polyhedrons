#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

struct Vector2d {
    double x;
    double y;

    Vector2d();
    Vector2d(double x, double y);
    //int operator=(Vector3d v);
};
typedef Vector2d Vertex2;

#endif