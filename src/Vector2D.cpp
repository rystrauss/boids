//
// Created by Ryan Strauss on 12/9/19.
//

#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(float x, float y) : x{x}, y{y} {}

Vector2D::Vector2D(const Vector2D &other) : x{other.x}, y{other.y} {}

Vector2D::Vector2D(Vector2D &&other) noexcept : x{other.x}, y{other.y} {
    other.x = 0;
    other.y = 0;
}

Vector2D::~Vector2D() = default;

Vector2D &Vector2D::operator=(const Vector2D &other) = default;

Vector2D &Vector2D::operator=(Vector2D &&other) noexcept {
    x = other.x;
    y = other.y;
    other.x = 0;
    other.y = 0;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D &other) const {
    return Vector2D{x + other.x, y + other.y};
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
    return Vector2D{x - other.x, y - other.y};
}

Vector2D Vector2D::operator+(float scalar) const {
    return Vector2D{x + scalar, y + scalar};
}

Vector2D Vector2D::operator-(float scalar) const {
    return Vector2D{x - scalar, y - scalar};
}

Vector2D &Vector2D::operator+=(const Vector2D &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2D &Vector2D::operator+=(float scalar) {
    x += scalar;
    y += scalar;
    return *this;
}

Vector2D &Vector2D::operator-=(float scalar) {
    x -= scalar;
    y -= scalar;
    return *this;
}

Vector2D Vector2D::operator*(const Vector2D &other) const {
    return Vector2D{x * other.x, y * other.y};
}

Vector2D Vector2D::operator*(float scalar) const {
    return Vector2D{x * scalar, y * scalar};
}

Vector2D &Vector2D::operator*=(const Vector2D &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vector2D &Vector2D::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2D Vector2D::operator/(const Vector2D &other) const {
    return Vector2D{x / other.x, y / other.y};
}

Vector2D Vector2D::operator/(float scalar) const {
    return Vector2D{x / scalar, y / scalar};
}

Vector2D &Vector2D::operator/=(const Vector2D &other) {
    x /= other.x;
    y /= other.y;
    return *this;
}

Vector2D &Vector2D::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

float Vector2D::distance(const Vector2D &other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

float Vector2D::norm() const {
    return sqrt(x * x + y * y);
}

void Vector2D::normalize() {
    float magnitude = norm();
    if (magnitude != 0) {
        x /= magnitude;
        y /= magnitude;
    }
}
