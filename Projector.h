#pragma once
#include <memory>
#include <vector>

#include "Beginning.h"
#include "Slide.h"

class Projector
{
private:
    std::vector<std::unique_ptr<Slide>> slides = {
        std::make_unique<Beginning>(),
        std::make_unique<Level01>(),
        std::make_unique<End>()
    };
};

