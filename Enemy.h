#pragma once

#include <numbers>

#include "GameComponent.h"

class Enemy : public GameComponent
{
private:
	static int s_seed;
	Seed seed;

	void init() noexcept;

public:
	Enemy(const Sprite& sprite) noexcept;
	Enemy(const Enemy& copy) noexcept;

	void tick(const Time time);
};