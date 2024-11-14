#ifndef WIDGET_HPP
#define WIDGET_HPP
#include <SDL2/SDL.h>
class Widget {
  SDL_Renderer *renderer;

protected:
  SDL_Renderer *GetRenderer();

public:
  Widget(SDL_Renderer *);
  virtual void Handle(const SDL_Event &) = 0;
  virtual void Update() = 0;
  virtual void Show() = 0;
  virtual ~Widget() = default;
};
#endif
