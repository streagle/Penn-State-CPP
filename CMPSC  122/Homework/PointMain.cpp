#include <iostream>
#include <cmath>
using namespace std;
#include "Point.h" // defines Point class
int main()
{
Point p0; // invokes default constructor
Point p1(5, -2); // invokes constructor
Point p2 = p1;
p0 = p1; // invokes assignment operator
cout << "p0.x() = " << p0.x() << "\n";
cout << "p0.y() = " << p0.y() << "\n";
}