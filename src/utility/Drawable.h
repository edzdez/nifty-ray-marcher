#ifndef NIFTY_RAY_MARCHER_DRAWABLE_H
#define NIFTY_RAY_MARCHER_DRAWABLE_H

#include <SFML/Graphics.hpp>

class Drawable
{
  public:
    virtual ~Drawable() = 0;

    [[nodiscard]] auto getColor() const -> sf::Color;

    auto setColor(sf::Color color) -> void;

    virtual auto draw(sf::RenderWindow &renderWindow) const -> void = 0;

  protected:
    sf::Color m_color;
};

#endif // NIFTY_RAY_MARCHER_DRAWABLE_H
