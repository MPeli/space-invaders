#pragma once

#include "GameComponents.h"
#include "Slide.h"
#include "Text.h"

class Level01 : public Slide
{
public:
    Level01();

    SlideType getNextSlide() override;

    void reset() override;
    void tick(const Time currentTime) override;

private:
    Text text = { "space invaders 2d", sprites.alphabet, Position(80, 30), Text::Alignment::left, Size(40, 40) };
};