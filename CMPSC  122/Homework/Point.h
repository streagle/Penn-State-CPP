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