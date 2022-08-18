#ifndef NIFTY_RAY_MARCHER_RAYMARCHERAPP_H
#define NIFTY_RAY_MARCHER_RAYMARCHERAPP_H

#include <array>
#include <exception>
#include <memory>
#include <vector>

#include "App.h"
#include "entity/Camera.h"
#include "entity/CircleObject.h"
#include "entity/CollisionObject.h"
#include "entity/Ray.h"
#include "entity/RectangleObject.h"
#include "utility/Random.h"
#include "utility/Vec2D.h"

class RaymarcherApp : public App
{
  public:
    const sf::Color CLEAR_COLOR{238, 238, 238, 255};
    const size_t NUM_OBJECTS{20};
    const float MIN_WIDTH{30};
    const float MAX_WIDTH{140};
    const float THRESHOLD = 0.01;

    enum class CollisionObjectType
    {
        RectangleObject = 0,
        CircleObject,
        NUM_OBJECTS,
    };

  public:
    RaymarcherApp(std::string_view title, int width, int height, int fps);

    auto run() -> int override;

  protected:
    auto processEvents() -> void override;
    auto update() -> void override;
    auto draw() -> void override;

  private:
    std::vector<std::unique_ptr<CollisionObject>> m_objects;
    std::optional<Ray> m_ray{};
    Camera m_camera;

    Random m_random;
};

#endif // NIFTY_RAY_MARCHER_RAYMARCHERAPP_H
