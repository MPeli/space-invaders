#pragma once
#include "GameComponent.h"
#include <numbers>

class Enemy : public GameComponent<Enemy>
{
private:
	static int s_seed;
	Seed seed;

	void init() noexcept
	{
		this->seed = Enemy::s_seed;
		this->basePosition = { (seed % 10) * 60 + 120, (seed / 10) * 60 + 70 };
		this->size = { (10 + ((seed) % 17)), (10 + ((seed) % 17)) };

		++Enemy::s_seed;
	}

public:
	const Sprite& sprite;
	Enemy(const Sprite& sprite) noexcept : sprite(sprite)
	{
		this->init();
	}

	Enemy(const Enemy& copy) noexcept : sprite(copy.sprite)
	{
		this->init();
	}

	void tick(const Time time)
	{
		int dx = 0, dy = 0;
		const int n1 = time + seed * seed + seed * seed * seed;
		const int n2 = time + seed + seed * seed + seed * seed * seed * 3;
		if (((n1 >> 6) & 0x7) == 0x7)
		{
			dx += (1 - cos((n1 & 0x7f) / 64.0f * 2.f * std::numbers::pi)) * (20 + ((seed * seed) % 9));
			dy += (sin((n1 & 0x7f) / 64.0f * 2.f * std::numbers::pi)) * (20 + ((seed * seed) % 9));
		}

		if (((n2 >> 8) & 0xf) == 0xf)
		{
			dy += (1 - cos((n2 & 0xff) / 256.0f * 2.f * 3.141592)) * (150 + ((seed * seed) % 9));
		}

		this->position = this->basePosition + Position(dx, dy);

		DrawSprite(sprite, position.x, position.y, size.width, size.height, angle, 0xffffffff);
	}
};