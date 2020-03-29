#pragma once

#include "Tickable.h"
#include "Sprite.h"
#include <algorithm>
#include <tuple>
#include <cmath>

struct Vector2D
{
    float x;
    float y;
    Vector2D() = default;
    Vector2D(const float x, const float y) noexcept : x(x), y(y)
    {

    }

    Vector2D operator+(const Vector2D& vector)
    {
        return { this->x + vector.x, this->y + vector.y };
    }

    Vector2D operator-(const Vector2D& vector)
    {
        return { this->x - vector.x, this->y - vector.y };
    }

    Vector2D& operator+=(const Vector2D& vector)
    {
        this->x += vector.x;
        this->y += vector.y;

        return *this;
    }

    Vector2D& operator-=(const Vector2D& vector)
    {
        this->x -= vector.x;
        this->y -= vector.y;

        return *this;
    }

    Vector2D operator*(const float scalar)
    {
        return { this->x * scalar, this->y * scalar };
    }

    void normalize()
    {
        double magnitude = std::sqrt((this->x * this->x) + (this->y * this->y));
        this->x /= magnitude;
        this->y /= magnitude;
    }

    void rotate(const Vector2D& center, const float angle)
    {
        Vector2D old = *this - center;
        this->x = old.x * std::cos(angle) - old.y * std::sin(angle) + center.x;
        this->y = old.x * std::sin(angle) + old.y * std::cos(angle) + center.y;
    }

    float getAngle() const
    {
        return std::atan2(this->x, this->y);
    }
};

struct Size
{
public:
    int width;
    int height;

    Size() = default;
    Size(const int width, const int height) noexcept : width(width), height(height)
    {

    }
};

using Position = Vector2D;
using Delta = Vector2D;
using Direction = Vector2D;
using Angle = float;
using Seed = int;

class GameComponent : public Tickable
{
public:
    const Sprite& sprite;

public:
    Vector2D direction;
    Vector2D position;
    Vector2D basePosition;
    Size size;
    Angle angle{};
    std::pair<Vector2D, Vector2D> minmax;
    bool visible = true;

public:
    GameComponent(const Sprite& sprite);
    virtual void draw();
    virtual void tick(const Time currentTime) = 0;

    void recomputeBoundingBox();

    std::pair<Vector2D, Vector2D>& getBoundingBox();
};