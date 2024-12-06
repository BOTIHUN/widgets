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
  void HandleWidgets(const SDL_Event &event);
  virtual void Organize() = 0;
  void UpdateWidgets();
  void ShowWidgets();
  virtual ~Layout() = default;
};
#endif
