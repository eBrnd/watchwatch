#pragma once

#include <cmath>

namespace angleFunctions {
static const auto pi = std::acos(-1);

double secondAngle(std::tm* lt, long usec) {
  double secondAngle = pi + -2 * pi * (lt->tm_sec / 60.);
  double subsecondAngle = (-2 * pi / 60.) * (usec / 1000000.);

  return secondAngle + subsecondAngle;
}

double minuteAngle(std::tm* lt) {
  double min = lt->tm_min + (lt->tm_sec / 60.);
  return pi + -2 * pi * (min / 60.);
}

double hourAngle(std::tm* lt) {
  double hour = lt->tm_hour + (lt->tm_min / 60) + (lt->tm_sec / 3600);
  return pi + -2 * pi * (hour / 12.);
}

};
