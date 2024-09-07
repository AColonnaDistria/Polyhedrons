#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "vector3d.hpp"
#include "vector2d.hpp"

#include <array>
#include <tuple>

enum class SelectionChoice {
    TETRAHEDRON = 0,
    CUBE = 1,
    OCTAHEDRON = 2,
    ICOSAHEDRON = 3,
    DODECAHEDRON = 4,
    SPHERE = 5,
};

class MainWindow {
    sf::RenderWindow* window;

    SelectionChoice selection;

    std::vector<Vertex> vertices;
    std::vector<Vertex2> projectedVertices;

    std::vector<std::tuple<int, int>> edges;
    Angle theta1;
    Angle theta2;
    Angle theta3;

    Angle alpha;

public:
    MainWindow();
    int start();

private:
    void setup();
    void processInput();
    void render();

    void drawLine(Vertex2 v1, Vertex2 v2);
    Vector2d project(const Vector3d& src);

    void icosahedron();
    void dodecahedron();
    void octahedron();
    void tetrahedron();
    void sphere();
    void torus();
    void cube();

    void applyChoice();
};