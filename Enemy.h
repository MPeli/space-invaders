﻿#pragma once

#include <numbers>

#include "GameComponent.h"

class Enemy : public GameComponent
{
private:
	void init() noexcept;

public:
	Enemy(const Sprite& sprite) noexcept;
	Enemy(const Enemy& copy) noexcept;
	
	void reset() noexcept;
	void tick(const Time time);
};