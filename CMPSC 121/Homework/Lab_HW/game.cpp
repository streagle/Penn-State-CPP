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
// Assignment: Lab 14
//

#include <iostream>
#include <random>
#include <ctime>

using namespace std;
// Methods
bool checkAnswer(int userInput, int max, int correctAnswer);

bool checkAnswer(int userInput, int max, int correctAnswer)
{
    if (userInput < 1)
    {
        cout << "Invalid input. Please enter a number greater than 0." << endl;
        return false;
    }
    if (userInput > max)
    {
        cout << "Invalid input. Please enter a number less than " << max << "." << endl;
        return false;
    }
    if (userInput == correctAnswer)
    {
        cout << "Congratulations! You guessed the correct number, " << correctAnswer << "!" << endl;
        return true;
    }
    if (userInput < correctAnswer)
    {
        cout << "Too low, try again." << endl;
        return false;
    }
    if (userInput > correctAnswer)
    {
        cout << "Too high, try again." << endl;
        return false;
    }

    return false;
}

int main()
{
    // Variables
    int userInput;
    int max;
    int correctAnswer;
    srand((unsigned)time(nullptr));

    // Inputs
    do
    {
        cout << "Enter  upper Limit of the guessing game: ";
        cin >> max;
        if (max < 1)
        {
            cout << "Invalid input. Please enter a number greater than 0." << endl;
        }
    } while (max < 1);

    // Generate random number

    correctAnswer = rand() % max + 1;

    // Processes
    do
    {
        cout << "Enter your guess: ";
        cin >> userInput;
    } while (!checkAnswer(userInput, max, correctAnswer));

    // Outputs

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"game"
Enter  upper Limit of the guessing game: 100
Enter your guess: 101
Invalid input. Please enter a number less than 100.
Enter your guess: -1
Invalid input. Please enter a number greater than 0.
Enter your guess: 80
Too low, try again.
Enter your guess: 93
Too high, try again.
Enter your guess: 90
Too high, try again.
Enter your guess: 85
Too high, try again.
Enter your guess: 83
Too high, try again.
Enter your guess: 81
Too low, try again.
Enter your guess: 82
Congratulations! You guessed the correct number, 82!
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/