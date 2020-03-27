#pragma once
#include "Drawable.h"
#include "Sprite.h"

struct Coordinates
{
    int x;
    int y;
    Coordinates() = default;
    Coordinates(const int x, const int y) noexcept : x(x), y(y)
    {

    }

    Coordinates operator+(const Coordinates& coordinates)
    {
        return { this->x + coordinates.x, this->y + coordinates.y };
    }

    Coordinates& operator+=(const Coordinates& coordinates)
    {
        this->x += coordinates.x;
        this->y += coordinates.y;

        return *this;
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

using Position = Coordinates;
using Delta = Coordinates;
using Angle = float;
using Seed = int;

class GameComponent: public Drawable
{
public:
    Coordinates position;
    Coordinates basePosition;
    Size size;
    Angle angle{};

public:
    virtual void tick(const Time currentTime) = 0;
};