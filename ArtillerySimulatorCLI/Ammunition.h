#pragma once
#include "Acceleration.h"
#include "Angle.h"
#include "Constants.h"
#include "Drag.h"
#include "Position.h"
#include "Velocity.h"
#include <iostream>

class Ammunition {

public:
  void fire(Angle angle) {
    
    velocity.setPointAngle(TRIPLE7_VELOCITY, angle);

    Angle dragAngle(velocity.getPointAngle());
    dragAngle.addRadians(PI);

    acceleration.setPointAngle(drag.getAcceleration(), dragAngle);
    acceleration.addY(-1 * GRAVITY);

    std::cout << "\nProjectile fired at: " << std::endl;
    // angle.display();
    displayAmmunition();
    std::cout << std::endl;
  }

  void advance() {

    // update position based on velocity
    position.addXY(velocity.getX() * TIME, velocity.getY() * TIME);

    // update velocity based on acceleration
    velocity.addXY(acceleration.getX() * TIME, acceleration.getY() * TIME);

    // updated drag based on altitue and velocity
    drag.setAltitudeVelocity(position.getY(), velocity.getTotalPoint());
    // drag.displayDrag();

    // angle drag
    Angle dragAngle(velocity.getPointAngle());
    dragAngle.addRadians(PI);

    // update acceleration based on drag
    acceleration.setPointAngle(drag.getAcceleration(), dragAngle);
    acceleration.addY(-1 * GRAVITY);
  }

  // getter
  Position getPosition() const { return position; }

  // display
  void displayAmmunition() {
    position.display();
    velocity.display();
    acceleration.display();
    drag.display();
  }

private:
  Position position;
  Velocity velocity;
  Acceleration acceleration;
  Drag drag;
};