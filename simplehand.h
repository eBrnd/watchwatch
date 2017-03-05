#pragma once

#include <functional>

#include "renderobject.h"

template <int CENTER_X, int CENTER_Y, int LENGTH>
class SimpleHand : public RenderObject {
  public:
    SimpleHand(std::function<double()>& angle_f)
      : angle_f(angle_f) { }

    virtual bool render(SDL_Renderer* rend) {
      double angle = angle_f();
      int x = LENGTH * sin(angle);
      int y = LENGTH * cos(angle);

      SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(rend, CENTER_X, CENTER_Y, CENTER_X + x, CENTER_Y + y);
      return true;
    }

  private:
    std::function<double()> angle_f;
};
