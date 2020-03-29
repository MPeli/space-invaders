#pragma once
#include "Vector2D.h"
#include "Slide.h"
#include "Text.h"

#include <vector>

class Beginning : public Slide
{
public:
    Beginning();
    SlideType getNextSlide() override;

    void reset() override;
    void tick(const Time currentTime) override;

private:
    std::vector<Text> texts = {
        { "welcome", sprites.alphabet, Position(400, 100), Text::Alignment::center, Size(40, 40) },
        { "use a w s d", sprites.alphabet, Position(400, 200), Text::Alignment::center, Size(40, 40) },
        { "and", sprites.alphabet, Position(400, 300), Text::Alignment::center, Size(40, 40) },
        { "your mouse", sprites.alphabet, Position(400, 400), Text::Alignment::center, Size(40, 40) }
    };
};