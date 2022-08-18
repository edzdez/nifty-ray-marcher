#ifndef NIFTY_RAY_MARCHER_CIRCLEOBJECT_H
#define NIFTY_RAY_MARCHER_CIRCLEOBJECT_H

#include <SFML/Graphics.hpp>

#include "../utility/Vec2D.h"
#include "CollisionObject.h"

class CircleObject : public CollisionObject
{
  public:
    CircleObject(const Vec2D &position, float radius);

    [[nodiscard]] auto getRadius() const -> float;

    auto setRadius(float radius) -> void;

    [[nodiscard]] auto computeDistance(float x, float y) const -> float override;

    auto draw(sf::RenderWindow &renderWindow) const -> void override;

  private:
    float m_radius{};
};

#endif // NIFTY_RAY_MARCHER_CIRCLEOBJECT_H
