#ifndef NIFTY_RAY_MARCHER_VEC2D_H
#define NIFTY_RAY_MARCHER_VEC2D_H

#include <cmath>

class Vec2D
{
  public:
    Vec2D(float x, float y);

    [[nodiscard]] auto getX() const -> float;
    [[nodiscard]] auto getY() const -> float;

    auto setX(float x) -> void;
    auto setY(float y) -> void;

    auto operator+(const Vec2D &other) const -> Vec2D;
    auto operator-(const Vec2D &other) const -> Vec2D;

    auto norm() const -> float;

  private:
    float m_x{}, m_y{};
};

#endif // NIFTY_RAY_MARCHER_VEC2D_H
