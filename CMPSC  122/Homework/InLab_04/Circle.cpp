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
#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle(Point cp, double r) : center(cp), radius(r) {} // Constructor with Point

Circle::Circle(double x, double y, double r) : center(x, y), radius(r) {} // Constructor with coordinates

double Circle::getArea() {
    return M_PI * radius * radius; // Area = πr²
}

void Circle::moveCircle(double dx, double dy) {
    center.move(dx, dy);
}

bool Circle::isItOrigin() const {
    return center.x() == 0 && center.y() == 0;
}

double Circle::getRadius() const {
    return radius;
}

Point Circle::getCenter() const {
    return center;
}

void Circle::display() const {
    cout << "[(" << center.x() << ", " << center.y() << "), " << radius << "]" << endl;
}