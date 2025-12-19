#include "mainWindow.hpp"
#include "vector3d.hpp"
#include "vector2d.hpp"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 800

#include "common.hpp"
#include <array>

void MainWindow::applyChoice() {
    switch (selection) {
        case SelectionChoice::TETRAHEDRON:
            tetrahedron();
            break;
        case SelectionChoice::CUBE:
            cube();
            break;
        case SelectionChoice::OCTAHEDRON:
            octahedron();
            break;
        case SelectionChoice::ICOSAHEDRON:
            icosahedron();
            break;
        case SelectionChoice::DODECAHEDRON:
            dodecahedron();
            break;
        case SelectionChoice::SPHERE:
            sphere();
            break;
            /*
        case SelectionChoice::TORUS:
            torus();
            break;
            */
        default:
            // defaults to cube
            cube();
            break;
    }
}

void MainWindow::sphere() {
    // Cube centered on 0.0
    this->window->setTitle("Sphere");
    
    this->vertices.clear();

    int n = 32;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double theta = ((double) i / (double) n) * M_PI - M_PI * 0.5;
            double phi = ((double) j / (double) n) * 2.0 * M_PI - M_PI;

            double x = cos(theta) * cos(phi);
            double y = cos(theta) * sin(phi);
            double z = sin(theta);

            this->vertices.push_back(Vertex(x, y, z));
        }
    }
    this->vertices.push_back(Vertex(0.0,0.0,1.0));

    this->projectedVertices.resize(this->vertices.size());

    this->edges.clear();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            int k = i * n + j;

            this->edges.push_back(std::make_tuple(k,k+n));
            this->edges.push_back(std::make_tuple(k,k+1));
        }
        int k = i * n + (n - 1);
        int k2 = i * n;
        
        this->edges.push_back(std::make_tuple(k,k+n));
        this->edges.push_back(std::make_tuple(k,k2));
    }

    // cap
    for (int j = 0; j < n - 1; ++j) {
        int k = (n - 1) * n + j;
        int k2 = n * n;

        this->edges.push_back(std::make_tuple(k,k+1));
        this->edges.push_back(std::make_tuple(k,k2));
    }
    int k = (n - 1) * n + (n - 1);
    int k2 = (n - 1) * n;
    int k3 = n * n;

    this->edges.push_back(std::make_tuple(k,k2));
    this->edges.push_back(std::make_tuple(k,k3));
}

void MainWindow::torus() {
    // Cube centered on 0.0
    this->window->setTitle("Torus");
    
    this->vertices.clear();

    double R = 1.0;
    double r = 0.5;

    int n_i = 16;
    int n_j = 32;
    
    for (int i = 0; i < n_i; ++i) {
        for (int j = 0; j < n_j; ++j) {
            double theta = ((double) i / (double) n_i) * 2.0 * M_PI;
            double phi = ((double) j / (double) n_j) * 2.0 * M_PI;

            double x = (R + r * cos(theta)) * cos(phi);
            double y = (R + r * cos(theta)) * sin(phi);
            double z = r * sin(theta);

            this->vertices.push_back(Vertex(x, y, z));
        }
    }

    this->projectedVertices.resize(this->vertices.size());
    this->edges.clear();

    for (int i = 0; i < n_i - 1; ++i) {
        for (int j = 0; j < n_j - 1; ++j) {
            int k = i * n_i + j;

            this->edges.push_back(std::make_tuple(k,k+n_j));
            this->edges.push_back(std::make_tuple(k,k+1));
        }
        int k = i * n_i + (n_j - 1);
        int k2 = i * n_i;
        
        this->edges.push_back(std::make_tuple(k,k+n_j));
        this->edges.push_back(std::make_tuple(k,k2));
    }
}

