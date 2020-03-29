#pragma once

class Tickable
{
public:
    using Time = long long int;
    virtual void tick(const Time currentTime) = 0;
};

