#include "Canvas.h"
#include <algorithm>


void Canvas::moveIn(GameComponent& component) const
{
    component.position.x = std::clamp(static_cast<int>(component.position.x), 0, width);
    component.position.y = std::clamp(static_cast<int>(component.position.y), 0, height);
}