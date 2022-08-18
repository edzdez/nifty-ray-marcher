#ifndef NIFTY_RAY_MARCHER_APP_H
#define NIFTY_RAY_MARCHER_APP_H

#include <string_view>

#include <SFML/Graphics.hpp>

class App
{
  public:
    App(std::string_view title, int width, int height, int fps);
    virtual ~App() = 0;

    virtual auto run() -> int = 0;

  protected:
    virtual auto processEvents() -> void = 0;
    virtual auto update() -> void = 0;
    virtual auto draw() -> void = 0;

  protected:
    sf::RenderWindow m_window;

    int m_fps;
};

#endif // NIFTY_RAY_MARCHER_APP_H
