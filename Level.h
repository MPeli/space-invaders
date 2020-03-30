#pragma once

#include "GameComponents.h"
#include "Brain.h"
#include "Slide.h"
#include "Text.h"
#include "Timer.h"

class Level : public Slide
{
public:
    Level();

    void reset() override;
    void tick(const Time currentTime) override;
    void stop();

    // static Timer timer;

protected:
    Text text = { "score", sprites.alphabet, Position(80, 30), Text::Alignment::left, Size(40, 40) };
    std::unique_ptr<Brain> brain;
};