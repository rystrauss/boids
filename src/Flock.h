//
// Created by Ryan Strauss on 12/10/19.
//

#ifndef BOIDS_FLOCK_H
#define BOIDS_FLOCK_H

#include "Boid.h"
#include <vector>

class Flock {
private:
    std::vector<Boid *> boids;

public:

    Flock();

    Flock(const Flock &other);

    ~Flock();

    Boid *operator[](int i) const;

    void add(Boid *boid);

    void update();

    int size();

};


#endif //BOIDS_FLOCK_H
