#include "Misc.h"

#include <array>

#include <SFML/Graphics.hpp>

#include "Random.h"

auto randomColor(Random &random) -> sf::Color
{
    return {static_cast<uint8_t>(random.next() * 256), static_cast<uint8_t>(random.next() * 256),
            static_cast<uint8_t>(random.next() * 256), 255};
}

auto degreeToRadian(float degree) -> float
{
    return degree / 180 * static_cast<float>(std::numbers::pi);
}

auto radianToDegree(float radian) -> float
{
    return 180 * radian / static_cast<float>(std::numbers::pi);
}

auto withinBounds(float a, float low, float high) -> bool
{
    return a >= low && a < high;
}