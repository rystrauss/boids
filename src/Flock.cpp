//
// Created by Ryan Strauss on 12/10/19.
//

#include "Flock.h"

Flock::Flock() = default;

Flock::Flock(const Flock &other) {
    for (const Boid &b : other.boids) boids.emplace_back(b);
}

Flock::~Flock() = default;

Boid Flock::operator[](int i) const {
    return boids[i];
}

void Flock::add(const Boid &boid) {
    boids.emplace_back(boid);
}

void Flock::update(float window_width, float window_height) {
    // Copy boids so that updates happen simultaneously
    std::vector<Boid> old_boids(boids);
    for (Boid &b : boids) b.update(old_boids);
}

int Flock::size() const {
    return boids.size();
}
