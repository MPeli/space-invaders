#pragma once
#include "GameComponent.h"

struct Canvas
{
public:
	void moveIn(GameComponent& component) const;

private:
	const int width = 800;
	const int height = 600;
};

