#pragma once
#include "lib/leetlib.h"

class Sounds
{
private:
    void* explosionSound;
    void* shootSound;
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
        PlaySnd(this->shootSound, 1);
    }

    void explode()
    {
        PlaySnd(this->explosionSound, 1);
    }
};

