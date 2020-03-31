#include "GameComponents.h"
#include "Logger.h"


GameComponents::GameComponents()
{
    Logger::get() << "Initializing game components...\n";

    // 1 player
    player.basePosition = Position(400, 550);
    player.position = player.basePosition;
    player.size = Size(100, 100);

    // 10 bullets
    bullets.emplace_back_multiple(10, Sprites::get().bullet, Size(20, 20));

    // 50 enemies
    enemies.emplace_back_multiple(50, Sprites::get().enemy);
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

Score& GameComponents::getScore() noexcept
{
    return this->score;
}

const Canvas& GameComponents::getCanvas() noexcept
{
    return this->canvas;
}

Timer& GameComponents::getTimer() noexcept
{
    return this->timer;
}