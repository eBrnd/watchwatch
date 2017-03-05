#pragma once

#include <cmath>

namespace angleFunctions {
static const auto pi = std::acos(-1);

double secondAngle(std::tm* lt) {
  return pi + -2 * pi * (lt->tm_sec / 60.);
}

double minuteAngle(std::tm* lt) {
  return pi + -2 * pi * (lt->tm_min / 60.);
}

double hourAngle(std::tm* lt) {
  return pi + -2 * pi * (lt->tm_hour / 12.);
}

};
