#pragma once
#include "Angle.h"
#include "Constants.h"
#include "Point.h"
#include <iostream>

class Ammunition {

public:
  Ammunition(const double area, const double mass) {
    this->area = area;
    this->mass = mass;

    resetAcceleration();
  }

  void fire(const double speed, const Angle angle) {

    std::cout << "\nProjectile fired at: " << std::endl;
    angle.display();

    velocity.setPointAngle(speed, angle);

    displayAmmunition();
    std::cout << std::endl;
  }

  void advance() {

    // update position based on velocity
    position.addXY(velocity.getX() * TIME, velocity.getY() * TIME);

    // update velocity based on acceleration
    velocity.addXY(acceleration.getX() * TIME, acceleration.getY() * TIME);
  }

  void applyDrag(Point dragAcceleration) {
    resetAcceleration();
    acceleration.addPoint(dragAcceleration);
  }

  // getter
  Point getPosition() const { return position; }
  Point getVelocity() const { return velocity; }
  Point getAcceleration() const { return acceleration; }

  double getArea() const { return area; }
  double getMass() const { return mass; }

  // display
  void displayAmmunition() const {
    position.displayPoint("Position");
    velocity.displayPoint("Velocity");
    acceleration.displayPoint("Acceleration");
  }

private:
  Point position;
  Point velocity;
  Point acceleration;

  double area;
  double mass;

  void resetAcceleration() { acceleration.setXY(0, -1 * GRAVITY); }
};