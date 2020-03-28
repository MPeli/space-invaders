#include "GameComponent.h"

GameComponent::GameComponent(const Sprite& sprite) : sprite(sprite)
{

}

void GameComponent::draw()
{
    DrawSprite(sprite, position.x, position.y, size.width, size.height, angle, 0xffffffff);
}