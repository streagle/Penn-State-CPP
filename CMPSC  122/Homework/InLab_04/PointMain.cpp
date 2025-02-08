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
#include <iostream>
using namespace std;
#include "Point.cpp" // wont work with .h file so i used .cpp file
int main()
{
    Point p0;        // invokes default constructor
    Point p1(5, -2); // invokes constructor
    Point p2 = p1;
    p0 = p1; // invokes assignment operator
    cout << "p2.x() = " << p2.x() << "\n";
    cout << "p2.y() = " << p2.y() << "\n";
    cout << "p0.x() = " << p0.x() << "\n";
    cout << "p0.y() = " << p0.y() << "\n";
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"PointMain"
p2.x() = 5
p2.y() = -2
p0.x() = 5
p0.y() = -2
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/