#pragma once

#include <chrono>
#include <cmath>

#include "renderobject.h"

static const auto pi = std::acos(-1);

template <int CENTER_X, int CENTER_Y, int LENGTH>
class Hand : public RenderObject {
  public:
    virtual bool render(SDL_Renderer* rend) {
      std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      std::tm* lt = localtime(&time);
      int seconds = lt->tm_sec;

      auto angle = pi + -2 * pi * (seconds / 60.);
      int x = LENGTH * sin(angle);
      int y = LENGTH * cos(angle);

      SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(rend, CENTER_X, CENTER_Y, CENTER_X + x, CENTER_Y + y);
      return true;
    }
};
