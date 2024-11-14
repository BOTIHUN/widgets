#ifndef MATH_HPP
#define MATH_HPP
#include <cstdint>

bool PointInRect(int px, int py, int rx, int ry, int rw, int rh);
struct Coord2D {
  int x{0}, y{0};
};
struct ColorRGBA {
  uint8_t r{0}, g{0}, b{0}, a{0};
};
struct Rect {
  Coord2D pos;
  int w{0}, h{0};
};

#endif
