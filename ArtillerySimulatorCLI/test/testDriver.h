#pragma once
#include "AngleTest.h"
#include "PointTest.h"
#include <iostream>

void testDriver() {

  AngleTest angleTest;
  angleTest.testGetters();
  angleTest.testSetters();

  PointTest pointTest;
  pointTest.testGetters();
  pointTest.testSetters();
  pointTest.testAddition();
}