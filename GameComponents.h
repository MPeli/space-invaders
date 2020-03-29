#pragma once

#include "Bullet.h"
#include "Container.h"
#include "Enemy.h"
#include "Player.h"
#include "Slide.h"
#include "Sounds.h"
#include "Sprite.h"
#include "Singleton.h"
#include "Projector.h"

#include <tuple>

class GameComponents : public Singleton<GameComponents>
{
    friend Singleton<GameComponents>;

public:
    std::tuple<Player&, Container<Bullet>&, Container<Enemy>&> getAllComponents();

    Container<Bullet>& getBullets();

    Sounds& getSound() noexcept;

private:
    Sounds sounds;
    Player player = { Sprites::get().player, Position(0, 0), Size(0, 0) };
    Container<Bullet> bullets;
    Container<Enemy> enemies;

    GameComponents();
};