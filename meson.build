project('nifty-ray-marcher', 'cpp',
  default_options : ['cpp_std=c++20', 'warning_level=3'])

sfml_dep = dependency('sfml-all')

deps = [sfml_dep]
srcs = [
    'src/App.cpp',
    'src/main.cpp',
    'src/RaymarcherApp.cpp',
    'src/entity/Camera.cpp',
    'src/entity/CircleObject.cpp',
    'src/entity/CollisionObject.cpp',
    'src/entity/March.cpp',
    'src/entity/Ray.cpp',
    'src/entity/RectangleObject.cpp',
    'src/utility/Drawable.cpp',
    'src/utility/Misc.cpp',
    'src/utility/Random.cpp',
    'src/utility/Vec2D.cpp'
]

executable('nifty-ray-marcher', srcs,
  dependencies : deps)
