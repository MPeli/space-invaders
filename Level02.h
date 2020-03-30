#pragma once
#include "Brain.h"
#include "Classic.h"
#include "Level.h"

class Level02 : public Level
{
public:
    Level02();
    SlideType getNextSlide() override;
};