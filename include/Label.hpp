#ifndef LABEL_HPP
#define LABEL_HPP
#include "Widget.hpp"
#include <SDL2/SDL_ttf.h>

class Label : public Widget {
  static constexpr const char *DEFAULT_FONT_PATH =
      "res/fonts/JetBrainsMonoNerdFont-Regular.ttf";
  static constexpr int DEFAULT_FONT_SIZE = 24;
  TTF_Font *font;

public:
  void Handle(const SDL_Event &) override;
  void Update() override;
  void Show() override;
};
#endif
