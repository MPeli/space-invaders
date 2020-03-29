#include "GameComponents.h"
#include "Logger.h"


GameComponents::GameComponents()
{
    Logger::get() << "Initializing game components...\n";
}

std::tuple<Player&, Container<Bullet>&, Container<Enemy>&> GameComponents::getAllComponents()
{
    return { player, bullets, enemies };
}

Container<Bullet>& GameComponents::getBullets()
{
    return this->bullets;
}

Sounds& GameComponents::getSound() noexcept
{
    return this->sounds;
}