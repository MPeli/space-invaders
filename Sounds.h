#pragma once
#include "lib/leetlib.h"
#include "Logger.h"
#include "Tickable.h"

class Sounds : Tickable
{
private:
    void* explosionSound;
    void* shootSound;
    float volume = 0;
    Sounds()
    {
        this->explosionSound = LoadSnd("sounds/EXPLOSION-Bang-04.wav");
        this->shootSound = LoadSnd("sounds/WEAPON-GUNSHOT-Rifle-Swish-02.wav");
    }
public:
    static Sounds& get()
    {
        static Sounds sounds;
        return sounds;
    }

    void shoot()
    {
        PlaySnd(this->shootSound, this->volume);
    }

    void explode()
    {
        PlaySnd(this->explosionSound, this->volume);
    }

    void setVolume(const float volume)
    {
        this->volume = volume;
    }

    void decreaseVolume()
    {
        if (this->volume > 0)
        {
            this->volume -= 0.01;

            Logger::get() << "Volume was decreased to " << this->volume << "\n";
        }
    }

    void increaseVolume()
    {
        if (this->volume < 1)
        {
            this->volume += 0.01;

            Logger::get() << "Volume was increased to " << this->volume << "\n";
        }
    }

    void tick(const Time currentTime) override
    {
        if (IsKeyDown(VK_ADD))
        {
            this->increaseVolume();
        }
        else if (IsKeyDown(VK_SUBTRACT))
        {
            this->decreaseVolume();
        }
    }
};

