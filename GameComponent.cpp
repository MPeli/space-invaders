#include "GameComponent.h"

GameComponent::GameComponent(const Sprite& sprite) : sprite(sprite)
{

}

void GameComponent::draw()
{
    DrawBoundingBox(minmax.first.x, minmax.first.y, minmax.second.x, minmax.second.y);
    DrawSprite(sprite, position.x, position.y, size.width, size.height, angle, 0xffffffff);
}