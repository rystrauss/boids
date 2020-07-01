//
// Created by Ryan Strauss on 12/9/19.
//

#include <cmath>
#include <stdexcept>
#include <random>
#include "Vector2D.h"

float Vector2D::get_random_float() {
    static std::random_device rd;
    static std::mt19937 engine(rd());
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
    if (other.x == 0 || other.y == 0)
        throw std::invalid_argument("Divide by zero.");

    x /= other.x;
    y /= other.y;
    return *this;
}

Vector2D &Vector2D::operator/=(float scalar) {
    if (scalar == 0)
        throw std::invalid_argument("Divide by zero.");

    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2D::operator==(const Vector2D &other) const {
    return x == other.x && y == other.y;
}

bool Vector2D::operator!=(const Vector2D &other) const {
    return !(x == other.x && y == other.y);
}

Vector2D &Vector2D::operator-() {
    x = -x;
    y = -y;
    return *this;
}

float Vector2D::distance(const Vector2D &other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

float Vector2D::toroidal_distance2(const Vector2D &other, float width, float height) const {
    float dx = x - other.x;
    float dy = y - other.y;

    if (dx > width / 2)
        dx = width - dx;

    if (dy > height / 2)
        dy = height - dy;

    return dx * dx + dy * dy;
}

float Vector2D::toroidal_distance(const Vector2D &other, float width, float height) const {
    return sqrt(toroidal_distance2(other, width, height));
}

float Vector2D::norm() const {
    return sqrt(x * x + y * y);
}

Vector2D &Vector2D::normalize() {
    float magnitude = norm();
    if (magnitude != 0) {
        x /= magnitude;
        y /= magnitude;
    }
    return *this;
}

Vector2D &Vector2D::limit(float max) {
    float magnitude = norm();
    if (magnitude > max) {
        x *= max / magnitude;
        y *= max / magnitude;
    }
    return *this;
}

Vector2D Vector2D::random() {
    return Vector2D{get_random_float(), get_random_float()};
}
