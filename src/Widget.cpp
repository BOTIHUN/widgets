#include "Widget.hpp"

Widget::Widget(SDL_Renderer *renderer)
    : renderer(renderer), shape(DefaultShape) {}
SDL_Renderer *Widget::GetRenderer() { return renderer; }
Rect &Widget::GetShape() { return shape; }
void Widget::SetShape(const Rect &s) { shape = s; }
