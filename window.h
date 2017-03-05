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

      rend = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

    ~Window() {
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(w);
      SDL_Quit();
    }

    Window(Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&) = delete;
    Window& operator=(Window&&) = delete;

    SDL_Renderer* getRenderer() {
      return rend;
    }

    void clear() {
      SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
      SDL_RenderClear(rend);
    }

    void present() {
      SDL_RenderPresent(rend);
    }

  private:
    SDL_Window* w;
    SDL_Renderer* rend;
};
