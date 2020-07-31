#ifndef FPS_TEMPLATE_MATHHELPER_H
#define FPS_TEMPLATE_MATHHELPER_H

#include "structs.h"
#include <cmath>
#include <vector>

// This file contains general math helper functions

const double PI = 3.14159265358979323846;


// Assuming n > 0, this returns the integer closest to n that
// is a perfect square
int nearestPerfectSquare(int n);

// Returns the square root of n, assuming that n is a perfect square
int isqrt(int n);

// Convert between chunkID's and Point2D's
Point2D chunkIDtoPoint2D(int n);
int point2DtoChunkID(Point2D p);

// Returns the distance in the xz plane
double distance2d(Point p1, Point p2);

double distanceFormula(double x1, double y1, double x2, double y2);

// Euclidean distance
double distance(Point2D p1, Point2D p2);

double distance3d(Point p1, Point p2);


// Returns the ints corresponding to to all chunks that are within radius of this one,
// using the taxicab metric
std::vector<int> getChunkIDsAroundPoint(Point2D p, int radius);
std::vector<Point2D> getChunkTopLeftCornersAroundPoint(Point2D p, int radius);
#endif //FPS_TEMPLATE_MATHHELPER_H