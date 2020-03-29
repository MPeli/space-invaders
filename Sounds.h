#pragma once
#include "lib/leetlib.h"
#include "Tickable.h"

class Sounds : public Tickable
{
public:
    Sounds();

    void shoot();
    void explode();

    void setVolume(const float volume);
    void decreaseVolume();
    void increaseVolume();

    void tick(const Time currentTime) override;

private:
    void* explosionSound = nullptr;
    void* shootSound = nullptr;
    float volume = 0;
};

