#include "Vec2D.h"

#include <cmath>

Vec2D::Vec2D(float x, float y)
    : m_x(x)
    , m_y(y)
{
}

auto Vec2D::getX() const -> float
{
    return m_x;
}

auto Vec2D::getY() const -> float
{
    return m_y;
}

auto Vec2D::setX(float x) -> void
{
    m_x = x;
}

auto Vec2D::setY(float y) -> void
{
    m_y = y;
}

auto Vec2D::operator+(const Vec2D &other) const -> Vec2D
{
    return {getX() + other.getX(), getY() + other.getY()};
}

auto Vec2D::operator-(const Vec2D &other) const -> Vec2D
{
    return {getX() - other.getX(), getY() - other.getY()};
}

auto Vec2D::norm() const -> float
{
    return std::sqrt(getX() * getX() + getY() * getY());
}
