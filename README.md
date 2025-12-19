## Polyhedron 3d viewer

This project is a simple C++ application using the SFML for graphics. It demonstrates the wireframe projection and rotation of various 3D shapes onto a 2D screen.

## Prerequisites

You need a C++ compiler and the SFML library installed and configured for your project environment

## Compilation

Run

```bash
g++ main.cpp mainWindow.cpp vector3d.cpp vector2d.cpp -o polyhedron -lsfml-graphics -lsfml-window -lsfml-system
```

## Usage

To compute the projections, I just used sympy in order to compute linear transformations and then put it in my code rather than relying an external library.

In order to navigate between polyhedrons, use the left and right keys of the keyboard.

## Video

[![Watch the video](https://img.youtube.com/vi/OPk1zP_mg0c/maxresdefault.jpg)](https://youtu.be/OPk1zP_mg0c)

## Illustrations

Tetrahedron:
![alt text](readme-images/tetrahedron.png "Tetrahedron")

Cube:
![alt text](readme-images/cube.png "Cube")

Octahedron:
![alt text](readme-images/octahedron.png "Octahedron")

Icosahedron:
![alt text](readme-images/icosahedron.png "Icosahedron")

Sphere:
![alt text](readme-images/sphere.png "Sphere")

