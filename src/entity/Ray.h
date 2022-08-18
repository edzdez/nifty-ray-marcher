#ifndef NIFTY_RAY_MARCHER_RAY_H
#define NIFTY_RAY_MARCHER_RAY_H

#include <vector>

#include "../utility/Drawable.h"
#include "March.h"

class Ray : Drawable
{
  public:
    explicit Ray(std::vector<March> marches);

    auto draw(sf::RenderWindow &renderWindow) const -> void override;

  private:
    std::vector<March> m_marches;
};

#endif // NIFTY_RAY_MARCHER_RAY_H
