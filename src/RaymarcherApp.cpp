#include "RaymarcherApp.h"

#include <exception>
#include <memory>
#include <vector>

#include "App.h"
#include "entity/Camera.h"
#include "entity/CircleObject.h"
#include "entity/CollisionObject.h"
#include "entity/Ray.h"
#include "entity/RectangleObject.h"
#include "utility/Misc.h"
#include "utility/Random.h"
#include "utility/Vec2D.h"

RaymarcherApp::RaymarcherApp(std::string_view title, int width, int height, int fps)
    : App(title, width, height, fps)
    , m_camera()
    , m_random()
{
    m_window.setFramerateLimit(m_fps);
    const auto windowSize = m_window.getSize();

    for (size_t i = 0; i < NUM_OBJECTS; ++i)
    {
        // TODO: Factory?
        auto type =
            static_cast<CollisionObjectType>(m_random.next() * static_cast<double>(CollisionObjectType::NUM_OBJECTS));

        const Vec2D position(m_random.next() * static_cast<float>(windowSize.x),
                             m_random.next() * static_cast<float>(windowSize.y));

        std::unique_ptr<CollisionObject> collisionObject{nullptr};
        switch (type)
        {
        case CollisionObjectType::RectangleObject:
            collisionObject = std::make_unique<RectangleObject>(position, m_random.next() * MAX_WIDTH,
                                                                m_random.next() * (MAX_WIDTH - MIN_WIDTH) + MIN_WIDTH);
            break;
        case CollisionObjectType::CircleObject:
            collisionObject =
                std::make_unique<CircleObject>(position, m_random.next() * (MAX_WIDTH - MIN_WIDTH) / 2 + MIN_WIDTH);
            break;
        default:
            throw std::runtime_error("Unhandled shape type");
        }

        collisionObject->setColor(randomColor(m_random));
        m_objects.push_back(std::move(collisionObject));
    }
}

auto RaymarcherApp::run() -> int
{
    while (m_window.isOpen())
    {
        processEvents();

        update();

        m_window.clear(CLEAR_COLOR);
        draw();
        m_window.display();
    }

    return EXIT_SUCCESS;
}

auto RaymarcherApp::processEvents() -> void
{
    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
        if (event.type == sf::Event::MouseMoved)
        {
            auto locationEvent = event.mouseMove;
            m_camera.setPosition(static_cast<float>(locationEvent.x), static_cast<float>(locationEvent.y));
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            int angle = static_cast<int>(m_camera.getAngle());
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                m_camera.setAngle(static_cast<float>((angle + 1) % 360));
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                m_camera.setAngle(static_cast<float>((angle - 1) % 360));
        }
        if (event.type == sf::Event::KeyPressed)
        {
            int angle = static_cast<int>(m_camera.getAngle());
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                m_camera.setAngle(static_cast<float>((angle + 1) % 360));
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                m_camera.setAngle(static_cast<float>((angle - 1) % 360));
        }
    }
}

auto RaymarcherApp::update() -> void
{
    const auto cameraPosition = m_camera.getPosition();
    if (cameraPosition)
    {
        std::vector<March> marches;
        auto x{cameraPosition.value().getX()}, y{cameraPosition.value().getY()},
            angle{degreeToRadian(m_camera.getAngle())};
        auto windowSize{m_window.getSize()};
        auto windowWidth{static_cast<float>(windowSize.x)}, windowHeight{static_cast<float>(windowSize.y)};

        float last;
        do
        {
            float dist{std::numeric_limits<float>::max()};

            for (const auto &object : m_objects)
                dist = std::min(dist, object->computeDistance(x, y));

            auto newX{x + dist * std::cos(angle)}, newY{y + dist * std::sin(angle)};
            marches.emplace_back(Vec2D(x, y), dist, Vec2D(x, y), Vec2D(newX, newY));

            x = newX;
            y = newY;
            last = dist;
        } while (last > THRESHOLD && withinBounds(x - last * std::cos(angle), 0, windowWidth) &&
                 withinBounds(y - last * std::sin(angle), 0, windowHeight));

        m_ray = Ray(marches);
    }
}

auto RaymarcherApp::draw() -> void
{
    for (const auto &object : m_objects)
        object->draw(m_window);
    if (m_ray)
        m_ray.value().draw(m_window);

    m_camera.draw(m_window);
}
