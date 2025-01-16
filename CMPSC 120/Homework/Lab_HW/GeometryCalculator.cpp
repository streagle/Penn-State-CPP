#include <iostream>
#include <iomanip>


using namespace std;
//Methods



int main() {
    // Variables
    int choice;
    double area, radius, length, width, base, height;

    // Inputs
    cout << "Geometry Calculator" << endl;
    cout << "   1. Calculate the Area of a Circle" << endl;
    cout << "   2. Calculate the Area of a Rectangle" << endl;
    cout << "   3. Calculate the Area of a Triangle" << endl;
    cout << "   4. Quit" << endl;
    cout << "   Enter your choice (1-4): ";
    cin >> choice;

    // Processes
    switch (choice) {
        case 1:
            cout << "Enter the radius of the circle (m): ";
            cin >> radius;
            if (radius < 0) {
                cout << "Radius cannot be negative." << endl;
            } else {
                area = M_PI * radius * radius;
                cout << fixed << setprecision(2);
                cout << "The area of the circle is " << area <<" m^2"<< endl;
            }
            break;
        case 2:
            cout << "Enter the length of the rectangle (m): ";
            cin >> length;
            cout << "Enter the width of the rectangle (m): ";
            cin >> width;
            if (length < 0 || width < 0) {
                cout << "Length and width cannot be negative." << endl;
            } else {
                area = length * width;
                cout << fixed << setprecision(2);
                cout << "The area of the rectangle is " << area <<" m^2"<< endl;
            }
            break;
        case 3:
            cout << "Enter the base  of the triangle (m): ";
            cin >> base;
            cout << "Enter the height of the triangle (m): ";
            cin >> height;
            if (base < 0 || height < 0) {
                cout << "Base and height cannot be negative." << endl;
            } else {
                area = 0.5 * base * height;
                cout << fixed << setprecision(2);
                cout << "The area of the triangle is " << area <<" m^2"<< endl;
            }
            break;
        case 4:
            cout << "Quitting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            break;
    }

    // Outputs
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                 Test Case 1                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"GeometryCalculator"
Geometry Calculator
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 5
Invalid choice. Please enter a number between 1 and 4.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 Test Case 2                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"GeometryCalculator"
Geometry Calculator
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 4
Quitting the program.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 Test Case 3                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"GeometryCalculator"
Geometry Calculator
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 1
Enter the radius of the circle (m): -1
Radius cannot be negative.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 Test Case 4                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"GeometryCalculator"
Geometry Calculator
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 2
Enter the length of the rectangle (m): 4
Enter the width of the rectangle (m): -1
Length and width cannot be negative.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 Test Case 5                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"GeometryCalculator"
Geometry Calculator
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 1
Enter the radius of the circle (m): 6.2
The area of the circle is 120.76 m^2
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 Test Case 6                                */
/* -------------------------------------------------------------------------- */


/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"GeometryCalculator"
Geometry Calculator
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 3
Enter the base  of the triangle (m): 5.5
Enter the height of the triangle (m): 9
The area of the triangle is 24.75 m^2
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/