#pragma once
#include "GameComponent.h"
class Text : Tickable
{
private:
    Vector2D position;
    Size size;
    std::string_view text;
    std::unordered_map<char, Sprite>& alphabet;

public:
    Text(std::string_view text, std::unordered_map<char, Sprite>& alphabet, const Position position, const Size size) noexcept;

    void tick(const Time time) override;
};

