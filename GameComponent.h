#pragma once

#include "Tickable.h"
#include "Score.h"
#include "Sprite.h"
#include "Vector2D.h"
#include <tuple>

class GameComponent : public Tickable
{
public:
    const Sprite& sprite;

public:
    Vector2D direction;
    Vector2D position;
    Vector2D basePosition;
    // Score score;
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