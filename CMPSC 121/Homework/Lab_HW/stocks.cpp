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
// Assignment: Lab 07
//

#include <iostream>
#include <iomanip>

using namespace std;
// Methods

int getInt(string prompt);
double getDouble(string prompt);

void calculateProfit(int NS, double SP, double SC, double PP, double PC)
{

    double profit = ((NS * SP) - SC) - ((NS * PP) + PC);

    cout << "The profit on the stock was : $" << fixed << setprecision(2) << profit << endl;
}

int getInt(string prompt)
{
    int value;
    do
    {
        cout << prompt;
        cin >> value;
        if (value < 0)
        {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    } while (value < 0);
    return value;
};
double getDouble(string prompt)
{
    double value;
    do
    {
        cout << prompt;
        cin >> value;
        if (value < 0)
        {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    } while (value < 0);
    return value;
};

int main()
{
    // Variables
    double shares, salePrice, saleCommission, purchasePrice, purchaseCommission;

    shares = getInt("Enter the number of shares purchased: ");

    purchasePrice = getDouble("Enter the purchase price: ");

    purchaseCommission = getDouble("Enter the purchase commission: ");

    salePrice = getDouble("Enter the sale price: ");

    saleCommission = getDouble("Enter the sale commission: ");

    calculateProfit(shares, salePrice, saleCommission, purchasePrice, purchaseCommission);

    // Inputs

    // Processes

    // Outputs

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                               Sample output 1                              */
/* -------------------------------------------------------------------------- */

/*

ryanreagle@Ryans-MacBook-Pro-2 output % ./"stocks"
Enter the number of shares purchased: 10
Enter the purchase price: 100.00
Enter the purchase commission: 10.00
Enter the sale price: 200.00
Enter the sale commission: 10.00
The profit on the stock was : $980.00
ryanreagle@Ryans-MacBook-Pro-2 output %

*/