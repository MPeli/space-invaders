#include "Text.h"
#include <string>
#include "lib/leetlib.h"
#include <algorithm>

Text::Text(std::string text, std::unordered_map<char, Sprite>& alphabet, const Position position, const Alignment alignment, const Size size) noexcept : text(text), alphabet(alphabet), alignment(alignment), size(size)
{
    this->position = position;
}

void Text::tick(const Time time)
{
    auto origin = this->position.x;

    if (this->alignment == Alignment::center)
    {
        auto width = text.size() * this->size.width;
        origin -= width / 2 - this->size.width / 2;
    }
    else if (this->alignment == Alignment::right)
    {
        auto width = text.size() * this->size.width;
        origin -= width - this->size.width / 2;
    }

    for (std::size_t i = 0; i < text.size(); ++i)
    {
        if (const auto search = this->alphabet.find(text[i]); search != this->alphabet.end())
        {
            DrawSprite(search->second, origin + i * this->size.width, this->position.y, this->size.width, this->size.height, sin(time * 0.1) * i * 0.01);
        }
    }
}

void Text::setText(const std::string text)
{
    this->text = text;
}

void Text::setPosition(const Position& position)
{
    this->position = position;
}

void Text::setSize(const Size& size)
{
    this->size = size;
}