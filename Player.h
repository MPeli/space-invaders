#pragma once
#include "GameComponent.h"
#include <numbers>

class Player :  public GameComponent
{
public:
    Player(const Sprite& sprite, const Position position, const Size size) noexcept;

    void move() noexcept;
    void shoot(const Time time);
    void tick(const Time time) override;
};