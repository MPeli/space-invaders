#pragma once
#include "Text.h"
#include "Slide.h"
#include "Timer.h"

class BetweenLevels : public Slide
{
public:
    BetweenLevels();
    SlideType getNextSlide() override;

    void reset() override;
    void tick(const Time currentTime) override;

private:
    Text text = { "well done", sprites.alphabet, Position(400, 200), Text::Alignment::center, Size(40, 40) };
};

