#pragma once
class Drawable
{
public:
    using Time = int;
    virtual void tick(const Time currentTime) = 0;
};

