#pragma once

#include "Sprite.h"
#include "Tickable.h"

enum class SlideType
{
    beginning,
    level01,
    end
};

class Slide : public Tickable
{
public:
    Slide();
    virtual SlideType getNextSlide() = 0;
    virtual void reset() = 0;

protected:
    Sprites& sprites;
};

