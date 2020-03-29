#include "Beginning.h"
#include "Logger.h"

Beginning::Beginning()
{
    Logger::get() << "Initializing the beginning slide...\n";
}

SlideType Beginning::getNextSlide()
{
    if (IsKeyDown(VK_SPACE))
    {
        return SlideType::level01;
    }

    return SlideType::beginning;
}

void Beginning::reset()
{

}

void Beginning::tick(const Time currentTime)
{
    for (auto& text : texts)
    {
        text.tick(currentTime);
    }
}