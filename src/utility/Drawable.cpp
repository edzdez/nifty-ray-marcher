#include "Drawable.h"

#include <SFML/Graphics.hpp>

Drawable::~Drawable() = default;

auto Drawable::getColor() const -> sf::Color
{
    return m_color;
}

auto Drawable::setColor(sf::Color color) -> void
{
    m_color = color;
}
