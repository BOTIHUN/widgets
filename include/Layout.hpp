#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include "Widget.hpp"
#include <memory>
#include <vector>
/*
 * should not alter widgets handle and show behaviour
 * may alter widgets shape
 */
class Layout {
  std::vector<std::weak_ptr<Widget>> widgets;
  SDL_Renderer *renderer;

public:
  Layout(SDL_Renderer *renderer);
  virtual ~Layout() = default;
};
#endif
