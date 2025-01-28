#include <iostream>
#include <iomanip>

using namespace std;
// Methods

int main()
{
    // Variables
    double distance;
    int weight;
    double rate = 0;
    double cost = 0;

    // Inputs
    cout << "Enter the weight in Kg (20kg Max. ): ";
    cin >> weight;
    if (weight > 20 || weight < 0)
    {
        cout << "Invalid weight" << endl;
        return 0;
    }
    cout << "Enter the distance in miles (10-3000): ";
    cin >> distance;
    cout << endl;
    if (distance < 10 || distance > 3000)
    {
        cout << "Invalid distance" << endl;
        return 0;
    }

    // Processes
    distance = ceil(distance / 500);

    if (weight <= 2)
    {
        rate = 1.10;
    }
    else if (weight > 2 && weight <= 6)
    {
        rate = 2.20;
    }
    else if (weight > 6 && weight <= 10)
    {
        rate = 3.70;
    }
    else if (weight > 10 && weight <= 20)
    {
        rate = 4.80;
    }

    cost = distance * rate;

    // Outputs
    cout << "The cost to ship the package is $" << fixed << setprecision(2) << cost << endl;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                 Test Case 1                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"shippingCharges"
Enter the weight in Kg (20kg Max. ): 25
Invalid weight
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 Test Case 2                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"shippingCharges"
Enter the weight in Kg (20kg Max. ): 5
Enter the distance in miles (10-3000): 3100

Invalid distance
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 Test Case 3                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"shippingCharges"
Enter the weight in Kg (20kg Max. ): 12
Enter the distance in miles (10-3000): 1220

The cost to ship the package is $14.40
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 Test Case 4                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"shippingCharges"
Enter the weight in Kg (20kg Max. ): 6
Enter the distance in miles (10-3000): 2500

The cost to ship the package is $11.00
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/
