#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "Math.hpp"
#include <SDL2/SDL.h>

class Widget {
  SDL_Renderer *renderer;
  static constexpr Rect DefaultShape{{0, 0}, 150, 75};
  Rect shape;

protected:
  SDL_Renderer *GetRenderer();

public:
  Widget(SDL_Renderer *);
  virtual void Handle(const SDL_Event &) = 0;
  virtual void Update() = 0;
  virtual void Show() = 0;
  virtual ~Widget() = default;
  Rect GetShape() const;
  void SetShape(const Rect &);
};
#endif
