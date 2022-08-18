#include "CircleObject.h"

#include <SFML/Graphics.hpp>

#include "../utility/Vec2D.h"
#include "CollisionObject.h"

CircleObject::CircleObject(const Vec2D &position, float radius)
    : CollisionObject(position)
    , m_radius(radius)
{
}

auto CircleObject::getRadius() const -> float
{
    return m_radius;
}

auto CircleObject::setRadius(float radius) -> void
{
    m_radius = radius;
}

auto CircleObject::computeDistance(float x, float y) const -> float
{
    return std::max((getPosition() - Vec2D(x, y)).norm() - getRadius(), 0.f);
}

auto CircleObject::draw(sf::RenderWindow &renderWindow) const -> void
{
    sf::CircleShape shape(getRadius(), 50);
    shape.setOrigin(getRadius(), getRadius());

    auto position = getPosition();
    shape.setPosition(position.getX(), position.getY());

    shape.setFillColor(getColor());

    renderWindow.draw(shape);
}