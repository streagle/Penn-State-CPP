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
// Assignment: HW 09
//
#include <iostream>
#include <iomanip>

using namespace std;
// Methods

// get the item purchased and the price and use vectors to store the data
void getPurchase(vector<string> &items, vector<double> &prices)
{
    string item;
    double price;

    while (item != "done")
    {
        cout << "Enter the item purchased or Done to finish: ";
        getline(cin, item);
        if (item == "done" || item == "Done")
        {
            break;

        }
        cout << "Enter the price of the item: ";
        cin >> price;
        cin.ignore();
        items.push_back(item);
        prices.push_back(price);
    }
}

// print the receipt including subtotal, tax, and total
void printReceipt(vector<string> items, vector<double> prices)
{
    double subtotal = 0;
    double tax;
    double total;
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < items.size(); i++)
    {
        cout << setw(15) << left << items[i] << " $" << prices[i] << endl;
        subtotal += prices[i];
    }
    cout << "----------------------" << endl;
    tax = subtotal * 0.06;
    total = subtotal + tax;
    cout << setw(15) << left << "Subtotal" << " $" << subtotal << endl;
    cout << setw(15) << left << "Tax (6%)" << " $" << tax << endl;
    cout << setw(15) << left << "Total" << " $" << total << endl;
}

int main()
{
    // Variables
    vector<string> items;
    vector<double> prices;

    // Inputs

    // Processes
    getPurchase(items, prices);
    cout << endl;
    printReceipt(items, prices);

    // Outputs

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   Output                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"cashRegister"
Enter the item purchased or Done to finish: Hamburger
Enter the price of the item: 2.00
Enter the item purchased or Done to finish: French Fries
Enter the price of the item: 1.50
Enter the item purchased or Done to finish: Bread
Enter the price of the item: 1.50
Enter the item purchased or Done to finish: Done

Hamburger       $2.00
French Fries    $1.50
Bread           $1.50
----------------------
Subtotal        $5.00
Tax (6%)        $0.30
Total           $5.30
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/