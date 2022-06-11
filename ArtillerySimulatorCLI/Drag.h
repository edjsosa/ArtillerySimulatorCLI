#pragma once
#include "Constants.h"
#include <fstream> // The fstream library is required to read to a file.
#include <iostream>
#include <string> // Use the string library to declare a std::string object.
#include <vector>

/*
d = 0. 5* a * c * p * v^2
a = surface area
d = force in newtons (N)
c = drag coefficient
p = density of the fluid/gas
v = velocity of the projectile
*/

class Drag {
private:
  std::string COEFFICIENT_DATA = "data/coefficient.txt";
  std::string DENSITY_DATA = "data/density.txt";
  std::string SOUND_DATA = "data/sound.txt";

public:
  // default constructor
  Drag() {

    readData(COEFFICIENT_DATA, coefficientData);
    readData(DENSITY_DATA, densityData);
    readData(SOUND_DATA, soundData);

    area = TRIPLE7_AREA;
    mass = TRIPLE7_WEIGHT;

    setAltitudeVelocity(0, TRIPLE7_VELOCITY);
  }

  void setAltitudeVelocity(const double altitude, const double velocity) {

    this->altitude = altitude;
    this->velocity = velocity;

    /* Works on replit, but not on Visual Studio.
    density = densityData.end()->output;
    */

    for (int i = 0; i < densityData.size() - 1; i++) {

      if (this->altitude == densityData[i].input) {
        density = densityData[i].output;
        break;
      }

      else if (this->altitude > densityData[i].input &&
               this->altitude < densityData[i + 1].input) {

        density = interpolation(this->altitude, densityData[i].input,
                                densityData[i].output, densityData[i + 1].input,
                                densityData[i + 1].output);
        // std::cout << "density: " << density << std::endl;
        break;
      }
    }

    /* Works on replit, but not on Visual Studio.
    speedOfSound = soundData.end()->output;
    */

    for (int j = 0; j < soundData.size() - 1; j++) {
      if (this->altitude == soundData[j].input) {
        speedOfSound = soundData[j].output;
        break;
      } else if (this->altitude > soundData[j].input &&
                 this->altitude < soundData[j + 1].input) {

        speedOfSound = interpolation(
            this->altitude, soundData[j].input, soundData[j].output,
            soundData[j + 1].input, soundData[j + 1].output);
        // std::cout << "speedOfSound: " << speedOfSound << std::endl;
        break;
      }
    }

    double mach = velocity / speedOfSound;

    /* Works on replit, but not on Visual Studio.
    coefficient = coefficientData.end()->output;
    */

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

    computeDrag();
  }

  // getters
  double getDrag() const { return drag; }

  double getAcceleration() const {
    if (mass > 0)
      return drag / mass;
    return 0;
  }

  // display
  void display() {
    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << "Drag Force: " << drag
              << ", Drag Acceleration: " << getAcceleration() << std::endl;

    // std::cout << "Altitude: " << altitude;
    // std::cout << "\tCoefficient: " << coefficient;
    // std::cout << "\tDensity: " << density;
    // std::cout << "\tSpeed of Sound: " << speedOfSound;
    // std::cout << "\tVelocity: " << velocity << std::endl;

    std::cout.clear();
  }

private:
  typedef struct {
    double input;
    double output;
  } Data_t;

  std::vector<Data_t> coefficientData, densityData, soundData;
  double altitude, area, coefficient, density, drag, mass, speedOfSound,
      velocity;

  void computeDrag() {
    drag = 0.5 * area * coefficient * density * velocity * velocity;
  }

  double interpolation(double x, double x1, double y1, double x2, double y2) {
    return y1 + (x - x1) * (y2 - y1) / (x2 - x1);
  }

  void readData(const std::string filename, std::vector<Data_t> &data) {

    // Declare an input file stream object.
    std::ifstream file;

    // Open the input file.
    file.open(filename);

    Data_t reading;

    // Check for errors.
    if (!file.fail()) {

      // Read the data from the input file.
      while (file >> reading.input >> reading.output)
        data.push_back(reading);

    } else
      std::cout << "Unable to open " << filename << std::endl;

    // Close the input file stream object.
    file.close();
  }
};