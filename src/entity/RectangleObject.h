#ifndef NIFTY_RAY_MARCHER_RECTANGLEOBJECT_H
#define NIFTY_RAY_MARCHER_RECTANGLEOBJECT_H

#include <SFML/Graphics.hpp>

#include "../utility/Vec2D.h"
#include "CollisionObject.h"

class RectangleObject : public CollisionObject
{
  public:
    RectangleObject(const Vec2D &m_position, float width, float height);

    [[nodiscard]] auto getWidth() const -> float;
    [[nodiscard]] auto getHeight() const -> float;

    auto setWidth(float width) -> void;
    auto setHeight(float height) -> void;

    [[nodiscard]] auto computeDistance(float x, float y) const -> float override;

    auto draw(sf::RenderWindow &renderWindow) const -> void override;

  private:
    float m_width{}, m_height{};
};

#endif // NIFTY_RAY_MARCHER_RECTANGLEOBJECT_H
