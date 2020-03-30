#pragma once

#include "GameComponent.h"

enum class BrainType
{
    classic,
    chaos
};

class Brain
{
public:
	virtual void compute(GameComponent& component, const Tickable::Time currentTime) = 0;
};

