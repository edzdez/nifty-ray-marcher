#include "Camera.h"

#include <optional>

#include "../utility/Drawable.h"
#include "../utility/Vec2D.h"

Camera::Camera()
    : Camera({0, 0}, 10)
{
    m_position.reset();
}

Camera::Camera(const Vec2D &position, float radius)
    : m_position(position)
    , m_radius(radius)
    , m_angle(0)
{
    setColor(sf::Color::Blue);
}

auto Camera::getPosition() const -> std::optional<Vec2D>
{
    return m_position;
}

auto Camera::getRadius() const -> float
{
    return m_radius;
}

auto Camera::getAngle() const -> float
{
    return m_angle;
}

auto Camera::setPosition(const Vec2D &position) -> void
{
    m_position = position;
}

auto Camera::setPosition(float x, float y) -> void
{
    m_position = {x, y};
}

auto Camera::setRadius(float radius) -> void
{
    m_radius = radius;
}

auto Camera::setAngle(float angle) -> void
{
    m_angle = angle;
}

auto Camera::draw(sf::RenderWindow &renderWindow) const -> void
{
    sf::CircleShape shape(getRadius(), 50);
    shape.setOrigin(getRadius(), getRadius());

    auto position = getPosition();
    if (position)
        shape.setPosition(position.value().getX(), position.value().getY());
    else
        return;

    shape.setFillColor(getColor());

    renderWindow.draw(shape);
}
