#pragma once
#include "Point.h"
#include <iomanip>
#include <iostream>

class Acceleration : public Point {
public:
  // display
  void display() { Point::display("Acceleration"); }
};