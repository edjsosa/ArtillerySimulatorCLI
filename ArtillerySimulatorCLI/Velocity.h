#pragma once
#include "Point.h"
#include <iomanip>
#include <iostream>

class Velocity : public Point {
public:
  // display
  void display() { Point::display("Velocity"); }
};