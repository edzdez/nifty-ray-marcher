#include "RaymarcherApp.h"

constexpr static auto WIDTH = 800;
constexpr static auto HEIGHT = 800;
constexpr static auto TARGET_FPS = 60;

constexpr static auto TITLE = "Raymarcher";

auto main() -> int
{
    RaymarcherApp app(TITLE, WIDTH, HEIGHT, TARGET_FPS);
    return app.run();
}
