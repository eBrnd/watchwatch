#include <iostream>
#include <chrono>

#include "anglefunctions.h"
#include "simplehand.h"
#include "window.h"
#include "renderlist.h"

int main(int, char**) {
  try {
    Window<800, 600> w;
    RenderList list;

    std::tm* lt = NULL;

    std::function<double()> secondAngle = [&lt] () { return angleFunctions::secondAngle(lt); };
    std::function<double()> minuteAngle = [&lt] () { return angleFunctions::minuteAngle(lt); };
    std::function<double()> hourAngle = [&lt] () { return angleFunctions::hourAngle(lt); };

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
