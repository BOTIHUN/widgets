#include "Button.hpp"
#include "Math.hpp"
#include "SDLSupport.hpp"

Button::Button(SDL_Renderer *renderer, Callback ClickedCallback,
               Callback NotClickedCallback, Callback PressingCallback,
               Callback NotPressingCallback)
    : Widget(renderer), mouse_down(false), pressing(false), clicked(false),
      ClickedCallback(ClickedCallback), NotClickedCallback(NotClickedCallback),
      PressingCallback(PressingCallback),
      NotPressingCallback(NotPressingCallback) {
  shape = {{100, 100}, 250, 100};
  color_background = DefaultColorBackground;
}
void Button::Handle([[maybe_unused]] const SDL_Event &event) {
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
    PressingCallback(this);
  else
    NotPressingCallback(this);

  if (clicked)
    ClickedCallback(this);
  else
    NotClickedCallback(this);
}
void Button::Show() {
  SDL_SetRenderDrawColor(GetRenderer(), color_background.r, color_background.g,
                         color_background.b, color_background.a);
  SDL_Rect temp{shape.pos.x, shape.pos.y, shape.w, shape.h};
  SDL_RenderFillRect(GetRenderer(), &temp);
}

ColorRGBA Button::GetColorBackground() const { return color_background; }
void Button::SetColorBackground(const ColorRGBA &color) {
  color_background = color;
}
