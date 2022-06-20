#pragma once
#include "Ammunition.h"
#include "Point.h"
#include "data/data.h"
#include <iostream>

class Drag {

public:
  Drag(Ammunition *ammunition) {
    setAmmunition(ammunition);
    update();
  }

  // getters
  double getDrag() { 
    update();
    return drag; 
    }

  Point getAcceleration() {

    double mass = pAmmo->getMass();
    
    if (mass > 0) {

      double dragAcceleration = getDrag() / mass;

      Angle dragAngle(pAmmo->getVelocity().getPointAngle());
      dragAngle.addRadians(PI);

      Point acceleration;
      acceleration.setPointAngle(dragAcceleration, dragAngle);
      return acceleration;
    }

    Point point;
    return point;
  }

  // display
  void displayDrag() {
    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << "Drag Force: " << drag << std::endl;
    getAcceleration().displayPoint("Drag Acceleration");
    std::cout << std::endl;

    std::cout.clear();
  }

private:
  double drag;
  Ammunition *pAmmo;

  void setAmmunition(Ammunition *ammunition) { pAmmo = ammunition; }

  void computeDrag(const double coefficient, const double density) {

    double velocity = pAmmo->getVelocity().getTotalPoint();
    double area = pAmmo->getArea();

    drag = 0.5 * area * coefficient * density * velocity * velocity;
  }

  double interpolation(const double x, const double x1, const double y1,
                       const double x2, const double y2) const {
    return y1 + (x - x1) * (y2 - y1) / (x2 - x1);
  }

  double computeDensity(const double altitude) const {

      double density = densityData.back().output;

    for (int i = 0; i < densityData.size() - 1; i++) {

      if (altitude == densityData[i].input) {
        density = densityData[i].output;
        break;
      }

      else if (altitude > densityData[i].input &&
               altitude < densityData[i + 1].input) {

        density =
            interpolation(altitude, densityData[i].input, densityData[i].output,
                          densityData[i + 1].input, densityData[i + 1].output);
        // std::cout << "density: " << density << std::endl;
        break;
      }
    }
    return density;
  }

  double computeSpeedOfSound(const double altitude) const {

    double speedOfSound = soundData.back().output;

    for (int j = 0; j < soundData.size() - 1; j++) {
      if (altitude == soundData[j].input) {
        speedOfSound = soundData[j].output;
        break;
      } else if (altitude > soundData[j].input &&
                 altitude < soundData[j + 1].input) {

        speedOfSound =
            interpolation(altitude, soundData[j].input, soundData[j].output,
                          soundData[j + 1].input, soundData[j + 1].output);
        // std::cout << "speedOfSound: " << speedOfSound << std::endl;
        break;
      }
    }
    return speedOfSound;
  }

  double computeCoefficient(const double velocity,
                            const double speedOfSound) const {

    double mach = velocity / speedOfSound;

    double coefficient = coefficientData.back().output;

    for (int k = 0; k < coefficientData.size() - 1; k++) {
      if (mach == coefficientData[k].input) {
        coefficient = coefficientData[k].output;
        break;
      } else if (mach > coefficientData[k].input &&
                 mach < coefficientData[k + 1].input) {

        coefficient = interpolation(
            mach, coefficientData[k].input, coefficientData[k].output,
            coefficientData[k + 1].input, coefficientData[k + 1].output);
        // std::cout << "coefficient: " << coefficient << std::endl;
        break;
      }
    }

    return coefficient;
  }

  void update() {

    double altitude = pAmmo->getPosition().getY();
    double velocity = pAmmo->getVelocity().getTotalPoint();

    double density = computeDensity(altitude);
    double speedOfSound = computeSpeedOfSound(altitude);
    double coefficient = computeCoefficient(velocity, speedOfSound);

    computeDrag(coefficient, density);
  }
};