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
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>


class Point {
public:
    Point(); // Default constructor
    Point(double x, double y); // Constructor with parameters

    double x() const; // Getter for x
    double y() const; // Getter for y

    double magnitude() const; // Returns the polar coordinate r
    void move(double dx, double dy); // Moves the point
    void print() const; // Prints the point

private:
    double _x, _y;
};

#endif