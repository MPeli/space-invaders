#pragma once
#include "GameComponent.h"
#include <string_view>
#include <unordered_map>

class Text : public Tickable
{
public:
    enum class Alignment
    {
        left,
        center
    };

    Text(std::string_view text, std::unordered_map<char, Sprite>& alphabet, const Position position, const Alignment alignment, const const Size size) noexcept;

    void tick(const Time time) override;

private:
    Vector2D position;
    Size size;
    std::string_view text;
    std::unordered_map<char, Sprite>& alphabet;
    Alignment alignment;
};