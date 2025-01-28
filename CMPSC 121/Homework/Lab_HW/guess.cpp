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
// Assignment: Lab 06
//
#include <iostream>
#include <iomanip>

using namespace std;
// Methods

int main()
{
    // Variables
    int upperLimit;
    int lowerLimit = 1;
    int randomNumber;
    int guess = 0;

    // Inputs

    cout << "Enter the upper limit for the range of numbers: ";
    cin >> upperLimit;
    while (upperLimit < 1)
    {
        cout << "The upper limit must be greater than 0!" << endl;
        cout << "Enter the upper limit for the range of numbers: ";
        cin >> upperLimit;
    }

    // Processes
    srand(time(NULL));
    randomNumber = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;

    //cout << randomNumber << endl; // outputs number for testing reasons

    while (guess != randomNumber)
    {
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess > upperLimit || guess < lowerLimit)
        {
            cout << "Invalid guess. Please enter a number between 1 and " << upperLimit << endl;
        }
        else
        {

            if (guess > randomNumber)
            {
                cout << "Too high!" << endl;
            }
            else if (guess < randomNumber)
            {
                cout << "Too low!" << endl;
            }
        }
    }

    cout << "Congratulations! You guessed the correct number, " << randomNumber << endl;

    // Outputs

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                              Output example 1                              */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"guess"
Enter the upper limit for the range of numbers: 10
Enter your guess: 11
Invalid guess. Please enter a number between 1 and 10
Enter your guess: -1
Invalid guess. Please enter a number between 1 and 10
Enter your guess: 5
Too high!
Enter your guess: 3
Too high!
Enter your guess: 1
Too low!
Enter your guess: 2
Congratulations! You guessed the correct number, 2
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/