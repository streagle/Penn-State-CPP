#include <iostream>
#include <iomanip>

using namespace std;
// Methods

struct rectangle
{
    double length;
    double width;
};

void rectangleValues(rectangle &r1)
{
    do
    {
        cout << "Enter the length of the rectangle: ";
        cin >> r1.length;
        if (r1.length <= 0)
        {
            cout << "Please Enter a length greater than 0!" << endl;
        }
    } while (r1.length <= 0);
    do
    {
        cout << "Enter the width of the rectangle: ";
        cin >> r1.width;
        if (r1.width <= 0)
        {
            cout << "Please Enter a width greater than 0!" << endl;
        }
    } while (r1.width <= 0);
}

double area(const rectangle &r1)
{
    return r1.length * r1.width;
}

void doubleDimensions(rectangle &r1)
{
    r1.length *= 2;
    r1.width *= 2;
}

int main()
{
    // Variables
    rectangle r1;
    double area1;

    // Inputs

    // Processes
    rectangleValues(r1);

    // Outputs
    do
    {
        area1 = area(r1);
        if (area1 > 500)
        {
            cout << "DONE";
            
        }
        else{
        cout << fixed << setprecision(2) << r1.length << " x " << r1.width << " = " << area1 << endl;
        doubleDimensions(r1);
        }
    }while(area1 < 500);

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*

ryanreagle@Ryans-MacBook-Pro-2 output % ./"rectangle"
Enter the length of the rectangle: -20
Please Enter a length greater than 0!
Enter the length of the rectangle: 15.75
Enter the width of the rectangle: 0
Please Enter a width greater than 0!
Enter the width of the rectangle: 1.2
15.75 x 1.20 = 18.90
31.50 x 2.40 = 75.60
63.00 x 4.80 = 302.40
DONE%                                                                                                                                                                    
ryanreagle@Ryans-MacBook-Pro-2 output % 

*/