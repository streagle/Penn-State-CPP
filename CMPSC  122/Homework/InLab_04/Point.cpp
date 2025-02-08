// Academic Integrity Affidavit:
// I certify that this program code is my work. Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Ryan Reagle>
// Section: <003L>
// Assignment: InLab 04
//
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