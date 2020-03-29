#pragma once

#include "Slide.h"
#include "Text.h"

class End : public Slide
{
public:
    End();
    SlideType getNextSlide() override;

    void reset() override;
    void tick(const Time currentTime) override;

private:
    Text text = { "the end", sprites.alphabet, Position(400, 200), Text::Alignment::center, Size(40, 40) };
};