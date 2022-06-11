#pragma once
#include "Point.h"
#include <iomanip>
#include <iostream>

class Position : public Point {
public:
  // display
  void display() { Point::display("Position"); }
};