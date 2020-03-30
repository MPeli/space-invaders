#pragma once
#include <utility>

class Vector2D
{
public:
    float x;
    float y;
    Vector2D() = default;
    Vector2D(const float x, const float y) noexcept;

    Vector2D operator+(const Vector2D& vector);

    Vector2D operator-(const Vector2D& vector);

    Vector2D& operator+=(const Vector2D& vector);

    Vector2D& operator-=(const Vector2D& vector);

    Vector2D operator*(const float scalar);

    void normalize();

    void rotate(const Vector2D& center, const float angle);

    float getAngle() const;
};

class Size
{
public:
    int width;
    int height;

    Size() = default;
    Size(const int width, const int height) noexcept;
};

using Position = Vector2D;
using Delta = Vector2D;
using Direction = Vector2D;
using Angle = float;
using Seed = int;
using BoundingBox = std::pair<Vector2D, Vector2D>;