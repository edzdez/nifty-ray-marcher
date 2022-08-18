#ifndef NIFTY_RAY_MARCHER_RANDOM_H
#define NIFTY_RAY_MARCHER_RANDOM_H

#include <random>

class Random
{
  public:
    Random();

    auto next() -> float;

  private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_real_distribution<float> dist;
};

#endif // NIFTY_RAY_MARCHER_RANDOM_H
