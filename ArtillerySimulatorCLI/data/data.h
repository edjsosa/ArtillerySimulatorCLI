#pragma once
#include <fstream>
#include <iostream>
#include <vector>

typedef struct {
  double input;
  double output;
} Data_t;

std::vector<Data_t> readData(const std::string filename) {

  std::vector<Data_t> data;

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

  return data;
}

std::vector<Data_t> coefficientData = readData("data/coefficient.txt");
std::vector<Data_t> densityData = readData("data/density.txt");
std::vector<Data_t> soundData = readData("data/sound.txt");