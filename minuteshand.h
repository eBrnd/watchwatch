#pragma once

#include <chrono>
#include <cmath>

#include "renderobject.h"

template <int CENTER_X, int CENTER_Y, int LENGTH>
class MinutesHand : public RenderObject {
  static constexpr auto pi = std::acos(-1);

  public:
    virtual bool render(SDL_Renderer* rend) {
      std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      std::tm* lt = localtime(&time);
      int minutes = lt->tm_min;

      auto angle = pi + -2 * pi * (minutes / 60.);
      int x = LENGTH * sin(angle);
      int y = LENGTH * cos(angle);

      SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(rend, CENTER_X, CENTER_Y, CENTER_X + x, CENTER_Y + y);
      return true;
    }
};
