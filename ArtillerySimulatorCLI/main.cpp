#pragma once
#include "Ammunition.h"
#include "Angle.h"
#include "Drag.h"
#include <iostream>

int main() {

  while (true) {

    double degrees = 180;
    while (degrees < -90 || degrees > 90) {

      std::cout
          << "What is the angle of the howitzer where 0 is up? [-90 to 90] ";
      std::cin >> degrees;

      if (degrees < -90 || degrees > 90)
        std::cout << "Please, try again.\n\n";
    }

    Angle angleFired;
    angleFired.setDegrees(90 - degrees);

    Ammunition triple7(TRIPLE7_AREA, TRIPLE7_WEIGHT);
    triple7.fire(TRIPLE7_VELOCITY, angleFired);

    Drag drag(&triple7);

    double timer = 0;
    double maxHeight = 0;
    int counter = 0;

    do {
      triple7.advance();
      triple7.applyDrag(drag.getAcceleration());

      timer += TIME;
      if (triple7.getPosition().getY() > maxHeight) {
        maxHeight = triple7.getPosition().getY();
      }

      counter++;
      if (counter % 100 == 0) {
        triple7.displayAmmunition();
        drag.displayDrag();
        std::cout << std::endl;
      }
    } while (triple7.getPosition().getY() > 0);

    std::cout << "Distance Traveled: " << triple7.getPosition().getX()
              << std::endl;
    std::cout << "Maximum Height: " << maxHeight << std::endl;
    std::cout << "Total Time: " << timer << std::endl << std::endl;
  }

  return 0;
}