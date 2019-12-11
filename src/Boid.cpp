//
// Created by Ryan Strauss on 12/9/19.
//

#include "Boid.h"
#include <cmath>

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

Boid::~Boid() = default;

Boid &Boid::operator=(const Boid &other) = default;

Vector2D Boid::alignment(const std::vector<Boid *> &boids) const {
    return Vector2D();
}

Vector2D Boid::cohesion(const std::vector<Boid *> &boids) const {
    return Vector2D();
}

Vector2D Boid::separation(const std::vector<Boid *> &boids) const {
    return Vector2D();
}

void Boid::apply_force(const Vector2D &force) {
    acceleration += force;
}

void Boid::update(const std::vector<Boid *> &boids, float window_width, float window_height) {
    // Apply each rule, get resulting forces, and weight them
    Vector2D alignment_update = alignment(boids) * ALIGNMENT_WEIGHT;
    Vector2D cohesion_update = cohesion(boids) * COHESION_WEIGHT;
    Vector2D separation_update = separation(boids) * SEPARATION_WEIGHT;
    // Apply the weighted forces to this boid
    apply_force(alignment_update + cohesion_update + separation_update);
    // Scale the acceleration then use it to update the velocity
    acceleration *= ACCELERATION_SCALE;
    velocity += acceleration;
    // Limit the velocity so the boids don't get too fast
    velocity.limit(max_speed);
    // Then update the position based on the velocity
    position += velocity;
    // Set the acceleration to zero before the next update
    acceleration = 0;
    // If boid leaves the screen, update position so the boid wraps around
    if (position.x < 0) position.x += window_width;
    if (position.y < 0) position.y += window_height;
    if (position.x >= window_width) position.x -= window_width;
    if (position.y >= window_height) position.y -= window_height;

}

float Boid::angle() const {
    return (float)(atan2(velocity.x, -velocity.y) * 180 / M_PI);
}
