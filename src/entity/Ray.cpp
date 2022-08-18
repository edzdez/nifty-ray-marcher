#include "Ray.h"

#include <vector>

#include "../utility/Drawable.h"

Ray::Ray(std::vector<March> marches)
    : m_marches(std::move(marches))
{
}

auto Ray::draw(sf::RenderWindow &renderWindow) const -> void
{
    for (const auto &march : m_marches)
        march.draw(renderWindow);
}
