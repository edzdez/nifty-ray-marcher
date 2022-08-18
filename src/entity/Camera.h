#ifndef NIFTY_RAY_MARCHER_CAMERA_H
#define NIFTY_RAY_MARCHER_CAMERA_H

#include <optional>

#include "../utility/Drawable.h"
#include "../utility/Vec2D.h"

class Camera : public Drawable
{
  public:
    Camera();
    explicit Camera(const Vec2D &position, float radius = 10);

    [[nodiscard]] auto getPosition() const -> std::optional<Vec2D>;
    [[nodiscard]] auto getRadius() const -> float;
    [[nodiscard]] auto getAngle() const -> float;

    auto setPosition(const Vec2D &position) -> void;
    auto setPosition(float x, float y) -> void;
    auto setRadius(float radius) -> void;
    auto setAngle(float angle) -> void;

    auto draw(sf::RenderWindow &renderWindow) const -> void override;

  private:
    std::optional<Vec2D> m_position;
    float m_radius;
    float m_angle;
};

#endif // NIFTY_RAY_MARCHER_CAMERA_H
