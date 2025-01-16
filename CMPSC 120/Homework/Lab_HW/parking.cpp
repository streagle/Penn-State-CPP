
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
// Assignment: Lab 5 (Parking Rate)
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

using namespace std;
// Methods

int main()
{
    // Variables
    char vehicleType;
    string vehicleTypeString;
    double hoursParked;
    string lisencePlate;
    double totalCost = 0;

    // Inputs
    cout << "Enter the type of vehicle (C for car, T for truck, B for bus): ";
    cin >> vehicleType;
    if (vehicleType != 'C' && vehicleType != 'c' && vehicleType != 'T' && vehicleType != 't' && vehicleType != 'B' && vehicleType != 'b')
    {
        cout << "Invalid vehicle type" << endl;
        return 0;
    }
    cout << "Enter the number of hours parked: ";
    cin >> hoursParked;
    if (hoursParked < 0)
    {
        cout << "Invalid number of hours" << endl;
        return 0;
    }
    cin.ignore(); // ignores the newline character from the cin
    cout << "Enter the lisence plate: ";
    getline(cin, lisencePlate);
    cout << endl;

    // Processes
    if (vehicleType == 'C' || vehicleType == 'c')
    {
        vehicleTypeString = "Car";
        if (hoursParked <= 2)
        {
            totalCost = hoursParked * 1.25;
        }
        else if (hoursParked > 2)
        {
            hoursParked = ceil(hoursParked);
            totalCost = (hoursParked - 2) * 1.5 + 2.50;
        }
    }
    else if (vehicleType == 'T' || vehicleType == 't')
    {
        vehicleTypeString = "Truck";
        hoursParked = ceil(hoursParked);
        if (hoursParked <= 2)
        {
            totalCost = hoursParked * 2.75;
        }
        else if (hoursParked > 2)
        {
            totalCost = (hoursParked - 2) * 3.75 + 5.50;
        }
    }
    else if (vehicleType == 'B' || vehicleType == 'b')
    {
        vehicleTypeString = "Bus";
        hoursParked = ceil(hoursParked);
        if (hoursParked <= 2)
        {
            totalCost = hoursParked * 9.50;
        }
        else if (hoursParked > 2)
        {
            totalCost = (hoursParked - 2) * 6.75 + 19.00;
        }
    }

    // Outputs

    cout << "Vehicle type: " << vehicleTypeString << endl;
    cout << "Time parked: " << hoursParked << " Hours" << endl;
    cout << "Lisence plate: " << lisencePlate << endl;
    cout << "Total cost: ($) " << fixed << setprecision(2) << totalCost << endl;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                normal output: Car                          */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"parking"
Enter the type of vehicle (C for car, T for truck, B for bus): c
Enter the number of hours parked: 5.5
Enter the lisence plate: ABC 123

Vehicle type: Car
Time parked: 6 Hours
Lisence plate: ABC 123
Total cost: ($) 8.50
ryanreagle@Ryans-MacBook-Pro-2 output %
*/

/* -------------------------------------------------------------------------- */
/*                            normal output: Truck                            */
/* -------------------------------------------------------------------------- */

/*
Enter the type of vehicle (C for car, T for truck, B for bus): T
Enter the number of hours parked: 5.5
Enter the lisence plate: ABC 456

Vehicle type: Truck
Time parked: 6 Hours
Lisence plate: ABC 456
Total cost: ($) 20.50
*/

/* -------------------------------------------------------------------------- */
/*                             normal output: Bus                             */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"parking"
Enter the type of vehicle (C for car, T for truck, B for bus): B
Enter the number of hours parked: 5.5
Enter the lisence plate: ABC 789

Vehicle type: Bus
Time parked: 6 Hours
Lisence plate: ABC 789
Total cost: ($) 46.00
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/


/* -------------------------------------------------------------------------- */
/*                          Error: wrong vehicle type                         */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"parking"
Enter the type of vehicle (C for car, T for truck, B for bus): A
Invalid vehicle type
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

