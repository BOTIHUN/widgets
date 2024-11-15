#include "Button.hpp"
#include "SDLSupport.hpp"
#include <iostream>
Button::Button(SDL_Renderer *renderer)
    : Widget(renderer), mouse_down(false), pressing(false), clicked(false) {
  shape = {{100, 100}, 250, 100};
}
void Button::Handle(const SDL_Event &event) {
  if (!mouse_down || pressing)
    SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
}
void Button::Update() {
  mouse_down = LeftMouseDown();
  if (!mouse_down && pressing &&
      PointInRect(mouse_pos.x, mouse_pos.y, shape.pos.x, shape.pos.y, shape.w,
                  shape.h))
    clicked = true;
  else
    clicked = false;
  pressing = mouse_down && PointInRect(mouse_pos.x, mouse_pos.y, shape.pos.x,
                                       shape.pos.y, shape.w, shape.h);
  if (pressing)
    color_background = {120, 0, 0, 120};
  else
    color_background = {255, 0, 0, 255};

  if (clicked)
    std::cout << "clicked" << std::endl;
}
void Button::Show() {
  SDL_SetRenderDrawColor(GetRenderer(), color_background.r, color_background.g,
                         color_background.b, color_background.a);
  SDL_Rect temp{shape.pos.x, shape.pos.y, shape.w, shape.h};
  SDL_RenderFillRect(GetRenderer(), &temp);
}
