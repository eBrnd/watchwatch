#pragma once

#include <exception>
#include <string>
#include <SDL2/SDL.h>

template<int WIDTH, int HEIGHT>
class Window {
  public:
    Window() {
      if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("Can't init video");


      w = SDL_CreateWindow("watchwatch",
              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
              WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

      if (!w)
        throw std::runtime_error("Can't open window");

      surf = SDL_GetWindowSurface(w);
    }

    ~Window() {
      SDL_DestroyWindow(w);
      SDL_Quit();
    }

  private:
    SDL_Window* w;
    SDL_Surface* surf;
};
