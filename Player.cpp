#include "Player.h"

#include "GameComponents.h"
#include <algorithm>

Player::Player(const Sprite& sprite, const Position position, const Size size) noexcept : GameComponent(sprite)
{
    this->position = position;
    this->size = size;
}

void Player::move() noexcept
{
    // Horizontal movement
    position.x += IsKeyDown('A') ? -7 : IsKeyDown('D') ? 7 : 0;

    // Vertical movement
    position.y += IsKeyDown('W') ? -7 : IsKeyDown('S') ? 7 : 0;

    float mx, my;
    GetMousePos(mx, my);

    // Compute angle between cursor and the player's position
    this->direction.x = this->position.x - mx;
    this->direction.y = this->position.y - my;
    this->direction.normalize();
    this->angle = this->direction.getAngle();

    // Compute bounding box
    this->recomputeBoundingBox();
}

void Player::shoot(const Time time)
{
    static auto& bullets = GameComponents::get().getBullets();
    static auto bulletToFire = bullets.begin();

    static int counter = 0;
    if (IsKeyDown(VK_LBUTTON))
    {
        if (counter == 0)
        {
            bulletToFire->setDirection(this->direction);
            bulletToFire->setPosition(this->position);
            bulletToFire->visible = true;
            bullets.next(bulletToFire);

            counter = 15;
        }
        else
        {
            --counter;
        }
    }
    else
    {
        counter = 0;
    }
}

void Player::tick(const Time time)
{
    this->move();
    this->shoot(time);
    // this->angle = std::numbers::pi + sin(time * 0.1) * 0.1;

    DrawSprite(sprite, position.x, position.y, size.width, size.height, angle, 0xffffffff);
}