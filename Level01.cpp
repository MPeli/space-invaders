#include "Level01.h"
#include "Logger.h"

#include <algorithm>
#include "Classic.h"
#include "CollisionDetector.h"

Level01::Level01()
{
    Logger::get() << "Initializing the level01 slide...\n";
    this->brain = std::make_unique<Classic>();
}

SlideType Level01::getNextSlide()
{
    const auto& [player, bullets, enemies] = GameComponents::get().getAllComponents();

    auto allDead = std::all_of(enemies.cbegin(), enemies.cend(), [](const Enemy& enemy)
        {
            return !enemy.visible;
        });

    if (allDead)
    {
        return SlideType::betweenLevels;
    }

    return SlideType::level01;
}