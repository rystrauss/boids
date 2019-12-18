//
// Created by Ryan Strauss on 12/10/19.
//

#include <random>
#include "Simulation.h"


Simulation::Simulation(int window_width, int window_height, float max_speed, float max_force,
                       float alignment_weight, float cohesion_weight, float separation_weight,
                       float acceleration_scale, float perception, float separation_distance) {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(window_width, window_height, desktop.bitsPerPixel), "Boids", sf::Style::Titlebar);
    window.setFramerateLimit(FRAME_RATE);

    this->window_width = window_width;
    this->window_height = window_height;
    this->max_speed = max_speed;
    this->max_force = max_force;
    this->alignment_weight = alignment_weight;
    this->cohesion_weight = cohesion_weight;
    this->separation_weight = separation_weight;
    this->acceleration_scale = acceleration_scale;
    this->perception = perception;
    this->separation_distance = separation_distance;
}

Simulation::~Simulation() = default;

void Simulation::run(int flock_size) {
    for (int i = 0; i < flock_size; ++i) {
        add_boid(get_random_float() * window_width, get_random_float() * window_height);
    }

    while (window.isOpen()) {
        if (handle_input()) break;
        render();
    }
}

void Simulation::add_boid(float x, float y, bool is_predator) {
    Boid b = Boid{x, y, (float) window_width, (float) window_height, max_speed, max_force, acceleration_scale,
                  cohesion_weight, alignment_weight, separation_weight, perception, separation_distance, is_predator};
    sf::CircleShape shape(DEFAULT_BOID_SIZE, 3);

    shape.setPosition(x, y);
    shape.setFillColor(is_predator ? sf::Color::Red : sf::Color::Green);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);

    flock.add(b);
    shapes.emplace_back(shape);
}

void Simulation::render() {
    window.clear();
    flock.update(window_width, window_height);

    for (int i = 0; i < shapes.size(); ++i) {
        Boid b = flock[i];
        shapes[i].setPosition(b.position.x, b.position.y);
        shapes[i].setRotation(b.angle());
        window.draw(shapes[i]);
    }

    window.display();
}

bool Simulation::handle_input() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return true;
        }
    }
    return false;
}

float Simulation::get_random_float() {
    static std::random_device rd;
    static std::mt19937 engine(rd());
    static std::uniform_real_distribution<float> dist(0, 1);
    return dist(engine);
}