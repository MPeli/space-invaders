#pragma once

#include "Tickable.h"
#include <algorithm>
#include <tuple>

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

    void recomputeBoundingBox()
    {
        if (this->angle)
        {
            Position p0 = { this->position.x - this->size.width / 2, this->position.y - this->size.height / 2 };
            Position p1 = { this->position.x - this->size.width / 2, this->position.y + this->size.height / 2 };
            Position p2 = { this->position.x + this->size.width / 2, this->position.y - this->size.height / 2 };
            Position p3 = { this->position.x + this->size.width / 2, this->position.y + this->size.height / 2 };

            p0.rotate(this->position, this->angle);
            p1.rotate(this->position, this->angle);
            p2.rotate(this->position, this->angle);
            p3.rotate(this->position, this->angle);

            auto minx = std::min<float>({ p0.x, p1.x, p2.x, p3.x });
            auto miny = std::min<float>({ p0.y, p1.y, p2.y, p3.y });

            auto maxx = std::max<float>({ p0.x, p1.x, p2.x, p3.x });
            auto maxy = std::max<float>({ p0.y, p1.y, p2.y, p3.y });

            this->minmax = std::make_pair(Vector2D{minx, miny}, Vector2D{maxx, maxy});
        }
        else
        {
            Position p0 = { this->position.x - this->size.width / 2, this->position.y - this->size.height / 2 };
            Position p1 = { this->position.x + this->size.width / 2, this->position.y + this->size.height / 2 };

            this->minmax = { p0, p1 };
        }
    }

    std::pair<Vector2D, Vector2D>& getBoundingBox()
    {
        return this->minmax;
    }
};