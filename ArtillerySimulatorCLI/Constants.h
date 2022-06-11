// Constants.h
#if !defined(CONSTANTS_H)
#define CONSTANTS_H

const double TIME = 0.01; // seconds
const double PI = 3.14159265359;

const double AIR_DENSITY_SEA = 1.225; // kilogram / meter^3
const double SPEED_SOUND_SEA = 340;   // meters / second

const double GRAVITY = 9.80665; // meters / second^2

const double TRIPLE7_WEIGHT = 46.7;                 // kilograms
const double TRIPLE7_DEGREES = 30;                  // degrees
const double TRIPLE7_DIAMETER = 0.15489;            // meters
const double TRIPLE7_RADIUS = TRIPLE7_DIAMETER / 2; // meters
const double TRIPLE7_VELOCITY = 827;                // meters / second
const double TRIPLE7_AREA = PI * TRIPLE7_RADIUS * TRIPLE7_RADIUS; // meters^2
const double TRIPLE7_MACH = TRIPLE7_VELOCITY / SPEED_SOUND_SEA;
const double TRIPLE7_DRAG_COE = 0.25953;
const double TRIPLE7_DRAG_FORCE = 2048.6292; // kilograms meters / second^2
const double TRIPLE7_DRAG_ACCEL = 43.867;    // meters / second^2

#endif