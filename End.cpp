#include "End.h"
#include "GameComponents.h"
#include "Logger.h"
#include "Projector.h"

End::End()
{
    Logger::get() << "Initializing the end slide...\n";
}

SlideType End::getNextSlide()
{
    if (IsKeyDown(VK_SPACE))
    {
        Projector::get().reset();
        return SlideType::level01;
    }

    return SlideType::end;
}

void End::reset()
{

}

void End::tick(const Time currentTime)
{
    text.tick(currentTime);
}