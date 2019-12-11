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

    sf::RenderWindow window;
    int window_width, window_height;
    Flock flock;
    std::vector<sf::CircleShape> shapes;

    float max_speed, max_force;
    float acceleration_scale;
    float cohesion_weight, alignment_weight, separation_weight;

    void add_boid(float x, float y, bool is_predator = false);

    void render();

    bool handle_input();

    float static get_random_float();

public:
    constexpr static float DEFAULT_BOID_SIZE = 3;
    constexpr static int DEFAULT_WINDOW_WIDTH = 800;
    constexpr static int DEFAULT_WINDOW_HEIGHT = 500;
    constexpr static int DEFAULT_FLOCK_SIZE = 50;

    constexpr static float DEFAULT_MAX_SPEED = 3.5;
    constexpr static float DEFAULT_MAX_FORCE = 0.5;
    constexpr static float DEFAULT_ALIGNMENT_WEIGHT = 1.0;
    constexpr static float DEFAULT_COHESION_WEIGHT = 1.0;
    constexpr static float DEFAULT_SEPARATION_WEIGHT = 1.5;
    constexpr static float DEFAULT_ACCELERATION_SCALE = 0.4;

    Simulation(int window_width, int window_height, float max_speed, float max_force,
               float alignment_weight, float cohesion_weight, float separation_weight, float acceleration_scale);

    ~Simulation();

    void run(int flock_size);

};


#endif //BOIDS_SIMULATION_H
