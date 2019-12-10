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

public:
    Vector2D position, velocity, acceleration;
    float max_speed, max_force;
    bool is_predator;

    // Constructors
    Boid(float x, float y, bool is_predator = false);

    Boid(const Boid &other);

    Boid(Boid &&other) noexcept;

    ~Boid();

    // Operators
    Boid &operator=(const Boid &other);

    Boid &operator=(Boid &&other) noexcept;

    // Methods
    Vector2D alignment(std::vector<Boid> &boids) const;

    Vector2D cohesion(std::vector<Boid> &boids) const;

    Vector2D separation(std::vector<Boid> &boids) const;

    void apply_force(const Vector2D &force);

};


#endif //BOIDS_BOID_H
