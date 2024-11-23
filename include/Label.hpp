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
  std::string text;
  static constexpr ColorRGBA DEFAULT_COLOR{0, 0, 0, 0};
  ColorRGBA color;
  Coord2D mouse_pos;
  typedef void (*Callback)(Label *label);
  static void DEFAULT_ON_HOVER_CALLBACK(Label *label) {
    label->SetColor({90, 90, 90, 255});
  }
  Callback OnHoverCallback;
  static void DEFAULT_NOT_ON_HOVER_CALLBACK(Label *label) {
    label->SetColor(DEFAULT_COLOR);
  }
  Callback NotOnHoverCallback;

public:
  Label(SDL_Renderer *renderer, const std::string &text,
        int font_size = DEFAULT_FONT_SIZE,
        const ColorRGBA &color = DEFAULT_COLOR,
        Callback OnHoverCallback = DEFAULT_ON_HOVER_CALLBACK,
        Callback NotOnHoverCallback = DEFAULT_NOT_ON_HOVER_CALLBACK);
  void Handle(const SDL_Event &) override;
  void Update() override;
  void Show() override;
  ~Label();
  ColorRGBA GetColor() const;
  void SetColor(const ColorRGBA &color);
};
#endif
