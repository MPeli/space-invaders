#include "Level01.h"
#include "Logger.h"

#include <algorithm>

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
    auto& score = GameComponents::get().getScore();

    const auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

    static auto collide = [](const std::pair<Vector2D, Vector2D>& left, const std::pair<Vector2D, Vector2D>& right)
    {
        const auto& [min01, max01] = left;
        const auto& [min02, max02] = right;

        return max01.x > min02.x && min01.x < max02.x&& max01.y > min02.y && min01.y < max02.y;
    };

    // Detect colitions, one bullet can kill only one enemy
    for (auto& bullet : bullets)
    {
        if (bullet.visible)
        {
            const auto& bulletMinMax = bullet.getBoundingBox();

            for (auto& enemy : enemies)
            {
                if (enemy.visible)
                {
                    const auto& enemyMinMax = enemy.getBoundingBox();

                    // Colision detected
                    if (collide(bulletMinMax, enemyMinMax))
                    {
                        bullet.visible = false;
                        enemy.visible = false;
                        
                        score.addPoints(100 * enemy.size.width);

                        GameComponents::get().getSound().explode();
                        break;
                    }
                }
            }
        }
    }

    // Collision detection, was the player attacked?
    for (auto& enemy : enemies)
    {
        if (enemy.visible)
        {
            const auto& enemyMinMax = enemy.getBoundingBox();

            // Colision detected
            if (collide(enemyMinMax, player.getBoundingBox()))
            {
                GameComponents::get().getSound().explode();
                break;
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
    score.tick(currentTime);
}