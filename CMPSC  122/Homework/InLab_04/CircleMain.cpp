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
#include "Circle.cpp"// wont work with .h file so i used .cpp file


using namespace std;

int main() {
    Circle c1(2.5, 3.0, 5.0);
    cout << "Initial Circle: ";
    c1.display();

    cout << "Area: " << c1.getArea() << endl;

    c1.moveCircle(-2.5, -3.0);
    cout << "After moving: ";
    c1.display();

    cout << "Is circle at origin? " << (c1.isItOrigin() ? "Yes" : "No") << endl;

    cout << "Radius: " << c1.getRadius() << endl;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"CircleMain"
Initial Circle: [(2.5, 3), 5]
Area: 78.5398
After moving: [(0, 0), 5]
Is circle at origin? Yes
Radius: 5
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/