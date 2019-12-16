//
// Created by Ryan Strauss on 12/9/19.
//

#ifndef BOIDS_BOID_H
#define BOIDS_BOID_H

#include <vector>
#include "Vector2D.h"

class Boid {

public:
    Vector2D position, velocity, acceleration;
    float max_speed, max_force;
    float acceleration_scale;
    float cohesion_weight, alignment_weight, separation_weight;
    float perception;
    bool is_predator;

    // Constructors
    Boid(float x, float y, float max_speed, float max_force, float acceleration_scale, float cohesion_weight,
         float alignment_weight, float separation_weight, float perception, bool is_predator = false);

    Boid(const Boid &other);

    ~Boid();

    // Operators
    Boid &operator=(const Boid &other);

    // Methods
    Vector2D alignment(const std::vector<Boid> &boids) const;

    Vector2D cohesion(const std::vector<Boid> &boids) const;

    Vector2D separation(const std::vector<Boid> &boids) const;

    void apply_force(const Vector2D &force);

    void update(const std::vector<Boid> &boids, float window_width, float window_height);

    float angle() const;

};


#endif //BOIDS_BOID_H
