#include "CollisionObject.h"

#include "../utility/Drawable.h"
#include "../utility/Vec2D.h"
#include "Camera.h"

CollisionObject::CollisionObject(const Vec2D &position)
    : m_position(position)
{
}

CollisionObject::~CollisionObject() = default;

auto CollisionObject::getPosition() const -> Vec2D
{
    return m_position;
}

auto CollisionObject::setPosition(const Vec2D &position) -> void
{
    m_position = position;
}
