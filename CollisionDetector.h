#pragma once
#include <utility>

#include "Container.h"
#include "Vector2D.h"
#include <optional>

class CollisionDetector
{
public:
    template <typename T1, typename T2>
    static std::optional<std::pair<std::reference_wrapper<T1>, std::reference_wrapper<T2>>> getFirstCollision(Container<T1>& first, Container<T2>& second)
    {
        for (auto& primary : first)
        {
            if (primary.visible)
            {
                const auto& primaryBoundingBox = primary.getBoundingBox();

                for (auto& secondary : second)
                {
                    if (secondary.visible)
                    {
                        const auto& secondaryBoundingBox = secondary.getBoundingBox();

                        // Colision detected
                        if (collide(primaryBoundingBox, secondaryBoundingBox))
                        {
                            return std::optional(std::make_pair(std::ref(primary), std::ref(secondary)));
                            break;
                        }
                    }
                }
            }
        }

        return {};
    }

private:
    // AABB algorithm
    static bool collide(const std::pair<Vector2D, Vector2D>& left, const std::pair<Vector2D, Vector2D>& right)
    {
        const auto& [min01, max01] = left;
        const auto& [min02, max02] = right;

        return max01.x > min02.x && min01.x < max02.x&& max01.y > min02.y && min01.y < max02.y;
    }
};

