#pragma once
#include <unordered_map>
#include "lib/leetlib.h"

class Sprite
{
private:
    void* texture = nullptr;

public:
    Sprite(const char* const path)
    {
        this->texture = LoadSprite(path);
    }

    operator void* () const
    {
        return texture;
    }
};

// It loads letters (a-z), numbers (0-9), invaders (little and big) and the bullet
class Sprites
{
public:
    const Sprite enemy = "gfx/invaders/little.png";
    const Sprite player = "gfx/invaders/big.png";
    const Sprite bullet = "gfx/bullet.png";

    std::unordered_map<char, Sprite> alphabet;

    Sprites();
    void loadSprites();
};