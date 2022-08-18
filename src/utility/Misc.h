#ifndef NIFTY_RAY_MARCHER_MISC_H
#define NIFTY_RAY_MARCHER_MISC_H

#include <array>

#include <SFML/Graphics.hpp>

#include "Random.h"

auto randomColor(Random &random) -> sf::Color;
auto degreeToRadian(float degree) -> float;
auto radianToDegree(float degree) -> float;
auto withinBounds(float a, float low, float high) -> bool;

#endif // NIFTY_RAY_MARCHER_MISC_H
