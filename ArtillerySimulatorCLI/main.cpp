#pragma once
#include "Ammunition.h"
#include "Angle.h"
#include "test/testDriver.h"
#include <iostream>

int main() {

  // testDriver();

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

    Ammunition triple7;
    triple7.fire(angleFired);

    double timer = 0;
    double maxHeight = 0;
    int counter = 0;

    do {

      triple7.advance();
      timer += TIME;

      // maximum height
      if (triple7.getPosition().getY() > maxHeight) {
        maxHeight = triple7.getPosition().getY();
      }

      // display ammunition at 1 sec interval
      counter++;
      if (counter % 100 == 0) {
        std::cout << "Time: " << timer << std::endl;
        triple7.displayAmmunition();
        std::cout << std::endl;
      }

    } while (triple7.getPosition().getY() > 0);

    std::cout << "Final Distance: " << triple7.getPosition().getX()
              << std::endl;
    std::cout << "Maximum Height: " << maxHeight << std::endl;
    std::cout << "Total Time: " << timer << std::endl << std::endl;
  }

  return 0;
}