#pragma once

#include <SDL2/SDL.h>

class RenderObject {
  public:
    virtual bool render(SDL_Renderer*) = 0;
};
