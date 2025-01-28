#include <iostream>
#include <iomanip>
#include <random>

using namespace std;
// Methods

// AI Guess Method (Not the most optimal)
int aiGuess(int numberOfItems, int maxItems, int userGuessNumber, int moveNumber)
{
    if (numberOfItems <= maxItems)
    {
        // If the AI can win in one move, it should take all remaining items
        return numberOfItems;
    }
    if (moveNumber == 1)
    {
        maxItems = numberOfItems / 4; //? Sets maxItems to 1/4 of the total number of items so the opponent cant win in 1 turn
        // For the first move, AI randomly selects a number between 1 and maxItems-1
        return rand() % (maxItems - 1) + 1;
    }
    else
    {
        // Calculate the optimal move based on the current number of items and user's last guess
        int optimalMove = numberOfItems % (userGuessNumber + 1); // optimal move is the remainder of the number of items divided by the user's last guess + 1
        if (optimalMove == 0 || optimalMove > maxItems)
        {
            // If the optimal move is not possible, take the maximum allowed items or remaining items
            return min(maxItems, numberOfItems);
        }
        else
        {
            // Otherwise, take the optimal move
            return optimalMove;
        }
    }
}

int main()
{
    // Variables
    int aiGuessNumber = 0;
    int userGuessNumber = 0;
    int numberOfItems = 0;
    int moveNumber = 1;
    bool gameWon = false;
    bool turn = true;

    // Game
    cout << "Would you like to go first? (Y/N): ";
    char userChoice;
    cin >> userChoice;
    if (userChoice == 'Y' || userChoice == 'y')
    {
        turn = true;
    }
    else if (userChoice == 'N' || userChoice == 'n')
    {
        turn = false;
    }
    else
    {
        do
        {
            cout << "Invalid input. Please enter Y or N." << endl;
            cin >> userChoice;
            if (userChoice == 'Y' || userChoice == 'y')
            {
                turn = true;
            }
            else if (userChoice == 'N' || userChoice == 'n')
            {
                turn = false;
            }
        } while (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N' && userChoice != 'n');
    }

    cout << "Enter the number of items: ";
    do
    {
        cin >> numberOfItems;
        if (numberOfItems < 2)
        {
            cout << "Please enter a number greater than 1: ";
        }
    } while (numberOfItems < 2);

    while (!gameWon)
    {
        if (turn)
        {
            int maxGuess = (moveNumber == 1) ? numberOfItems - 1 : min(2 * aiGuessNumber, numberOfItems);
            if (moveNumber == 1)
            {
                maxGuess = numberOfItems - 1;
            }
            else
            {
                maxGuess = min(2 * aiGuessNumber, numberOfItems);
            }
            cout << "Enter your guess(1-" << maxGuess << "): ";
            cin >> userGuessNumber;
            while (userGuessNumber < 1 || userGuessNumber > maxGuess)
            {
                cout << "Please enter a valid number (1-" << maxGuess << "): ";
                cin >> userGuessNumber;
            }
            numberOfItems -= userGuessNumber;
            cout << "There are " << numberOfItems << " items left." << endl;
            if (numberOfItems == 0)
            {
                cout << "You win!" << endl;
                gameWon = true;
            }
        }
        else
        {
            srand((unsigned)time(NULL));
            aiGuessNumber = aiGuess(numberOfItems, 2 * userGuessNumber, userGuessNumber, moveNumber);
            cout << "The AI took " << aiGuessNumber << " items." << endl;
            numberOfItems -= aiGuessNumber;
            cout << "There are " << numberOfItems << " items left." << endl;
            if (numberOfItems == 0)
            {
                cout << "AI wins!" << endl;
                gameWon = true;
            }
        }
        turn = !turn;
        moveNumber++;
    }

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                             OUTPUT GOING FIRST                             */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"LabProj1"
Would you like to go first? (Y/N): Y
Enter the number of items: 20
Enter your guess(1-19): 5
There are 15 items left.
The AI took 3 items.
There are 12 items left.
Enter your guess(1-6): 2
There are 10 items left.
The AI took 1 items.
There are 9 items left.
Enter your guess(1-2): 2
There are 7 items left.
The AI took 1 items.
There are 6 items left.
Enter your guess(1-2): 1
There are 5 items left.
The AI took 1 items.
There are 4 items left.
Enter your guess(1-2): 1
There are 3 items left.
The AI took 1 items.
There are 2 items left.
Enter your guess(1-2): 2
There are 0 items left.
You win!
ryanreagle@Ryans-MacBook-Pro-2 output %
*/

/* -------------------------------------------------------------------------- */
/*                             OUTPUT GOING SECOND                            */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"LabProj1"
Would you like to go first? (Y/N): N
Enter the number of items: 20
The AI took 1 items.
There are 19 items left.
Enter your guess(1-2): 2
There are 17 items left.
The AI took 2 items.
There are 15 items left.
Enter your guess(1-4): 4
There are 11 items left.
The AI took 1 items.
There are 10 items left.
Enter your guess(1-2): 2
There are 8 items left.
The AI took 2 items.
There are 6 items left.
Enter your guess(1-4): 1
There are 5 items left.
The AI took 1 items.
There are 4 items left.
Enter your guess(1-2): 1
There are 3 items left.
The AI took 1 items.
There are 2 items left.
Enter your guess(1-2): 2
There are 0 items left.
You win!
ryanreagle@Ryans-MacBook-Pro-2 output %
*/

/* -------------------------------------------------------------------------- */
/*                                OUTPUT LOSING                               */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"LabProj1"
Would you like to go first? (Y/N): Y
Enter the number of items: 20
Enter your guess(1-19): 5
There are 15 items left.
The AI took 3 items.
There are 12 items left.
Enter your guess(1-6): 6
There are 6 items left.
The AI took 6 items.
There are 0 items left.
AI wins!
ryanreagle@Ryans-MacBook-Pro-2 output %
*/

/* -------------------------------------------------------------------------- */
/*                           OUTPUT INCORRECT INPUT                           */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"LabProj1"
Would you like to go first? (Y/N): Y
Enter the number of items: 20
Enter your guess(1-19): 20
Please enter a valid number (1-19): 5
There are 15 items left.
The AI took 3 items.
There are 12 items left.
Enter your guess(1-6): 7
Please enter a valid number (1-6): 6
There are 6 items left.
The AI took 6 items.
There are 0 items left.
AI wins!
ryanreagle@Ryans-MacBook-Pro-2 output %
*/