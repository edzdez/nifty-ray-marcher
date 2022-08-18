#ifndef NIFTY_RAY_MARCHER_MARCH_H
#define NIFTY_RAY_MARCHER_MARCH_H

#include <SFML/Graphics.hpp>

#include "../utility/Drawable.h"
#include "../utility/Vec2D.h"

class March : public Drawable
{
  public:
    March(const Vec2D &position, float radius, const Vec2D &start, const Vec2D &end);

    auto draw(sf::RenderWindow &renderWindow) const -> void override;

  private:
    sf::CircleShape m_circle;
    Vec2D m_start, m_end;
};

#endif // NIFTY_RAY_MARCHER_MARCH_H
