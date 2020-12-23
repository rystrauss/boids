//
// Created by Ryan Strauss on 12/10/19.
//

#ifndef BOIDS_FLOCK_H
#define BOIDS_FLOCK_H

#include <vector>
#include "Boid.h"

class Flock {
private:
    std::vector<Boid> boids;

public:

    Flock();

    Flock(const Flock &other);

    ~Flock();

    Boid operator[](int i) const;

    void add(const Boid &boid);

    void clear();

    void update(float window_width, float window_height);

    int size() const;

};


#endif //BOIDS_FLOCK_H
