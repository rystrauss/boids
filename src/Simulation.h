//
// Created by Ryan Strauss on 12/10/19.
//

#ifndef BOIDS_SIMULATION_H
#define BOIDS_SIMULATION_H

#include "Flock.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class Simulation {
private:

    constexpr static float DEFAULT_BOID_SIZE = 3;
    constexpr static float DEFAULT_WINDOW_WIDTH = 800;
    constexpr static float DEFAULT_WINDOW_HEIGHT = 500;
    constexpr static int DEFAULT_NUM_BOIDS = 50;

    sf::RenderWindow window;
    int window_width, window_height;
    Flock flock;
    float boid_size;
    std::vector<sf::CircleShape> shapes;

    void add_boid(float x, float y, bool is_predator = false);

    void render();

    void handle_input();

    float static get_random_float();

public:
    Simulation();

    ~Simulation();

    void run();

};


#endif //BOIDS_SIMULATION_H
