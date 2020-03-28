#pragma once
#include "Tickable.h"

class Slide: public Tickable
{
protected:
    Sprites& sprites = Sprites::get();
};

