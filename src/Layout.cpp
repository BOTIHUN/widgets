#include "Layout.hpp"
#include <stdexcept>

Layout::Layout(SDL_Renderer *renderer) : renderer(renderer) {}

void Layout::HandleWidgets(const SDL_Event &event) {
  for (auto widget_ptr : widgets) {
    if (auto widget = widget_ptr.lock()) {
      widget->Handle(event);
    } else {
      throw std::runtime_error("non existing widget pointer in Layout");
    }
  }
}

void Layout::ShowWidgets() {
  for (auto widget_ptr : widgets) {
    if (auto widget = widget_ptr.lock()) {
      widget->Show();
    } else {
      throw std::runtime_error("non existing widget pointer in Layout");
    }
  }
}

void Layout::UpdateWidgets() {
  for (auto widget_ptr : widgets) {
    if (auto widget = widget_ptr.lock()) {
      widget->Update();
    } else {
      throw std::runtime_error("non existing widget pointer in Layout");
    }
  }
}
