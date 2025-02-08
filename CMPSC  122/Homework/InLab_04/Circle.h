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
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.cpp"//Wont work with .h so i used .cpp

class Circle {
public:
Circle(Point cp, double r); // center point and radius
Circle(double x, double y, double r); // another constructor
double getArea(); // return the area of the circle
void moveCircle(double dx, double dy);
// space for adding new member functions
bool isItOrigin() const;
double getRadius() const;
Point getCenter() const;
void display() const;
    
private:
Point center;
double radius;
};

#endif