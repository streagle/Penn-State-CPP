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
// Assignment: Homework 07
//
#include <iostream>
#include <iomanip>

using namespace std;
bool askLoan();
double askIncome();
double askAmount();
bool decideLoan(double income, double loan);

// Methods

bool askLoan()
{
    string answer;

    while (true)
    {
        cout << "Do you want to apply for a loan? (y/n): ";
        cin >> answer;
        if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes")
        {
            return true;
        }
        else if (answer == "n" || answer == "N" || answer == "no" || answer == "No")
        {
            return false;
        }
        else
        {
            cout << "Invalid input. Please enter yes or no." << endl;
        }
    }
}

double askAmount()
{
    double amount;
    do
    {
        cout << "Enter the amount you would like to borrow: ";
        cin >> amount;
        if (amount < 0)
        {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    } while (amount < 0);
    return amount;
}

double askIncome()
{
    double income;
    do
    {
        cout << "Enter your annual income: ";
        cin >> income;
        if (income < 0)
        {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    } while (income < 0);
    return income;
}

bool decideLoan(double income, double loan)
{
    if (income <= 10000)
    {
        return false;
    }
    else if (income >= 100000)
    {
        return true;
    }
    else if (income > 10000 && income < 100000)
    {
        if (income * 5 >= loan)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    // Variables
    bool loanChoice, decision;
    double amountBorrowed, annualIncome;

    // Logic
    loanChoice = askLoan();
    if (loanChoice)
    {
        do
        {
            amountBorrowed = askAmount();

        } while (amountBorrowed < 0);
        do
        {
            annualIncome = askIncome();
        } while (annualIncome < 0);
        decision = decideLoan(annualIncome, amountBorrowed);
        if (decision)
        {
            cout << "Congratulations! Your loan of $" << amountBorrowed << " has been approved." << endl;
        }
        else
        {
            cout << "I'm sorry, but your loan of $" << amountBorrowed << " has been denied." << endl;
        }
    }
    else
    {
        cout << "Thank you for visiting the bank." << endl;
    }

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                               Example output                               */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./bankloan
Do you want to apply for a loan? (y/n): y
Enter the amount you would like to borrow: -5
Invalid input. Please enter a positive number.
Enter the amount you would like to borrow: 10000
Enter your annual income: 5000
I'm sorry, but your loan of $10000 has been denied.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                              Example output 2                              */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"bankloan"
Do you want to apply for a loan? (y/n): yes
Enter the amount you would like to borrow: 45000
Enter your annual income: 15000
Congratulations! Your loan of $45000 has been approved.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/