#include "Level01.h"
#include "Logger.h"

Level01::Level01()
{
    Logger::get() << "Initializing the level01 slide...\n";

    const auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

    // 1 player
    player.basePosition = Position(400, 550);
    player.position = player.basePosition;
    player.size = Size(100, 100);

    // 10 bullets
    bullets.emplace_back_multiple(10, sprites.bullet, Size(20, 20));

    // 50 enemies
    enemies.emplace_back_multiple(50, sprites.enemy);
}

SlideType Level01::getNextSlide()
{
    const auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

    auto allDead = std::all_of(enemies.cbegin(), enemies.cend(), [](const Enemy& enemy)
        {
            return !enemy.visible;
        });

    if (allDead)
    {
        return SlideType::end;
    }

    return SlideType::level01;
}

void Level01::reset()
{
    const auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

    player.position = player.basePosition;
    
    for (auto& bullet : bullets)
    {
        bullet.visible = false;
        bullet.position = player.basePosition;
    }

    // Show all enemies
    for (auto& enemy : enemies)
    {
        enemy.visible = true;
    }

}

void Level01::tick(const Time currentTime)
{
    const auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

    // Detect colitions, one bullet can kill only one enemy
    for (auto& bullet : bullets)
    {
        if (bullet.visible)
        {
            const auto& [min01, max01] = bullet.getBoundingBox();

            for (auto& enemy : enemies)
            {
                if (enemy.visible)
                {
                    const auto& [min02, max02] = enemy.getBoundingBox();

                    // Colision detected
                    if (max01.x > min02.x && min01.x < max02.x && max01.y > min02.y && min01.y < max02.y)
                    {
                        bullet.visible = false;
                        enemy.visible = false;
                        GameComponents::get().getSound().explode();
                        break;
                    }
                }
            }
        }
    }

    player.tick(currentTime);

    for (auto& bullet : bullets)
    {
        bullet.tick(currentTime);
    }

    for (auto& enemy : enemies)
    {
        enemy.tick(currentTime);
    }

    text.tick(currentTime);
}