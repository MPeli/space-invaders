#include "Enemy.h"


Enemy::Enemy(const Sprite& sprite) noexcept : GameComponent(sprite)
{
	this->init();
}

Enemy::Enemy(const Enemy& copy) noexcept : GameComponent(copy.sprite)
{
	this->init();
}


void Enemy::init() noexcept
{
	this->reset();
	++Enemy::s_seed;
}

void Enemy::reset() noexcept
{
	this->basePosition = { (seed % 10) * 60 + 120.f, (seed / 10) * 60 + 70.f };
	this->position = this->basePosition;
	this->size = { (10 + ((seed) % 17)) * 2, (10 + ((seed) % 17)) * 2 };
	this->visible = true;
}

void Enemy::tick(const Time time)
{
	if (!this->visible)
	{
		return;
	}

	// Let the brain to do its work = compute new position

	// Compute bounding box
	this->recomputeBoundingBox();

	this->draw();
}