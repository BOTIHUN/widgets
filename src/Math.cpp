#include "Math.hpp"
bool PointInRect(int px, int py, int rx, int ry, int rw, int rh) {
  return (px >= rx && px <= rx + rw) && (py >= ry && py <= ry + rh);
}
void Rect::SetPos(int x, int y) {
  pos.x = x;
  pos.y = y;
}
