#include "March.h"

March::March(const Vec2D &position, float radius, const Vec2D &start, const Vec2D &end)
    : m_circle(radius, 50)
    , m_start(start)
    , m_end(end)
{
    m_circle.setOrigin(radius, radius);
    m_circle.setPosition({position.getX(), position.getY()});
    m_circle.setFillColor(sf::Color{0, 0, 0, 0});
    m_circle.setOutlineThickness(1.4f);
    m_circle.setOutlineColor(sf::Color::Green);
}

auto March::draw(sf::RenderWindow &renderWindow) const -> void
{
    renderWindow.draw(m_circle);

    sf::Vertex line[] = {sf::Vertex(sf::Vector2(m_start.getX(), m_start.getY())),
                         sf::Vertex(sf::Vector2(m_end.getX(), m_end.getY()))};
    line[0].color = sf::Color::Blue;
    line[1].color = sf::Color::Blue;
    renderWindow.draw(line, 2, sf::Lines);
}