void MainWindow::cube() {
    // Cube centered on 0.0
    this->window->setTitle("Cube");
    
    this->vertices.clear();
    
    for (int i = 0; i < 8; ++i) {
        this->vertices.push_back(Vertex(-0.5 + 1.0 * ((i / 4) % 2), -0.5 + 1.0 * ((i / 2) % 2), -0.5 + 1.0 * (i % 2)));
    }

    this->projectedVertices.resize(8);

    this->edges.clear();

    this->edges.push_back(std::make_tuple(0, 1));
    this->edges.push_back(std::make_tuple(1, 3));
    this->edges.push_back(std::make_tuple(3, 2));
    this->edges.push_back(std::make_tuple(2, 0));

    this->edges.push_back(std::make_tuple(4, 5));
    this->edges.push_back(std::make_tuple(5, 7));
    this->edges.push_back(std::make_tuple(7, 6));
    this->edges.push_back(std::make_tuple(6, 4));

    this->edges.push_back(std::make_tuple(6, 2));
    this->edges.push_back(std::make_tuple(7, 3));
    this->edges.push_back(std::make_tuple(5, 1));
    this->edges.push_back(std::make_tuple(4, 0));
}

void MainWindow::tetrahedron() {
    // Tetrahedron centered on 0.0
    this->window->setTitle("Tetrahedron");
    
    this->vertices.clear();
    
    this->vertices.push_back(Vertex(-0.5, 0.0, -sqrt(2) / 4.0));
    this->vertices.push_back(Vertex(0.5, 0.0, -sqrt(2) / 4.0));
    
    this->vertices.push_back(Vertex(0.0, -0.5, sqrt(2) / 4.0));
    this->vertices.push_back(Vertex(0.0, 0.5, sqrt(2) / 4.0));
    
    this->projectedVertices.resize(4);

    this->edges.clear();

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            this->edges.push_back(std::make_tuple(i, j));
        }
    }
}

void MainWindow::octahedron() {
    // Octahedron centered on 0.0
    this->window->setTitle("Octahedron");
    
    this->vertices.clear();
    
    this->vertices.push_back(Vertex(-sqrt(2) / 2.0, 0.0, 0.0));
    this->vertices.push_back(Vertex(sqrt(2) / 2.0, 0.0, 0.0));
    
    this->vertices.push_back(Vertex(0.0, -sqrt(2) / 2.0, 0.0));
    this->vertices.push_back(Vertex(0.0, sqrt(2) / 2.0, 0.0));

    this->vertices.push_back(Vertex(0.0, 0.0, -sqrt(2) / 2.0));
    this->vertices.push_back(Vertex(0.0, 0.0, sqrt(2) / 2.0));

    this->projectedVertices.resize(6);

    this->edges.clear();

    this->edges.push_back(std::make_tuple(0, 4));
    this->edges.push_back(std::make_tuple(0, 5));

    this->edges.push_back(std::make_tuple(0, 2));
    this->edges.push_back(std::make_tuple(0, 3));

    this->edges.push_back(std::make_tuple(1, 4));
    this->edges.push_back(std::make_tuple(1, 5));

    this->edges.push_back(std::make_tuple(1, 2));
    this->edges.push_back(std::make_tuple(1, 3));

    this->edges.push_back(std::make_tuple(2, 4));
    this->edges.push_back(std::make_tuple(2, 5));

    this->edges.push_back(std::make_tuple(3, 4));
    this->edges.push_back(std::make_tuple(3, 5));
}

