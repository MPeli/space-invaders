#include "Level.h"
#include "Logger.h"

#include <algorithm>
#include "Classic.h"
#include "CollisionDetector.h"

Level::Level()
{
    Logger::get() << "Initializing the Level slide...\n";
}

void Level::reset()
{
    timer.start();

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
        enemy.position = enemy.basePosition;
        enemy.visible = true;
    }
}

void Level::tick(const Time currentTime)
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
    auto collisionDetected = CollisionDetector::getFirstCollision(bullets, enemies);

    if (collisionDetected.has_value())
    {
        auto& [bullet, enemy] = collisionDetected.value();
        bullet.get().visible = false;
        enemy.get().visible = false;

        score.addPoints(100 * enemy.get().size.width);

        GameComponents::get().getSound().explode();
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
                score.setScore(0);
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
        brain->compute(enemy, currentTime);
        enemy.tick(currentTime);
    }

    text.tick(currentTime);
    score.tick(currentTime);

    timer.tick(currentTime);
}

void Level::stop()
{
    timer.stop();
}