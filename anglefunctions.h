#pragma once

#include <cmath>

namespace angleFunctions {
double secondAngle(std::tm* lt, long usec) {
  double secondAngle = M_PI + -2 * M_PI * (lt->tm_sec / 60.);

  double usec_sixths = floor(6 * usec / 1000000.) / 6;
  double subsecondAngle = (-2 * M_PI / 60.) * (usec_sixths);

  return secondAngle + subsecondAngle;
}

double minuteAngle(std::tm* lt) {
  double min = lt->tm_min + (lt->tm_sec / 60.);
  return M_PI + -2 * M_PI * (min / 60.);
}

double hourAngle(std::tm* lt) {
  double hour = lt->tm_hour + (lt->tm_min / 60) + (lt->tm_sec / 3600);
  return M_PI + -2 * M_PI * (hour / 12.);
}

};
