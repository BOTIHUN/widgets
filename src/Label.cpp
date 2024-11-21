#include "Label.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
Label::Label(SDL_Renderer *renderer, const std::string &text)
    : Widget(renderer) {
  font = TTF_OpenFont(DEFAULT_FONT_PATH, DEFAULT_FONT_SIZE);
  surface = TTF_RenderText_Solid(
      font, text.c_str(),
      {DEFAULT_COLOR.r, DEFAULT_COLOR.g, DEFAULT_COLOR.b, DEFAULT_COLOR.a});
  texture = SDL_CreateTextureFromSurface(GetRenderer(), surface);
}
void Label::Handle(const SDL_Event &) {}
void Label::Update() {
  SetShape({{GetShape().pos.x, GetShape().pos.y}, surface->w, surface->h});
}
void Label::Show() {
  SDL_Rect dest = {GetShape().pos.x, GetShape().pos.y, GetShape().w,
                   GetShape().h};
  SDL_RenderCopy(GetRenderer(), texture, nullptr, &dest);
}
Label::~Label() {
  SDL_FreeSurface(surface);
  TTF_CloseFont(font);
}
