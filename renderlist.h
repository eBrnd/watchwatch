#pragma once

#include <memory>
#include <vector>

#include "renderobject.h"

class RenderList : public RenderObject {
  public:

    void add(std::shared_ptr<RenderObject>&& obj) {
      objs.push_back(obj);
    }

    virtual bool render(SDL_Renderer* rend) {
      for (auto& o : objs) {
        if (!o->render(rend))
          return false;
      }
      return true;
    }
  private:
    std::vector<std::shared_ptr<RenderObject>> objs;
};
