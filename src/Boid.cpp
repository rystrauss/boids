//
// Created by Ryan Strauss on 12/9/19.
//

#include <cmath>
#include "Boid.h"

Boid::Boid(float x, float y, float max_width, float max_height, float max_speed, float max_force,
           float acceleration_scale, float cohesion_weight, float alignment_weight, float separation_weight,
           float perception, bool is_predator) {
    position = Vector2D{x, y};
    velocity = (Vector2D::random() - 0.5) * max_speed / 2;
    acceleration = Vector2D{};

    this->max_width = max_width;
    this->max_height = max_height;
    this->max_speed = max_speed;
    if (is_predator) this->max_speed *= 1.5;
    this->max_force = max_force;
    this->acceleration_scale = acceleration_scale;
    this->cohesion_weight = cohesion_weight;
    this->alignment_weight = alignment_weight;
    this->separation_weight = separation_weight;
    this->perception = perception;
    this->is_predator = is_predator;
}

Boid::Boid(const Boid &other) {
    position = other.position;
    velocity = other.velocity;
    acceleration = other.acceleration;
    max_width = other.max_width;
    max_height = other.max_height;
    max_speed = other.max_speed;
    max_force = other.max_force;
    acceleration_scale = other.acceleration_scale;
    cohesion_weight = other.cohesion_weight;
    alignment_weight = other.alignment_weight;
    separation_weight = other.separation_weight;
    perception = other.perception;
    is_predator = other.is_predator;
}

Boid::~Boid() = default;

Boid &Boid::operator=(const Boid &other) = default;

Vector2D Boid::alignment(const std::vector<Boid> &boids) const {
    Vector2D cm;
    int n = 0;

    for (const Boid &b : boids) {
        if (position != b.position && position.toroidal_distance(b.position, max_width, max_height) < perception) {
            cm += b.position;
            ++n;
        }
    }

    if (n == 0)
        return Vector2D{};

    cm /= n;
    cm.normalize();
    cm *= max_speed;
    Vector2D steer = cm - velocity;
    return steer.normalize();
}

Vector2D Boid::cohesion(const std::vector<Boid> &boids) const {
    return Vector2D();
}

Vector2D Boid::separation(const std::vector<Boid> &boids) const {
    return Vector2D();
}

void Boid::update(const std::vector<Boid> &boids) {
    // Apply each rule, get resulting forces, and weight them
    Vector2D alignment_update = alignment(boids) * alignment_weight;
    Vector2D cohesion_update = cohesion(boids) * cohesion_weight;
    Vector2D separation_update = separation(boids) * separation_weight;
    // Apply the weighted forces to this boid
    acceleration += alignment_update + cohesion_update + separation_update;
    // Scale the acceleration then use it to update the velocity
    acceleration *= acceleration_scale;
    velocity += acceleration;
    // Limit the velocity so the boids don't get too fast
    velocity.limit(max_speed);
    // Then update the position based on the velocity
    position += velocity;
    // Set the acceleration to zero before the next update
    acceleration = 0;
    // If boid leaves the screen, update position so the boid wraps around
    if (position.x < 0) position.x += max_width;
    if (position.y < 0) position.y += max_height;
    if (position.x >= max_width) position.x -= max_width;
    if (position.y >= max_height) position.y -= max_height;
}

float Boid::angle() const {
    return (float) (atan2(velocity.x, -velocity.y) * 180 / M_PI);
}
