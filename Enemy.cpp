#include "Enemy.h"

int Enemy::s_seed = 0;


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
	this->seed = Enemy::s_seed;
	this->reset();
	++Enemy::s_seed;
}

void Enemy::reset() noexcept
{
	this->basePosition = { (seed % 10) * 60 + 120.f, (seed / 10) * 60 + 70.f };
	this->size = { (10 + ((seed) % 17)) * 2, (10 + ((seed) % 17)) * 2 };
	this->visible = true;
}

void Enemy::tick(const Time time)
{
	if (!this->visible)
	{
		return;
	}

	int dx = 0, dy = 0;
	const int n1 = time + seed * seed + seed * seed * seed;
	const int n2 = time + seed + seed * seed + seed * seed * seed * 3;
	constexpr float twoPi = 2 * std::numbers::pi;
	if (((n1 >> 6) & 0x7) == 0x7)
	{
		const int radius = 20 + ((seed * seed) % 9);
		const float angle = (n1 & 0x7f) / 64.0f * twoPi;

		dx = radius * (1 - cos(angle));
		dy = radius * sin(angle);
	}

	if (((n2 >> 8) & 0xf) == 0xf)
	{
		const int distance = 150 + ((seed * seed) % 9);
		const float angle = (n2 & 0xff) / 256.0f * twoPi;

		dy += distance * (1 - cos(angle));
	}

	this->position = this->basePosition + Position(dx, dy);

	// Compute bounding box
	this->recomputeBoundingBox();

	this->draw();
}