#pragma once
#include "Constants.h"
#include "compareDouble.h"
#include <iostream>

class Angle {

public:
  // default constructor
  Angle() { setRadians(0); }

  // non-default constructor
  Angle(const double radians) { setRadians(radians); }

  // copy constructor
  Angle(const Angle &angle) { setRadians(angle.getRadians()); }

  // getters
  double getDegrees() const { return radians * 180 / PI; }
  double getRadians() const { return radians; }

  // setters
  void setDegrees(const double degrees) { setRadians(degrees * PI / 180); }
  void setRadians(const double radians) {

    if (compareDouble(radians, 0))
      this->radians = 0;
    else if (compareDouble(radians, PI / 6))
      this->radians = (PI / 6);
    else if (compareDouble(radians, PI / 4))
      this->radians = (PI / 4);
    else if (compareDouble(radians, PI / 3))
      this->radians = (PI / 3);
    else if (compareDouble(radians, PI / 2))
      this->radians = (PI / 2);
    else
      this->radians = radians;
  }

  // addition
  void addRadians(const double radians) { setRadians(getRadians() + radians); }

  // display
  void display() {
    std::cout << "Degrees: " << getDegrees()
              << "deg, Radians: " << getRadians() << "rad\n";
  }

protected:
  double radians;
};