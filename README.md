This project is a simple C++ application using the SFML (Simple and Fast Multimedia Library) for graphics. It demonstrates the wireframe projection and rotation of various 3D shapes onto a 2D screen.

Features

    Multiple 3D Shapes: Renders the wireframe of several standard 3D shapes and surfaces:

        Platonic Solids: Tetrahedron, Cube, Octahedron, Icosahedron, Dodecahedron.

        Surfaces: Sphere.

    3D Rotation: All shapes rotate continuously around the X,Y, and Z axes (theta1, theta2, theta3) for a dynamic visual effect.

    Shape Switching: Allows switching between the different shapes at runtime.

    Simple Projection: Implements a custom 3D-to-2D projection function (MainWindow::project) that includes rotation logic.

How to Run

Prerequisites

You need a C++ compiler and the SFML library installed and configured for your project environment.

    SFML (Simple and Fast Multimedia Library): Version 2.5 or later is generally recommended.

Building

The project is split into several source files. Compile all .cpp files and link them with the SFML libraries (specifically the sfml-graphics, sfml-window, and sfml-system modules).

Compilation Command Example (for Linux/macOS using g++):
```bash
g++ -o 3d_projector main.cpp mainWindow.cpp vector2d.cpp vector3d.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

Controls

The application starts by displaying a Cube.
Key	Action
Left Arrow	Cycle to the previous shape in the SelectionChoice enum.
Right Arrow	Cycle to the next shape in the SelectionChoice enum.
Close Window	Exit the application.

Project Structure

File	Description
main.cpp	Main entry point. Initializes the MainWindow and starts the main loop.
mainWindow.hpp	Header for the MainWindow class. Defines the core structure, variables, and methods (setup, input, rendering, shape generation, projection).
mainWindow.cpp	Implementation of the MainWindow class. Contains the main loop, shape generation functions (cube(), sphere(), etc.), and the 3D projection logic.
vector3d.hpp	Defines the Vector3d structure (aliased as Vertex) for 3D coordinates and the Angle type.
vector3d.cpp	Implementation for Vector3d.
vector2d.hpp	Defines the Vector2d structure (aliased as Vertex2) for 2D projected coordinates.
vector2d.cpp	Implementation for Vector2d.
common.hpp	Contains common includes and definitions (like <cmath> for M_PI and math functions).

Implementation Details

The core of the 3D rendering is in the MainWindow::project method, which takes a Vector3d and returns a Vector2d by applying a series of rotations and a final oblique/parallel-like projection (based on the formula used).

The rotation is applied incrementally in the MainWindow::start loop using three angles (theta1, theta2, theta3) for the three axes.
C++

// Rotation and Projection logic in MainWindow::project
// ... (rotations by theta1, theta2, theta3) ...
// The final projection includes the 'alpha' perspective factor
// ... + 0.5 * (x * sin_theta2 - y * sin_theta1 * cos_theta2 + z * cos_theta1 * cos_theta2) * cos_alpha;
// ... + 0.5 * (x * sin_theta2 - y * sin_theta1 * cos_theta2 + z * cos_theta1 * cos_theta2) * sin_alpha;

The rendering draws the vertices as small circles and the edges (stored as pairs of vertex indices) as lines using SFML's sf::Lines primitive.
