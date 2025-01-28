#include <iostream>
#include <iomanip>
#include "Triangle.cpp"

using namespace std;
// Methods

int main()
{
    // Variables
    double base;
    double height;
    double area;
    Triangle t;

    // Inputs

    do
    {
        cout << "Enter the height of the triangle: ";
        cin >> height;
        if (height <= 0)
        {
            cout << "Height must be greater than 0." << endl;
        }
    } while (!t.setHeight(height));
    
    do
    {
        cout << "Enter the base of the triangle: ";
        cin >> base;
        if (base <= 0)
        {
            cout << "Base must be greater than 0." << endl;
        }
    } while (!t.setBase(base));

    // Processes
    t.setBase(base);
    t.setHeight(height);
    area = t.getArea();

    // Outputs
    cout << fixed << setprecision(2);
    cout << "The area of the triangle is: " << area << " m^2" << endl;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*

ryanreagle@Ryans-MacBook-Pro-2 output % ./"main"
Enter the height of the triangle: -2
Height must be greater than 0.
Enter the height of the triangle: 2.57
Enter the base of the triangle: 0
Base must be greater than 0.
Enter the base of the triangle: 4.88
The area of the triangle is: 6.27 m^2
ryanreagle@Ryans-MacBook-Pro-2 output % 

*/