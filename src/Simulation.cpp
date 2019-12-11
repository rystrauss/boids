//
// Created by Ryan Strauss on 12/10/19.
//

#include "Simulation.h"
#include <iostream>

Simulation::Simulation() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window_width = DEFAULT_WINDOW_WIDTH;
    window_height = DEFAULT_WINDOW_HEIGHT;
    window.create(sf::VideoMode(window_width, window_height, desktop.bitsPerPixel), "Boids", sf::Style::None);

    boid_size = DEFAULT_BOID_SIZE;
}

Simulation::~Simulation() = default;

void Simulation::run() {
    for (int i = 0; i < DEFAULT_NUM_BOIDS; ++i) {
        add_boid(get_random_float() * window_width, get_random_float() * window_height);
    }

    while (window.isOpen()) {
        if (handle_input()) break;
        render();
    }
}

void Simulation::add_boid(float x, float y, bool is_predator) {
    Boid *b = new Boid{x, y, is_predator};
    sf::CircleShape shape(boid_size, 3);

    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);

    flock.add(b);
    shapes.emplace_back(shape);
}

void Simulation::render() {
    window.clear();
    flock.update(window_width, window_height);

    for (int i = 0; i < shapes.size(); ++i) {
        Boid *b = flock[i];
        shapes[i].setPosition(b->position.x, b->position.y);
        shapes[i].setRotation(b->angle());
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
    static std::ranlux24_base engine(rd());
    static std::uniform_real_distribution<float> dist(0, 1);
    return dist(engine);
}