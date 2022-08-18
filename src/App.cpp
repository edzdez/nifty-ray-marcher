#include "App.h"

#include <string_view>

#include <SFML/Graphics.hpp>

App::App(std::string_view title, int width, int height, int fps)
    : m_window(sf::VideoMode(width, height), title.data())
    , m_fps(fps)
{
}

App::~App() = default;
