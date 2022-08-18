#include "Random.h"

#include <random>

Random::Random()
    : rd()
    , mt(rd())
    , dist(0.0, 1.0)
{
}

auto Random::next() -> float
{
    return dist(mt);
}