void MainWindow::icosahedron() {
    // Dodecahedron centered on 0.0
    this->window->setTitle("Icosahedron");
    
    this->vertices.clear();

    double phi = (1.0 + sqrt(5.0)) * 0.5;

    for (int i = 0; i < 4; ++i) {
        this->vertices.push_back(Vertex(0.0, -0.5 + 1.0 * ((i / 2) % 2), -phi / 2.0 + phi * (i % 2)));
    }

    for (int i = 0; i < 4; ++i) {
        this->vertices.push_back(Vertex(-0.5 + 1.0 * ((i / 2) % 2), -phi / 2.0 + phi * (i % 2), 0.0));
    }

    for (int i = 0; i < 4; ++i) {
        this->vertices.push_back(Vertex(-phi / 2.0 + phi * (i % 2), 0.0, -0.5 + 1.0 * ((i / 2) % 2)));
    }

    this->projectedVertices.resize(12);

    this->edges.clear();

    this->edges.push_back(std::make_tuple(0, 2));
    this->edges.push_back(std::make_tuple(0, 4));
    this->edges.push_back(std::make_tuple(0, 6));
    this->edges.push_back(std::make_tuple(0, 8));
    this->edges.push_back(std::make_tuple(0, 9));
    this->edges.push_back(std::make_tuple(1, 3));
    this->edges.push_back(std::make_tuple(1, 4));
    this->edges.push_back(std::make_tuple(1, 6));
    this->edges.push_back(std::make_tuple(1, 10));
    this->edges.push_back(std::make_tuple(1, 11));
    this->edges.push_back(std::make_tuple(2, 5));
    this->edges.push_back(std::make_tuple(2, 7));
    this->edges.push_back(std::make_tuple(2, 8));
    this->edges.push_back(std::make_tuple(2, 9));
    this->edges.push_back(std::make_tuple(3, 5));
    this->edges.push_back(std::make_tuple(3, 7));
    this->edges.push_back(std::make_tuple(3, 10));
    this->edges.push_back(std::make_tuple(3, 11));
    this->edges.push_back(std::make_tuple(4, 6));
    this->edges.push_back(std::make_tuple(4, 8));
    this->edges.push_back(std::make_tuple(4, 10));
    this->edges.push_back(std::make_tuple(5, 7));
    this->edges.push_back(std::make_tuple(5, 8));
    this->edges.push_back(std::make_tuple(5, 10));
    this->edges.push_back(std::make_tuple(6, 9));
    this->edges.push_back(std::make_tuple(6, 11));
    this->edges.push_back(std::make_tuple(7, 9));
    this->edges.push_back(std::make_tuple(7, 11));
    this->edges.push_back(std::make_tuple(8, 10));
    this->edges.push_back(std::make_tuple(9, 11));
}

void MainWindow::dodecahedron() {
    // Dodecahedron centered on 0.0
    this->window->setTitle("Dodecahedron");
    
    this->vertices.clear();

    double phi = (1.0 + sqrt(5.0)) * 0.5;

    for (int i = 0; i < 8; ++i) {
        this->vertices.push_back(Vertex(-phi / 2.0 + phi * ((i / 4) % 2), -phi / 2.0 + phi * ((i / 2) % 2), -phi / 2.0 + phi * (i % 2)));
    }

    for (int i = 0; i < 4; ++i) {
        this->vertices.push_back(Vertex(0.0, (-phi + 2.0 * phi * ((i / 2) % 2)) * phi * 0.5, -0.5 + 1.0 * (i % 2)));
    }

    for (int i = 0; i < 4; ++i) {
        this->vertices.push_back(Vertex(-0.5 + 1.0 * (i % 2), 0.0, (-phi + 2.0 * phi * ((i / 2) % 2)) * phi * 0.5));
    }

    for (int i = 0; i < 4; ++i) {
        this->vertices.push_back(Vertex((-phi + 2.0 * phi * ((i / 2) % 2)) * phi * 0.5, -0.5 + 1.0 * (i % 2), 0.0));
    }

    this->projectedVertices.resize(20);

    this->edges.clear();

    this->edges.push_back(std::make_tuple(0, 8));
    this->edges.push_back(std::make_tuple(0, 12));
    this->edges.push_back(std::make_tuple(0, 16));
    this->edges.push_back(std::make_tuple(1, 9));
    this->edges.push_back(std::make_tuple(1, 14));
    this->edges.push_back(std::make_tuple(1, 16));
    this->edges.push_back(std::make_tuple(2, 10));
    this->edges.push_back(std::make_tuple(2, 12));
    this->edges.push_back(std::make_tuple(2, 17));
    this->edges.push_back(std::make_tuple(3, 11));
    this->edges.push_back(std::make_tuple(3, 14));
    this->edges.push_back(std::make_tuple(3, 17));

    this->edges.push_back(std::make_tuple(4, 8));
    this->edges.push_back(std::make_tuple(4, 13));
    this->edges.push_back(std::make_tuple(4, 18));

    this->edges.push_back(std::make_tuple(5, 9));
    this->edges.push_back(std::make_tuple(5, 15));
    this->edges.push_back(std::make_tuple(5, 18));

    this->edges.push_back(std::make_tuple(6, 10));
    this->edges.push_back(std::make_tuple(6, 13));
    this->edges.push_back(std::make_tuple(6, 19));

    this->edges.push_back(std::make_tuple(7, 11));
    this->edges.push_back(std::make_tuple(7, 15));
    this->edges.push_back(std::make_tuple(7, 19));

    this->edges.push_back(std::make_tuple(8, 9));

    this->edges.push_back(std::make_tuple(10, 11));
    this->edges.push_back(std::make_tuple(12, 13));
    this->edges.push_back(std::make_tuple(14, 15));
    this->edges.push_back(std::make_tuple(16, 17));
    this->edges.push_back(std::make_tuple(18, 19));
}

