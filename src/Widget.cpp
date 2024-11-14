#include "Widget.hpp"

Widget::Widget(SDL_Renderer *renderer) : renderer(renderer) {}
SDL_Renderer *Widget::GetRenderer() { return renderer; }
