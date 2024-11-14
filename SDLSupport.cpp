#include "SDLSupport.hpp"
bool LeftMouseDown(const SDL_Event &event) {
  return event.type == SDL_MOUSEBUTTONDOWN &&
         event.button.button == SDL_BUTTON_LEFT;
}
bool LeftMouseDown() {
  int x, y;
  uint32_t state = SDL_GetMouseState(&x, &y);
  return state & SDL_BUTTON(SDL_BUTTON_LEFT);
}
bool LeftMouseUp(const SDL_Event &event) {
  return event.type == SDL_MOUSEBUTTONUP &&
         event.button.button == SDL_BUTTON_LEFT;
}
