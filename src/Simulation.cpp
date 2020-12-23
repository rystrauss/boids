//
// Created by Ryan Strauss on 12/10/19.
//

#include <random>
#include "Simulation.h"


Simulation::Simulation(int window_width, int window_height, float boid_size, float max_speed, float max_force,
                       float alignment_weight, float cohesion_weight, float separation_weight,
                       float acceleration_scale, float perception, float separation_distance, float noise_scale,
                       bool fullscreen, bool light_scheme) {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    if (fullscreen) {
        window.create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Boids",
                      sf::Style::Fullscreen);
    } else {
        window.create(sf::VideoMode(window_width, window_height, desktop.bitsPerPixel), "Boids", sf::Style::Titlebar);
    }

    window.setFramerateLimit(FRAME_RATE);

    this->window_width = fullscreen ? desktop.width : window_width;
    this->window_height = fullscreen ? desktop.height : window_height;
    this->boid_size = boid_size;
    this->max_speed = max_speed;
    this->max_force = max_force;
    this->alignment_weight = alignment_weight;
    this->cohesion_weight = cohesion_weight;
    this->separation_weight = separation_weight;
    this->acceleration_scale = acceleration_scale;
    this->perception = perception;
    this->separation_distance = separation_distance;
    this->noise_scale = noise_scale;
    this->light_scheme = light_scheme;
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
                  cohesion_weight, alignment_weight, separation_weight, perception, separation_distance, noise_scale,
                  is_predator};
    sf::CircleShape shape(is_predator ? boid_size * 1.3f : boid_size, 3);

    shape.setPosition(x, y);
    shape.setFillColor(is_predator ? sf::Color::Red : (light_scheme ? sf::Color::Black : sf::Color::Green));
    shape.setOutlineColor(light_scheme ? sf::Color::White : sf::Color::Black);
    shape.setOutlineThickness(1);

    flock.add(b);
    shapes.emplace_back(shape);
}

void Simulation::render() {
    window.clear(light_scheme ? sf::Color::White : sf::Color::Black);
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

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
        add_boid(mouse_position.x, mouse_position.y, true);
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
        add_boid(mouse_position.x, mouse_position.y, false);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        flock.clear();
        shapes.clear();
        run(DEFAULT_FLOCK_SIZE);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        window.close();
        std::exit(0);
    }
    return false;
}

float Simulation::get_random_float() {
    static std::random_device rd;
    static std::mt19937 engine(rd());
    static std::uniform_real_distribution<float> dist(0, 1);
    return dist(engine);
}