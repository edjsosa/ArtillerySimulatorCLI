#pragma once
#include "../Angle.h"
#include "../compareDouble.h"
#include <cassert>

class AngleTest : Angle {
public:
  void testSetters() {

    for (int i = 0; i < 5; i++) {
      Angle::setDegrees(values[i].degrees);
      assert(compareDouble(radians, values[i].expectedRadians));

      Angle::setRadians(values[i].radians);
      assert(compareDouble(radians, values[i].expectedRadians));
    }
  }
  void testGetters() {

    for (int i = 0; i < 5; i++) {
      Angle::setDegrees(values[i].degrees);

      Angle::setRadians(values[i].radians);
      assert(compareDouble(Angle::getDegrees(), values[i].degrees));

      Angle::setRadians(values[i].radians);
      assert(compareDouble(Angle::getRadians(), values[i].expectedRadians));
    }
  }

  void testAngle() {

    // default constructor
    Angle defaultAngle;
    defaultAngle.display();

    // non-default constructor
    Angle NonDefaultAngle(PI);
    NonDefaultAngle.display();

    // copy constructor
    Angle copyAngle(NonDefaultAngle);
    copyAngle.display();

    // setters
    defaultAngle.setDegrees(30);
    defaultAngle.display();

    defaultAngle.setRadians(2 * PI);
    defaultAngle.display();

    // getters
    std::cout << "defaultAngle.getDegrees(): " << defaultAngle.getDegrees()
              << std::endl;
    std::cout << "defaultAngle.getRadians(): " << defaultAngle.getRadians()
              << std::endl;
  }

private:
  struct {
    double degrees;
    double radians;
    double expectedRadians;
  } values[5] = {{0, 0, 0},
                 {90, PI / 2, PI / 2},
                 {180, PI, PI},
                 {270, 3 * PI / 2, 3 * PI / 2},
                 {360, 2 * PI, 2 * PI}};
};
