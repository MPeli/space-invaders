#pragma once
#include <memory>
#include <unordered_map>

#include "Singleton.h"
#include "Slide.h"
#include "Sprite.h"
#include "Tickable.h"

class Projector : public Singleton<Projector>, public Tickable
{
    friend Singleton<Projector>;
public:
    Projector();

    void reset();
    void tick(const Time time) override;

private:
    SlideType activeSlide = SlideType::beginning;

    std::unordered_map<SlideType, std::unique_ptr<Slide>> slides;
};