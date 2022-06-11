#pragma once
#include "Angle.h"
#include "compareDouble.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

class Point {
public:
  // constructor at default location
  Point() {
    setX(0);
    setY(0);
  }

  // non-default constructor
  Point(const double x, const double y) {
    setX(x);
    setY(y);
  }

  // copy constructor
  Point(const Point &point) {
    setX(point.getX());
    setY(point.getY());
  }

  // getters
  double getX() const { return x; }
  double getY() const { return y; }
  double getTotalPoint() const { return sqrt(pow(getX(), 2) + pow(getY(), 2)); }

  Angle getPointAngle() const {

    Angle pointAngle;
    pointAngle.setRadians(atan2(getY(), getX()));

    return pointAngle;
  }

  // setters
  void setPoint(const Point point) {
    setX(point.getX());
    setY(point.getY());
  }
  void setXY(const double x, const double y) {
    setX(x);
    setY(y);
  }
  void setX(const double x) {
    if (compareDouble(x, 0))
      this->x = 0;
    else
      this->x = x;
  }
  void setY(const double y) {
    if (compareDouble(y, 0))
      this->y = 0;
    else
      this->y = y;
  }

  // set point at an angle
  void setPointAngle(const double totalPoint, const Angle angle) {
    setX(cos(angle.getRadians()) * totalPoint);
    setY(sin(angle.getRadians()) * totalPoint);
  }

  // addition
  void addPoint(const Point point) {
    setX(point.getX() + getX());
    setY(point.getY() + getY());
  }
  void addXY(const double x, const double y) {
    setX(x + getX());
    setY(y + getY());
  }
  void addX(const double x) { setX(x + getX()); }
  void addY(const double y) { setY(y + getY()); }

  // display
  void display(const char *name) {
    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << name << ": (" << getX() << ", " << getY() << ")\n";
    std::cout.clear();
  }

protected:
  // data members
  double x;
  double y;
};