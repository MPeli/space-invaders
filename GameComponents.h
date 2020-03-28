#pragma once

#include "Bullet.h"
#include "Container.h"
#include "Enemy.h"
#include "Player.h"
#include "Sprite.h"

#include <tuple>

class GameComponents
{
private:
    Sprites& sprites = Sprites::get();
    Player player = { sprites.player, Position(0, 0), Size(0, 0) };
    Container<Bullet> bullets;
    Container<Enemy> enemies;

    GameComponents() = default;

public:
    static GameComponents& get()
    {
        static GameComponents gameComponents;
        return gameComponents;
    }

    std::tuple<Player&, Container<Bullet>&, Container<Enemy>&> getAllComponents()
    {
        return { player, bullets, enemies };
    }

    Container<Bullet>& getBullets()
    {
        return this->bullets;
    }
};