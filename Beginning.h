#pragma once
#include "GameComponents.h"
#include "Slide.h"
#include "Text.h"

class Beginning : public Slide
{
private:
    Text text = { "welcome", sprites.alphabet, Position(300, 30) };
public:
    void tick(const Time currentTime) override
    {
        text.tick(currentTime);
    }
};

class End : public Slide
{
private:
    Text text = { "end", sprites.alphabet, Position(300, 30) };
public:
    void tick(const Time currentTime) override
    {
        text.tick(currentTime);
    }
};

class Level01 : public Slide
{
private:
    Text text = { "space invaders 2d", sprites.alphabet, Position(80, 30) };
public:
    Level01()
    {
        auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

        // 1 player
        player.position = Position(400, 550);
        player.size = Size(50, 50);

        // 10 bullets
        bullets.emplace_back_multiple(10, sprites.bullet, Size(10, 10));

        // 50 enemies
        enemies.emplace_back_multiple(50, sprites.enemy);
    }

    void tick(const Time currentTime) override
    {
        auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

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

        // Detect colitions
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
                        if (max01.x > min02.x && min01.x < max02.x && max01.y > min01.y && min01.y < max02.y)
                        {
                            bullet.visible = false;
                            enemy.visible = false;
                            break;
                        }
                    }
                }
            }
        }
    }
};

