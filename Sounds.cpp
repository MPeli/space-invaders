#include "Sounds.h"
#include "Logger.h"

Sounds::Sounds()
{
    Logger::get() << "Initializing sounds...\n";

    this->explosionSound = LoadSnd("sounds/EXPLOSION-Bang-04.wav");
    this->shootSound = LoadSnd("sounds/WEAPON-GUNSHOT-Rifle-Swish-02.wav");
}

void Sounds::shoot()
{
    PlaySnd(this->shootSound, this->volume);
}

void Sounds::explode()
{
    PlaySnd(this->explosionSound, this->volume);
}

void Sounds::setVolume(const float volume)
{
    this->volume = volume;
}

void Sounds::decreaseVolume()
{
    if (this->volume > 0)
    {
        this->volume -= 0.01;

        Logger::get() << "Volume was decreased to " << this->volume << "\n";
    }
}

void Sounds::increaseVolume()
{
    if (this->volume < 1)
    {
        this->volume += 0.01;

        Logger::get() << "Volume was increased to " << this->volume << "\n";
    }
}

void Sounds::tick(const Time currentTime)
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