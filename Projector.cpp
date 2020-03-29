#include "Projector.h"
#include "Beginning.h"
#include "Level01.h"
#include "End.h"
#include "Logger.h"

Projector::Projector() : sprites(Sprites::get())
{
    Logger::get() << "Initializing projector...\n";

    this->slides.emplace(SlideType::beginning, std::make_unique<Beginning>());
    this->slides.emplace(SlideType::level01, std::make_unique<Level01>());
    this->slides.emplace(SlideType::end, std::make_unique<End>());
}


void Projector::reset()
{
    for (auto& slide : slides)
    {
        slide.second->reset();
    }

}

void Projector::tick(const Time time)
{
    auto search = this->slides.find(this->activeSlide);
    search->second->tick(time);

    this->activeSlide = search->second->getNextSlide();
}