#include "GameComponents.h"

std::tuple<Player&, Container<Bullet>&, Container<Enemy>&> GameComponents::getAllComponents()
{
    return { player, bullets, enemies };
}

Container<Bullet>& GameComponents::getBullets()
{
    return this->bullets;
}

Sprites& GameComponents::getSprites() noexcept
{
    return this->sprites;
}

Sounds& GameComponents::getSound() noexcept
{
    return this->sounds;
}