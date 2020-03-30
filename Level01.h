#pragma once

#include "Brain.h"
#include "Classic.h"
#include "Level.h"

class Level01 : public Level
{
public:
    Level01();
    SlideType getNextSlide() override;
    void reset() override;
};