#pragma once
#include <cmath>

bool compareDouble(const double x, const double y) {

  const double PRECISION = 0.001;

  if (fabs(x - y) < PRECISION)
    return true; // they are same
  return false;  // they are not same
}