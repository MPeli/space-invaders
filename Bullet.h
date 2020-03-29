#pragma once
#include "GameComponent.h"

class Bullet : public GameComponent
{
public:
    Bullet(const Sprite& sprite, const Size size) noexcept;

    void setDirection(const Direction direction);
    void setPosition(const Position position);
    void tick(const Time currentTime) override;
};