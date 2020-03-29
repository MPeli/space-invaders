#pragma once

#include "Vector2D.h"
#include "Tickable.h"
#include "Sprite.h"

#include <string_view>
#include <unordered_map>

class Text : public Tickable
{
public:
    enum class Alignment
    {
        left,
        right,
        center
    };

    Text(std::string_view text, std::unordered_map<char, Sprite>& alphabet, const Position position, const Alignment alignment, const Size size) noexcept;

    void tick(const Time time) override;
    void setText(const std::string_view string);

private:
    Vector2D position;
    Size size;
    std::string_view text;
    std::unordered_map<char, Sprite>& alphabet;
    Alignment alignment;
};