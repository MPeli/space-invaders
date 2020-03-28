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

// Sprites is a singleton class
// It loads letters (a-z), numbers (0-9), invaders (little and big) and the bullet
class Sprites
{
private:
    Sprites();

public:
    const Sprite enemy = "gfx/invaders/little.png";
    const Sprite player = "gfx/invaders/big.png";
    const Sprite bullet = "gfx/bullet.png";

    std::unordered_map<char, Sprite> alphabet;

    static Sprites& get()
    {
        static Sprites sprites;
        return sprites;
    }

    void loadSprites();

    // do not allow any copies
    Sprites(const Sprites&) = delete;
    void operator=(const Sprites&) = delete;
    void operator=(const Sprites&&) = delete;
};