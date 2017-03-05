#include <iostream>
#include <chrono>
#include <cmath>

#include "simplehand.h"
#include "window.h"
#include "renderlist.h"

static const auto pi = std::acos(-1);

int main(int, char**) {
  try {
    Window<800, 600> w;
    RenderList list;

    std::tm* lt = NULL;

    std::function<double()> secondAngle = [&lt] () { return pi + -2 * pi * (lt->tm_sec / 60.); };
    std::function<double()> minuteAngle = [&lt] () { return pi + -2 * pi * (lt->tm_min / 60.); };
    std::function<double()> hourAngle = [&lt] () { return pi + -2 * pi * (lt->tm_hour / 12.); };

    list.add(std::shared_ptr<RenderObject>(new SimpleHand<400, 300, 250>(secondAngle)));
    list.add(std::shared_ptr<RenderObject>(new SimpleHand<400, 300, 230>(minuteAngle)));
    list.add(std::shared_ptr<RenderObject>(
          new SimpleHand<400, 300, (int)(230 / 1.618)>(hourAngle)));

    bool run = true;
    while (run) {
      w.clear();

      std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      lt = localtime(&time);

      run = list.render(w.getRenderer());

      if (run) {
        SDL_Event event;
        while (SDL_PollEvent(&event))
          if (event.type == SDL_QUIT)
            run = false;
      }

      w.present();
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
