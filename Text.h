#pragma once
#include "GameComponent.h"
class Text : Tickable
{
private:
    Vector2D position;
    std::string_view text;
    std::unordered_map<char, Sprite>& alphabet;

public:
    Text(std::string_view text, std::unordered_map<char, Sprite>& alphabet, Position position) noexcept;

    void tick(const Time time) override;
};

