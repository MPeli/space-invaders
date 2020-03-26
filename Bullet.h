#pragma once
#include "GameComponent.h"

class Bullet : public GameComponent<Bullet>
{
public:
    const Sprite& sprite;
    Bullet(const Sprite& sprite, const Size size) noexcept : sprite(sprite)
    {
        this->size = size;
    }

    void tick(const Time currentTime)
    {
        this->position.y -= 4;
        this->angle += 0.1f;

        DrawSprite(sprite, position.x, position.y, size.width, size.height, angle, 0xffffffff);
    }

    void setPosition(const Position position)
    {
        this->position = position;
    }
};