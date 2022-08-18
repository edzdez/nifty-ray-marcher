#ifndef NIFTY_RAY_MARCHER_COLLISIONOBJECT_H
#define NIFTY_RAY_MARCHER_COLLISIONOBJECT_H

#include <optional>

#include "../utility/Drawable.h"
#include "../utility/Vec2D.h"
#include "Camera.h"

class CollisionObject : public Drawable
{
  public:
    explicit CollisionObject(const Vec2D &position);
    ~CollisionObject() override = 0;

    [[nodiscard]] auto getPosition() const -> Vec2D;

    auto setPosition(const Vec2D &position) -> void;

    [[nodiscard]] virtual auto computeDistance(float x, float y) const -> float = 0;

  private:
    Vec2D m_position;
};

#endif // NIFTY_RAY_MARCHER_COLLISIONOBJECT_H
