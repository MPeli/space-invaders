#include "Bullet.h"


Bullet::Bullet(const Sprite& sprite, const Size size) noexcept : GameComponent(sprite)
{
    this->size = size;
}

void Bullet::setDirection(const Direction direction)
{
    this->direction = direction;
    this->angle = direction.getAngle();
}

void Bullet::setPosition(const Position position)
{
    this->position = position;
}

void Bullet::tick(const Time currentTime)
{
    if (this->visible)
    {
        constexpr float speed = 5.f;
        this->position -= this->direction * speed;

        // Compute bounding box
        this->recomputeBoundingBox();

        this->draw();
    }
}