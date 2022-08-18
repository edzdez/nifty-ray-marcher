#include "RectangleObject.h"

#include <SFML/Graphics.hpp>

#include "../utility/Vec2D.h"
#include "CollisionObject.h"

RectangleObject::RectangleObject(const Vec2D &m_position, float width, float height)
    : CollisionObject(m_position)
    , m_width(width)
    , m_height(height)
{
}

auto RectangleObject::getWidth() const -> float
{
    return m_width;
}

auto RectangleObject::getHeight() const -> float
{
    return m_height;
}

auto RectangleObject::setWidth(float width) -> void
{
    m_width = width;
}

auto RectangleObject::setHeight(float height) -> void
{
    m_height = height;
}

auto RectangleObject::computeDistance(float x, float y) const -> float
{
    const auto center = getPosition();
    const auto dx = std::max(std::abs(x - center.getX()) - getWidth() / 2, 0.f);
    const auto dy = std::max(std::abs(y - center.getY()) - getHeight() / 2, 0.f);

    const Vec2D resultant(dx, dy);
    return resultant.norm();
}

auto RectangleObject::draw(sf::RenderWindow &renderWindow) const -> void
{
    sf::RectangleShape shape(sf::Vector2(getWidth(), getHeight()));
    shape.setOrigin(getWidth() / 2, getHeight() / 2);

    auto position = getPosition();
    shape.setPosition(position.getX(), position.getY());

    shape.setFillColor(getColor());

    renderWindow.draw(shape);
}
