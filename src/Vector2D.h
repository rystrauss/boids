//
// Created by Ryan Strauss on 12/9/19.
//

#ifndef BOIDS_VECTOR2D_H
#define BOIDS_VECTOR2D_H

#include <random>

class Vector2D {
private:

    float static get_random_float();

public:
    float x, y;

    // Constructors
    explicit Vector2D(float x = 0, float y = 0);

    Vector2D(const Vector2D &other);

    Vector2D(Vector2D &&other) noexcept;

    ~Vector2D();

    // Operators
    Vector2D &operator=(const Vector2D &other);

    Vector2D &operator=(Vector2D &&other) noexcept;

    Vector2D operator+(const Vector2D &other) const;

    Vector2D operator-(const Vector2D &other) const;

    Vector2D operator+(float scalar) const;

    Vector2D operator-(float scalar) const;

    Vector2D &operator+=(const Vector2D &other);

    Vector2D &operator-=(const Vector2D &other);

    Vector2D &operator+=(float scalar);

    Vector2D &operator-=(float scalar);

    Vector2D operator*(const Vector2D &other) const;

    Vector2D operator*(float scalar) const;

    Vector2D &operator*=(const Vector2D &other);

    Vector2D &operator*=(float scalar);

    Vector2D operator/(const Vector2D &other) const;

    Vector2D operator/(float scalar) const;

    Vector2D &operator/=(const Vector2D &other);

    Vector2D &operator/=(float scalar);

    // Methods
    float distance(const Vector2D &other) const;

    float norm() const;

    void normalize();

    static Vector2D random();

};


#endif //BOIDS_VECTOR2D_H
