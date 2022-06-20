#pragma once
#include "AngleTest.h"
#include "PointTest.h"
#include <iostream>

void testDriver() {

  PointTest postTest;
  postTest.testGetters();
  postTest.testSetters();
  postTest.testAddition();

  AngleTest angleTest;
  angleTest.testGetters();
  angleTest.testSetters();
  
}