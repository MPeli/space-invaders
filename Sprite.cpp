#include "Sprite.h"


Sprites::Sprites()
{
    this->loadSprites();
}

void Sprites::loadSprites()
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