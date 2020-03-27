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
    Sprites()
    {
        this->loadSprites();
    }

public:
    const Sprite enemy = "gfx/invaders/little.png";
    const Sprite player = "gfx/invaders/big.png";
    const Sprite bullet = "gfx/bullet.png";

    std::unordered_map<char, Sprite> alphabet;

    static Sprites& getSprites()
    {
        static Sprites sprites;
        return sprites;
    }

    void loadSprites()
    {
        std::string root = "gfx";

        // load letters
        for (char letter = 'a'; letter <= 'z'; ++letter)
        {
            this->alphabet.emplace(letter, (root + "/alphabet/letters/" + letter + ".png").c_str());
        }

        // load numbers
        for (char number = '0'; number <= '9'; ++number)
        {
            this->alphabet.emplace(number, (root + "/alphabet/numbers/" + number + ".png").c_str());
        }
    }

    // do not allow any copies
    Sprites(const Sprites&) = delete;
    void operator=(const Sprites&) = delete;
};