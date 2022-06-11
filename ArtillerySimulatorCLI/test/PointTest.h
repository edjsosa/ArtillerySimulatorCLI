#pragma once
#include "../Point.h"
#include <cassert>

class PointTest : Point {
public:
  void testSetters() {

    for (int i = 0; i < 9; i++) {

      Point nonDefaultPoint(values[i].x, values[i].y);
      Point::setPoint(nonDefaultPoint);
      assert(x == values[i].expectedX && y == values[i].expectedY);

      Point::setXY(values[i].x, values[i].y);
      assert(x == values[i].expectedX && y == values[i].expectedY);

      Point::setX(values[i].x);
      assert(x == values[i].expectedX);

      Point::setY(values[i].y);
      assert(y == values[i].expectedY);
    }

    for (int i = 0; i < 5; i++) {
      Angle angle;
      angle.setDegrees(angleValues[i].angle);

      Point::setPointAngle(angleValues[i].totalPoint, angle);

      assert(compareDouble(x, angleValues[i].expectedX) &&
             compareDouble(y, angleValues[i].expectedY));
    }
  }

  void testGetters() {

    for (int i = 0; i < 9; i++) {
      Point::setXY(values[i].x, values[i].y);
      assert(Point::getX() == values[i].expectedX);
      assert(Point::getY() == values[i].expectedY);
    }

    for (int i = 0; i < 5; i++) {
      
      Angle angle;
      angle.setDegrees(angleValues[i].angle);

      Point::setPointAngle(angleValues[i].totalPoint, angle);

      assert(compareDouble(Point::getTotalPoint(),
                           angleValues[i].totalPoint));
    }
  }

  void testAddition() {

    for (int i = 0; i < 5; i++) {
      Point::setXY(addValues[i].x, addValues[i].y);
      Point::addXY(addValues[i].addX, addValues[i].addY);
      assert(x == addValues[i].expectedX && y == addValues[i].expectedY);
    }

    for (int i = 0; i < 5; i++) {
      Point::setX(addValues[i].x);
      Point::addX(addValues[i].addX);
      assert(x == addValues[i].expectedX);
    }

    for (int i = 0; i < 5; i++) {
      Point::setY(addValues[i].y);
      Point::addY(addValues[i].addY);
      assert(y == addValues[i].expectedY);
    }

    for (int i = 0; i < 5; i++) {
      Point::setXY(addValues[i].x, addValues[i].y);

      Point nonDefaultPoint(addValues[i].addX, addValues[i].addY);
      Point::addPoint(nonDefaultPoint);

      Point::setXY(addValues[i].x, addValues[i].y);
      Point::addXY(addValues[i].addX, addValues[i].addY);
      assert(x == addValues[i].expectedX && y == addValues[i].expectedY);
    }
  }

  void testPoint() {

    // default constructor
    Point defaultPoint;
    defaultPoint.display("Point");

    // non-default constructor
    Point nonDefaultPoint(100, 50);
    nonDefaultPoint.display("Point");

    // copy constructor
    Point copyPoint(nonDefaultPoint);
    copyPoint.display("Point");

    // setters
    defaultPoint.setPoint(nonDefaultPoint);
    defaultPoint.display("Point");

    defaultPoint.setXY(25, 25);
    defaultPoint.display("Point");

    defaultPoint.setX(51);
    defaultPoint.display("Point");

    defaultPoint.setY(52);
    defaultPoint.display("Point");

    Angle angle;
    angle.setDegrees(30);
    defaultPoint.setXY(100, 100);
    defaultPoint.setPointAngle(defaultPoint.getTotalPoint(), angle);
    defaultPoint.display("Point");

    // getters
    std::cout << "defaultPoint.getX(): " << defaultPoint.getX()
              << std::endl;
    std::cout << "defaultPoint.getY(): " << defaultPoint.getY()
              << std::endl;
    std::cout << "defaultPoint.getTotalPoint(): "
              << defaultPoint.getTotalPoint() << std::endl;

    // addition
    defaultPoint.setXY(25, 25);
    defaultPoint.addPoint(nonDefaultPoint);
    defaultPoint.display("Point");

    defaultPoint.addXY(10, 10);
    defaultPoint.display("Point");

    defaultPoint.addX(10);
    defaultPoint.display("Point");

    defaultPoint.addY(10);
    defaultPoint.display("Point");
  }

private:
  struct {
    double x;
    double y;
    double expectedX;
    double expectedY;
  } values[9] = {{99999999, 99999999, 99999999, 99999999},
                 {1000, 1000, 1000, 1000},
                 {6, 6, 6, 6},
                 {1, 1, 1, 1},
                 {0, 0, 0, 0},
                 {-1, -1, -1, -1},
                 {-6, -6, -6, -6},
                 {-1000, -1000, -1000, -1000},
                 {-99999999, -99999999, -99999999, -99999999}};

  struct {
    double totalPoint;
    double angle;
    double expectedX;
    double expectedY;
  } angleValues[5] = {{1000.0, 0.0, 1000, 0},
                      {1000.0, 90.0, 0, 1000},
                      {1000.0, 180.0, -1000, 0},
                      {1000.0, 270.0, 0, -1000},
                      {1000.0, 360.0, 1000, 0}};

  struct {
    double x;
    double y;
    double addX;
    double addY;
    double expectedX;
    double expectedY;
  } addValues[5] = {
      {1, 2, 3, 4, 4, 6},
      {10, 20, 30, 40, 40, 60},
      {1000, 2000, 3000, 4000, 4000, 6000},
      {1000000, 2000000, 3000000, 4000000, 4000000, 6000000},
      {1000000000, 2000000000, 3000000000, 4000000000, 4000000000, 6000000000}};
};
