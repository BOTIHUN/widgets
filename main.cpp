#include "Button.hpp"
#include "Label.hpp"
#include <SDL2/SDL.h>
#include <iostream>

void PrintClicked(Button *button) { std::cout << "clicked" << std::endl; }
int main() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }
  // Initialize SDL_ttf
  if (TTF_Init() == -1) {
    std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }
  // Create a window
  SDL_Window *window =
      SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (!window) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  // Create a renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Main loop flag
  bool running = true;
  // Event handler
  SDL_Event event;

  Widget *button = new Button(renderer, &PrintClicked);
  Widget *label = new Label(renderer, "Hello World!");
  label->GetShape().SetPos(120, 120);
  // Main loop
  while (running) {
    // Handle events while
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
      button->Handle(event);
    }
    button->Update();
    label->Update();
    // Set the drawing color (red, green, blue, alpha)
    SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);

    // Clear the screen
    SDL_RenderClear(renderer);
    button->Show();
    label->Show();
    // Present the renderer (update the screen)
    SDL_RenderPresent(renderer);
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
