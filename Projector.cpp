#include "Projector.h"
#include "Beginning.h"
#include "Level01.h"
#include "Level02.h"
#include "End.h"
#include "Logger.h"
#include "Chaos.h"
#include "Classic.h"
#include "BetweenLevels.h"

Projector::Projector() : sprites(Sprites::get())
{
    Logger::get() << "Initializing projector...\n";

    this->slides.emplace(SlideType::beginning, std::make_unique<Beginning>());
    this->slides.emplace(SlideType::level01, std::make_unique<Level01>());
    this->slides.emplace(SlideType::betweenLevels, std::make_unique<BetweenLevels>());
    this->slides.emplace(SlideType::level02, std::make_unique<Level02>());
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

    auto newSlide = search->second->getNextSlide();

    if (newSlide != this->activeSlide)
    {
        search->second->reset();
        this->activeSlide = newSlide;
    }
}