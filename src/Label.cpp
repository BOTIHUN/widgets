#include "Label.hpp"
#include "Math.hpp"
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
Label::Label(SDL_Renderer *renderer, const std::string &text, int font_size,
             const ColorRGBA &color, Callback OnHoverCallback,
             Callback NotOnHoverCallback)
    : Widget(renderer), text(text), color(color),
      OnHoverCallback(OnHoverCallback), NotOnHoverCallback(NotOnHoverCallback) {
  font = TTF_OpenFont(DEFAULT_FONT_PATH, font_size);
  surface = TTF_RenderText_Solid(font, text.c_str(),
                                 {color.r, color.g, color.b, color.a});
  texture = SDL_CreateTextureFromSurface(GetRenderer(), surface);
}
void Label::Handle(const SDL_Event &) {
  SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
}
void Label::Update() {
  if (PointInRect(mouse_pos.x, mouse_pos.y, GetShape().pos.x, GetShape().pos.y,
                  GetShape().w, GetShape().h))
    OnHoverCallback(this);
  else
    NotOnHoverCallback(this);
  SetShape({{GetShape().pos.x, GetShape().pos.y}, surface->w, surface->h});
}
void Label::Show() {
  SDL_Rect dest = {GetShape().pos.x, GetShape().pos.y, GetShape().w,
                   GetShape().h};
  SDL_RenderCopy(GetRenderer(), texture, nullptr, &dest);
}
Label::~Label() {
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font);
}
ColorRGBA Label::GetColor() const { return color; }
void Label::SetColor(const ColorRGBA &color) {
  SDL_FreeSurface(surface);
  surface = TTF_RenderText_Solid(font, text.c_str(),
                                 {color.r, color.g, color.b, color.a});
  SDL_DestroyTexture(texture);
  texture = SDL_CreateTextureFromSurface(GetRenderer(), surface);
}
