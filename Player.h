#pragma once
#include "GameComponent.h"
#include <numbers>

class Player :  public GameComponent<Player>
{
public:
    const Sprite& sprite;
    Player(const Sprite& sprite, const Position position, const Size size) noexcept : sprite(sprite)
    {
        this->position = position;
        this->size = size;
    }

    void tick(const Time time)
    {
        this->detectMovement();

        DrawSprite(sprite, position.x, position.y, size.width, size.height, std::numbers::pi + sin(time * 0.1) * 0.1, 0xffffffff);
    }

    void detectMovement() noexcept
    {
        position.x += IsKeyDown(VK_LEFT) ? -7 : IsKeyDown(VK_RIGHT) ? 7 : 0;
        position.y += IsKeyDown(VK_UP) ? -7 : IsKeyDown(VK_DOWN) ? 7 : 0;
    }
};