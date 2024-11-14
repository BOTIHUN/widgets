#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "Math.hpp"
#include "Widget.hpp"
class Button : public Widget {
  Rect shape;
  ColorRGBA color_background;
  bool mouse_down, pressing;
  Coord2D mouse_pos;

public:
  Button(SDL_Renderer *renderer);
  void Handle(const SDL_Event &event) override;
  void Update() override;
  void Show() override;
};
#endif
