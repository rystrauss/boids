//
// Created by Ryan Strauss on 12/10/19.
//

#ifndef BOIDS_SIMULATION_H
#define BOIDS_SIMULATION_H

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Flock.h"

class Simulation {
private:

    sf::RenderWindow window;
    int window_width, window_height;
    Flock flock;
    std::vector<sf::CircleShape> shapes;

    float max_speed, max_force;
    float acceleration_scale;
    float perception, separation_distance;
    float cohesion_weight, alignment_weight, separation_weight;

    void add_boid(float x, float y, bool is_predator = false);

    void render();

    bool handle_input();

    float static get_random_float();

public:
    constexpr static int FRAME_RATE = 60;

    constexpr static float BOID_SIZE = 3;
    constexpr static int DEFAULT_WINDOW_WIDTH = 1800;
    constexpr static int DEFAULT_WINDOW_HEIGHT = 1200;
    constexpr static int DEFAULT_FLOCK_SIZE = 50;

    constexpr static float DEFAULT_MAX_SPEED = 6;
    constexpr static float DEFAULT_MAX_FORCE = 0.5;
    constexpr static float DEFAULT_ALIGNMENT_WEIGHT = 1;
    constexpr static float DEFAULT_COHESION_WEIGHT = 1;
    constexpr static float DEFAULT_SEPARATION_WEIGHT = 1.5;
    constexpr static float DEFAULT_ACCELERATION_SCALE = 0.4;
    constexpr static float DEFAULT_PERCEPTION = 100;
    constexpr static float DEFAULT_SEPARATION_DISTANCE = 20;

    Simulation(int window_width, int window_height, float max_speed, float max_force, float alignment_weight,
               float cohesion_weight, float separation_weight, float acceleration_scale, float perception,
               float separation_distance, bool fullscreen = false);

    ~Simulation();

    void run(int flock_size);

};


#endif //BOIDS_SIMULATION_H
