#include <chrono>
#include <iostream>
#include <sys/time.h>

#include "anglefunctions.h"
#include "graduations.h"
#include "renderlist.h"
#include "simplehand.h"
#include "window.h"

int main(int, char**) {
  try {
    Window<800, 600> w;
    RenderList list;

    std::tm* lt = NULL;
    long usec = 0;

    std::function<double()> secondAngle = [&lt, &usec] () {
      return angleFunctions::secondAngle(lt, usec); };
    std::function<double()> minuteAngle = [&lt] () { return angleFunctions::minuteAngle(lt); };
    std::function<double()> hourAngle = [&lt] () { return angleFunctions::hourAngle(lt); };

    list.add(std::shared_ptr<RenderObject>(new Graduations<400, 300, 240, 250, 60>()));
    list.add(std::shared_ptr<RenderObject>(new Graduations<400, 300, 250, 270, 12>()));
    list.add(std::shared_ptr<RenderObject>(new Graduations<400, 430, 62, 70, 60>()));

    list.add(std::shared_ptr<RenderObject>(new SimpleHand<400, 430, 60>(secondAngle)));
    list.add(std::shared_ptr<RenderObject>(new SimpleHand<400, 300, 230>(minuteAngle)));
    list.add(std::shared_ptr<RenderObject>(
          new SimpleHand<400, 300, (int)(230 / 1.618)>(hourAngle)));

    bool run = true;
    while (run) {
      w.clear();

      auto now = std::chrono::system_clock::now();
      auto time = std::chrono::system_clock::to_time_t(now);
      lt = localtime(&time);
      usec = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count()
        % 1000000;

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
