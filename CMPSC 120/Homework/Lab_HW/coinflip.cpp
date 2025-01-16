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
// Assignment: Lab 14 Bonus
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <random>

using namespace std;

// Methods
bool coinFlip();

bool coinFlip() {
    int coin;
    coin = rand() % 2;
    return coin;
}

int main() {
    // Seed the random number generator once
    srand((unsigned)time(nullptr));

    // Variables
    bool result;
    char choice;
    int test = 100;
    int headCount = 0;
    int tailCount = 0;

    cout << "Welcome to the coin flip game!";
    do {
        result = coinFlip();
        if (result) {
            cout << "H ";
            headCount++;
        } else {
            cout << "T ";
            tailCount++;
        }
        test--;
    } while (test > 0);
    cout << endl;
    cout << "Heads: " << headCount << endl;
    cout << "Tails: " << tailCount << endl;


    //Start Of Game
    cout << "Each game costs $5.50. We'll flip a coin until the first Head appears, on the nth flip.";
    cout << endl;
    cout << "Your winnings will be $2^(n-2).";
    cout << endl;
    cout << "Would you like to play a game?: ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        double balance = 0.0;
        do {
            int n = 0;
            int winnings = 0;
            string gameResults = "";
            double gameCost = 5.50;

            cout << "Prev. Balance: " << fixed << setprecision(2) << balance << endl;
            cout << "Game Cost: " << gameCost << endl;
            balance -= gameCost;

            do {
                result = coinFlip();
                gameResults += result ? "H" : "T";
                n++;
                if (result) {
                    winnings = pow(2, n - 2);
                }
            } while (!result);

            balance += winnings;

            cout << "Game Results: " << gameResults << endl;
            cout << "Winnings: " << fixed << setprecision(2) << winnings << endl;
            cout << "New Balance: " << fixed << setprecision(2) << balance << endl;
            cout << "Would you like to play another game for $5.50? ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
        cout << "Thanks for playing! Congratulations on your winnings of $" << fixed << setprecision(2) << balance << "!" << endl;
    }

    return 0;
}


/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"coinflip"
Welcome to the coin flip game!T T T H T H H H T H T H H T T T T H H H H T T T T H H T T H H H H T H H T T T H H H H H T T H T T H H H T H H T T H T T T T H H T H H H H H T H T T H T T T H H T H H T T T H T T T H T T H H H H T T H 
Heads: 51
Tails: 49
Each game costs $5.50. We'll flip a coin until the first Head appears, on the nth flip.
Your winnings will be $2^(n-2).
Would you like to play a game?: y
Prev. Balance: 0.00
Game Cost: 5.50
Game Results: TTH
Winnings: 2
New Balance: -3.50
Would you like to play another game for $5.50? y
Prev. Balance: -3.50
Game Cost: 5.50
Game Results: TH
Winnings: 1
New Balance: -8.00
Would you like to play another game for $5.50? y
Prev. Balance: -8.00
Game Cost: 5.50
Game Results: TH
Winnings: 1
New Balance: -12.50
Would you like to play another game for $5.50? n
Thanks for playing! Congratulations on your winnings of $-12.50!
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/