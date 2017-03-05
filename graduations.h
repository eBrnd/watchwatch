#pragma once

#include "renderobject.h"

static const auto pi = std::acos(-1);

template<int CENTER_X, int CENTER_Y, int INNER_RADIUS, int OUTER_RADIUS, int NUMBER>
class Graduations : public RenderObject {

  virtual bool render(SDL_Renderer* rend) {
    for (int i = 0; i < NUMBER; i++) {
      double angle = i * 2 * pi / NUMBER;

      SDL_SetRenderDrawColor(rend, 128, 128, 128, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(rend,
          CENTER_X + INNER_RADIUS * sin(angle),
          CENTER_Y + INNER_RADIUS * cos(angle),
          CENTER_X + OUTER_RADIUS * sin(angle),
          CENTER_Y + OUTER_RADIUS * cos(angle));

    }

    return true;
  }
};
