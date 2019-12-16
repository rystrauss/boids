//
// Created by Ryan Strauss on 12/9/19.
//

#include <cmath>
#include "Vector2D.h"

float Vector2D::get_random_float() {
    static std::random_device rd;
    static std::ranlux24_base engine(rd());
    static std::uniform_real_distribution<float> dist(0, 1);
    return dist(engine);
}

Vector2D::Vector2D(float x, float y) : x{x}, y{y} {}

Vector2D::Vector2D(const Vector2D &other) = default;

Vector2D::~Vector2D() = default;

Vector2D &Vector2D::operator=(const Vector2D &other) = default;

Vector2D &Vector2D::operator=(float scalar) {
    x = scalar;
    y = scalar;
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

void Vector2D::limit(float max) {
    float magnitude = norm();
    if (magnitude > max) {
        x *= max / magnitude;
        y *= max / magnitude;
    }
}

Vector2D Vector2D::random() {
    return Vector2D{get_random_float(), get_random_float()};
}
