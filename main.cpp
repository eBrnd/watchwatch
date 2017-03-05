#include <iostream>
#include "window.h"

int main(int, char**) {
  try {
    Window<800, 600> w;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
