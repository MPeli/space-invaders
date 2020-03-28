#include "Text.h"

Text::Text(std::string_view text, std::unordered_map<char, Sprite>& alphabet, const Position position, const Size size) noexcept : text(text), alphabet(alphabet), size(size)
{
    this->position = position;
}

void Text::tick(const Time time)
{
    for (std::size_t i = 0; i < text.size(); ++i)
    {
        if (const auto search = this->alphabet.find(text[i]); search != this->alphabet.end())
        {
            DrawSprite(search->second, this->position.x + i * 40, this->position.y, this->size.width, this->size.height, sin(time * 0.1) * i * 0.01);
        }
    }
}