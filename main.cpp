#include <iostream>

#include "secondshand.h"
#include "minuteshand.h"
#include "window.h"
#include "renderlist.h"

int main(int, char**) {
  try {
    Window<800, 600> w;
    RenderList list;

    list.add(std::shared_ptr<RenderObject>(new SecondsHand<400, 300, 250>()));
    list.add(std::shared_ptr<RenderObject>(new MinutesHand<400, 300, 230>()));

    bool run = true;
    while (run) {
      w.clear();
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
