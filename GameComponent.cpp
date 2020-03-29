#include "GameComponent.h"

GameComponent::GameComponent(const Sprite& sprite) : sprite(sprite)
{

}

void GameComponent::draw()
{
    DrawBoundingBox(minmax.first.x, minmax.first.y, minmax.second.x, minmax.second.y);
    DrawSprite(sprite, position.x, position.y, size.width, size.height, angle, 0xffffffff);
}


void GameComponent::recomputeBoundingBox()
{
    if (this->angle)
    {
        Position p0 = { this->position.x - this->size.width / 2, this->position.y - this->size.height / 2 };
        Position p1 = { this->position.x - this->size.width / 2, this->position.y + this->size.height / 2 };
        Position p2 = { this->position.x + this->size.width / 2, this->position.y - this->size.height / 2 };
        Position p3 = { this->position.x + this->size.width / 2, this->position.y + this->size.height / 2 };

        p0.rotate(this->position, this->angle);
        p1.rotate(this->position, this->angle);
        p2.rotate(this->position, this->angle);
        p3.rotate(this->position, this->angle);

        auto minx = std::min<float>({ p0.x, p1.x, p2.x, p3.x });
        auto miny = std::min<float>({ p0.y, p1.y, p2.y, p3.y });

        auto maxx = std::max<float>({ p0.x, p1.x, p2.x, p3.x });
        auto maxy = std::max<float>({ p0.y, p1.y, p2.y, p3.y });

        this->minmax = std::make_pair(Vector2D{ minx, miny }, Vector2D{ maxx, maxy });
    }
    else
    {
        Position min = { this->position.x - this->size.width / 2, this->position.y - this->size.height / 2 };
        Position max = { this->position.x + this->size.width / 2, this->position.y + this->size.height / 2 };

        this->minmax = { min, max };
    }
}

std::pair<Vector2D, Vector2D>& GameComponent::getBoundingBox()
{
    return this->minmax;
}