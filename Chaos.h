#pragma once
#include "GameComponent.h"
#include "Brain.h"

class Chaos : public Brain
{
public:
	void compute(GameComponent & component, const Tickable::Time currentTime) override
	{
		const float speed = 0.05;
		const int distance = 40;
		float dx = 0;
		float dy = 0;
		if (component.seed % 8 == 0)
		{
			// circular motion
			dx = std::sin(currentTime * speed - component.seed) * distance;
			dy = std::cos(currentTime * speed - component.seed) * distance;
		}
		else if (component.seed % 2 == 0)
		{
			// diagonal motion |\|
			dx = std::sin(currentTime * speed - component.seed) * distance;
			dy = std::sin(currentTime * speed - component.seed) * distance;
		}
		else
		{
			// diagonal motion |/|
			dx = - std::cos(currentTime * speed - component.seed) * distance;
			dy = std::cos(currentTime * speed - component.seed) * distance;
		}

		component.position.x = component.basePosition.x + dx;
		component.position.y = component.basePosition.y + dy;
	}
};
