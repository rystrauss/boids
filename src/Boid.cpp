//
// Created by Ryan Strauss on 12/9/19.
//

#include "Boid.h"

Boid::Boid(float x, float y, bool is_predator) {
    position = Vector2D{x, y};
    velocity = Vector2D::random();
    acceleration = Vector2D{};

    max_speed = (is_predator) ? MAX_SPEED_PREDATOR : MAX_SPEED;
    max_force = MAX_FORCE;
    this->is_predator = is_predator;
}

Boid::Boid(const Boid &other) {
    position = other.position;
    velocity = other.velocity;
    acceleration = other.acceleration;
    max_speed = other.max_speed;
    max_force = other.max_force;
    is_predator = other.is_predator;
}

Boid::Boid(Boid &&other) noexcept {
    position = std::move(other.position);
    velocity = std::move(other.velocity);
    acceleration = std::move(other.acceleration);
    max_speed = other.max_speed;
    max_force = other.max_force;
    is_predator = other.is_predator;
}

Boid::~Boid() = default;

Boid &Boid::operator=(const Boid &other) = default;

Boid &Boid::operator=(Boid &&other) noexcept {
    position = std::move(other.position);
    velocity = std::move(other.velocity);
    acceleration = std::move(other.acceleration);
    max_speed = other.max_speed;
    max_force = other.max_force;
    is_predator = other.is_predator;
    return *this;
}

Vector2D Boid::alignment(std::vector<Boid> &boids) const {
    return Vector2D();
}

Vector2D Boid::cohesion(std::vector<Boid> &boids) const {
    return Vector2D();
}

Vector2D Boid::separation(std::vector<Boid> &boids) const {
    return Vector2D();
}

void Boid::apply_force(const Vector2D &force) {
    acceleration += force;
}
