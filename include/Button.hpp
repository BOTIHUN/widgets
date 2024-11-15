#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "Math.hpp"
#include "Widget.hpp"
class Button : public Widget {
  Rect shape;
  static constexpr ColorRGBA DefaultColorBackground{150, 150, 150, 255},
      DefaultColorBackgroundFaded{100, 100, 100, 255};
  ColorRGBA color_background;
  bool mouse_down, pressing, clicked;
  Coord2D mouse_pos;
  static void DefaultCallback(Button *) {}
  typedef void (*Callback)(Button *);
  Callback ClickedCallback;
  Callback NotClickedCallback;
  static void DefaultPressingCallback(Button *button) {
    button->SetColorBackground(DefaultColorBackgroundFaded);
  }
  Callback PressingCallback;
  static void DefaultNotPressingCallback(Button *button) {
    button->SetColorBackground(DefaultColorBackground);
  }
  Callback NotPressingCallback;

public:
  Button(SDL_Renderer *renderer, Callback ClickedCallback = DefaultCallback,
         Callback NotClickedCallback = DefaultCallback,
         Callback PressingCallback = DefaultPressingCallback,
         Callback NotPressingCallback = DefaultNotPressingCallback);
  void Handle(const SDL_Event &event) override;
  void Update() override;
  void Show() override;
  ColorRGBA GetColorBackground() const;
  void SetColorBackground(const ColorRGBA &);
};
#endif
