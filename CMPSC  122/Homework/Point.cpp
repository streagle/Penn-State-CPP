#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point() : _x(0), _y(0) {} // Default constructor initializes to (0,0)

Point::Point(double x, double y) : _x(x), _y(y) {} // Constructor with parameters

double Point::x() const { return _x; } // Get x coordinate
double Point::y() const { return _y; } // Get y coordinate

double Point::magnitude() const {
    return sqrt(_x * _x + _y * _y); // Compute polar coordinate r = √(x² + y²)
}

void Point::move(double dx, double dy) {
    _x += dx;
    _y += dy;
}

void Point::print() const {
    cout << "(" << _x << ", " << _y << ")";
}