MainWindow::MainWindow() {

}

int MainWindow::start() {
    this->setup();
    while (window->isOpen()) {
        this->processInput();

        this->theta1 += 0.005;
        this->theta2 += 0.015;
        this->theta3 += 0.01;

        for (int i = 0; i < vertices.size(); ++i) {
            projectedVertices[i] = project(this->vertices[i]);
        }

        this->render();
    }

    return 0;
}

Vector2d MainWindow::project(const Vector3d& src) {
    double x = src.x;
    double y = src.y;
    double z = src.z;

    double cos_alpha = cos(alpha);
    double sin_alpha = sin(alpha);

    double cos_theta1 = cos(theta1);
    double sin_theta1 = sin(theta1);

    double cos_theta2 = cos(theta2);
    double sin_theta2 = sin(theta2);

    double cos_theta3 = cos(theta3);
    double sin_theta3 = sin(theta3);

    double x_2 = x * cos_theta2 * cos_theta3 
    + y * (sin_theta1 * sin_theta2 * cos_theta3 + sin_theta3 * cos_theta1)
    + z * (sin_theta1 * sin_theta3 - sin_theta2 * cos_theta1 * cos_theta3)
    + 0.5 * (x * sin_theta2 - y * sin_theta1 * cos_theta2 + z * cos_theta1 * cos_theta2) * cos_alpha;
    
    double y_2 = -x * sin_theta3 * cos_theta2
    + y * (-sin_theta1 * sin_theta2 * sin_theta3 + cos_theta1 * cos_theta3)
    + z * (sin_theta1 * cos_theta3 + sin_theta2 * sin_theta3 * cos_theta1)
    + 0.5 * (x * sin_theta2 - y * sin_theta1 * cos_theta2 + z * cos_theta1 * cos_theta2) * sin_alpha;

    return Vector2d(x_2, y_2);
}

void MainWindow::drawLine(Vertex2 v1, Vertex2 v2) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(v1.x * 250.0f + 400.0f, v1.y * 250.0f + 400.0f);
    line[0].color  = sf::Color::White;  

    line[1].position = sf::Vector2f(v2.x * 250.0f + 400.0f, v2.y * 250.0f + 400.0f);
    line[1].color = sf::Color::White;

    window->draw(line, 2, sf::Lines);
}

void MainWindow::setup() {
    this->window = new sf::RenderWindow(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "Cube", sf::Style::Default);
    this->window->setFramerateLimit(60);

    selection = SelectionChoice::CUBE;
    applyChoice();

    this->alpha = M_PI / 3.0;

    this->theta1 = 0.0;
    this->theta2 = 0.0;
    this->theta3 = 0.0;
}
void MainWindow::processInput() {
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Key::Left) {
                selection = (SelectionChoice) (((int)(selection) + 7) % 6);
                applyChoice();
            }

            if (event.key.code == sf::Keyboard::Key::Right) {
                selection = (SelectionChoice) (((int)(selection) + 1) % 6);
                applyChoice();
            }
        }
    }
}
void MainWindow::render() {
    window->clear(sf::Color::Black);

    for (int i = 0; i < projectedVertices.size(); ++i) {
        sf::CircleShape shape(2.0f);

        shape.setFillColor(sf::Color::White);
        shape.setPosition(sf::Vector2f(projectedVertices[i].x * 250.0f + 400.0f - 2.0f, projectedVertices[i].y * 250.0f + 400.0f - 2.0f));
    
        window->draw(shape);
    }

    for (int i = 0; i < edges.size(); ++i) {
        drawLine(projectedVertices[std::get<0>(edges[i])], projectedVertices[std::get<1>(edges[i])]);
    }
    window->display();
}
