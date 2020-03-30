#pragma once

#include <numbers>
#include "Brain.h"
#include "GameComponent.h"

class Classic : public Brain
{
public:
	void compute(GameComponent& component, const Tickable::Time currentTime) override
    {
		const Seed seed = component.seed;

		int dx = 0, dy = 0;
		const int n1 = currentTime + seed * seed + seed * seed * seed;
		const int n2 = currentTime + seed + seed * seed + seed * seed * seed * 3;
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

		component.position = component.basePosition + Position(dx, dy);
    }
};

