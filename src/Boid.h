//
// Created by Ryan Strauss on 12/9/19.
//

#ifndef BOIDS_BOID_H
#define BOIDS_BOID_H

#include "Vector2D.h"
#include <vector>

class Boid {
private:
    constexpr static float MAX_SPEED = 3.5;
    constexpr static float MAX_SPEED_PREDATOR = 7.5;
    constexpr static float MAX_FORCE = 0.5;

    constexpr static float ALIGNMENT_WEIGHT = 1.0;
    constexpr static float COHESION_WEIGHT = 1.0;
    constexpr static float SEPARATION_WEIGHT = 1.5;

    constexpr static float ACCELERATION_SCALE = 0.4;

public:
    Vector2D position, velocity, acceleration;
    float max_speed, max_force;
    bool is_predator;

    // Constructors
    Boid(float x, float y, bool is_predator = false);

    Boid(const Boid &other);

    ~Boid();

    // Operators
    Boid &operator=(const Boid &other);

    // Methods
    Vector2D alignment(const std::vector<Boid *> &boids) const;

    Vector2D cohesion(const std::vector<Boid *> &boids) const;

    Vector2D separation(const std::vector<Boid *> &boids) const;

    void apply_force(const Vector2D &force);

    void update(const std::vector<Boid *> &boids, float window_width, float window_height);

    float angle() const;

};


#endif //BOIDS_BOID_H
