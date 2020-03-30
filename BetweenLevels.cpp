#include "BetweenLevels.h"
#include "BetweenLevels.h"
#include "GameComponents.h"
#include "Logger.h"
#include "Projector.h"

BetweenLevels::BetweenLevels()
{
    Logger::get() << "Initializing the between levels slide...\n";
}

SlideType BetweenLevels::getNextSlide()
{
    if (IsKeyDown(VK_SPACE))
    {
        return SlideType::level02;
    }

    return SlideType::betweenLevels;
}

void BetweenLevels::reset()
{

}

void BetweenLevels::tick(const Time currentTime)
{
    text.tick(currentTime);
}