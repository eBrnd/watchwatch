#include <iostream>
#include <chrono>
#include <sys/time.h>

#include "anglefunctions.h"
#include "simplehand.h"
#include "window.h"
#include "renderlist.h"

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

    list.add(std::shared_ptr<RenderObject>(new SimpleHand<400, 430, 60>(secondAngle)));
    list.add(std::shared_ptr<RenderObject>(new SimpleHand<400, 300, 230>(minuteAngle)));
    list.add(std::shared_ptr<RenderObject>(
          new SimpleHand<400, 300, (int)(230 / 1.618)>(hourAngle)));

    bool run = true;
    while (run) {
      w.clear();

      struct timeval time;
      gettimeofday(&time, NULL);
      lt = localtime(&time.tv_sec);
      usec = time.tv_usec;

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
