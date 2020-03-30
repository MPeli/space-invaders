#include "Level02.h"
#include "Logger.h"
#include "Chaos.h"

#include "GameComponents.h"

#include <algorithm>

Level02::Level02()
{
    Logger::get() << "Initializing the level02 slide...\n";
    this->brain = std::make_unique<Chaos>();
}

SlideType Level02::getNextSlide()
{
    const auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

    auto allDead = std::all_of(enemies.cbegin(), enemies.cend(), [](const Enemy& enemy)
        {
            return !enemy.visible;
        });

    if (allDead)
    {
        this->stop();
        return SlideType::end;
    }

    return SlideType::level02;
}
