#pragma once

#include "renderobject.h"

class Line : public RenderObject {
  public:
    virtual bool render(SDL_Renderer* rend) {
      SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(rend, 1, 1, 799, 599);
      return true;
    }
};
