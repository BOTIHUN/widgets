#ifndef LABEL_HPP
#define LABEL_HPP
#include "Math.hpp"
#include "Widget.hpp"
#include <SDL2/SDL_ttf.h>
#include <string>

class Label : public Widget {
  static constexpr const char *DEFAULT_FONT_PATH =
      "res/fonts/JetBrainsMonoNerdFont-Regular.ttf";
  static constexpr int DEFAULT_FONT_SIZE = 24;
  TTF_Font *font;
  SDL_Surface *surface;
  SDL_Texture *texture;
  static constexpr ColorRGBA DEFAULT_COLOR{255, 255, 255, 255};

public:
  Label(SDL_Renderer *, const std::string &);
  void Handle(const SDL_Event &) override;
  void Update() override;
  void Show() override;
  ~Label();
};
#endif
