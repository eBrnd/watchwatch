#include <iostream>

#include "hand.h"
#include "window.h"
#include "renderlist.h"

int main(int, char**) {
  try {
    Window<800, 600> w;
    RenderList list;

    list.add(std::shared_ptr<RenderObject>(new Hand<400, 300, 250>()));

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
