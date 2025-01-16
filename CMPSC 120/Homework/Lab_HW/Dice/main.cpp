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
// Assignment: HW 12
//

#include "Dice.cpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>


using namespace std;

void display_probabilities_and_histogram(Dice dice[], int numDice);
double outcome_probability(Dice dice[], int numDice, int outcome);\
int count_combinations(int outcome);

double outcome_probability(Dice dice[], int n_dice, int outcome) {
    const int TOSS_COUNT = 1000000;
    double outcomeCount = 0;

    for (int i = 0; i < TOSS_COUNT; ++i) {
        int sum = 0;
        for (int j = 0; j < n_dice; ++j) {
            dice[j].toss();
            sum += dice[j].getSideUp();
        }
        if (sum == outcome) {
            ++outcomeCount;
        }
    }

    return outcomeCount / TOSS_COUNT;
}

int count_combinations(int outcome) {
    int count = 0;

    // Loop through all combinations of three dice
    for (int die1 = 1; die1 <= 6; die1++) {
        for (int die2 = 1; die2 <= 6; die2++) {
            for (int die3 = 1; die3 <= 6; die3++) {
                if (die1 + die2 + die3 == outcome) {
                    count++;
                }
            }
        }
    }

    return count;
}


void display_probabilities_and_histogram(Dice dice[], int n_dice) {
    const int MIN_OUTCOME = 3;
    const int MAX_OUTCOME = 18;
    const int SCALE_FACTOR = 150; // Scale for the histogram

    // Header
    cout << right << setw(7) << "Outcome"
         << right << setw(12) << "Probability"
         << setw(15) << "Outcome Count"
         << "   Distribution Histogram" << endl;

    // Separator with specific spacing
    cout << string(7, '=') << " " 
         << string(11, '=') << "  " 
         << string(13, '=') << "   " 
         << string(21, '=') << endl;

    for (int outcome = MIN_OUTCOME; outcome <= MAX_OUTCOME; outcome++) {
        // Call outcome_probability to get the probability
        double probability = outcome_probability(dice, n_dice, outcome);
        
        // Get the actual outcome count from the combination counting function
        int outcome_count = count_combinations(outcome);

        // Calculate the histogram bar length (ensure at least 1 *)
        int histogram_bar = (probability * SCALE_FACTOR);
        if (histogram_bar < 1) histogram_bar = 1; // Ensure at least 1 *

        // Center the outcome count within a width of 15
        string outcome_count_str = to_string(outcome_count);
        int padding = (15 - outcome_count_str.length()) / 2; // Calculate padding for centering
        string padded_outcome_count = string(padding, ' ') + outcome_count_str; // Create padded outcome count string

        // Display the row
        cout << right << setw(7) << outcome // Outcome right-aligned
             << right << fixed << setprecision(7) << setw(12) << probability
             << padded_outcome_count // Centered outcome count
             << string(10, ' ') << string(histogram_bar, '*') << endl;
    }
}




int main()
{
    const int NUM_DICE = 3;
    const int TOSS_COUNT = 1000000;
    double sameNumberCount = 0;

    // Create three dice objects
    Dice dice1;
    Dice dice2;
    Dice dice3;

    // Toss the dice 1,000,000 times and count the number of times all dice show the same number
    for (int i = 0; i < TOSS_COUNT; ++i) {
        dice1.toss();
        dice2.toss();
        dice3.toss();
        if (dice1.getSideUp() == dice2.getSideUp() && dice2.getSideUp() == dice3.getSideUp()) {
            ++sameNumberCount;
        }
    }

    cout << "The initial side-up values of the three dice are: " << dice1.getSideUp() << ", " << dice2.getSideUp() << ", " << dice3.getSideUp() << endl;
    cout << "The theoretical probability of 3 dice tosses with the same number = 0.02777" << endl;
    cout << "The experimental probability of 3 dice tosses with the same number = " << sameNumberCount / TOSS_COUNT << endl;

    int userNumber;
    do {
        cout << "Enter a number between 3 and 18 (or 0 to exit): ";
        cin >> userNumber;

        if (userNumber == 0) {
            break;
        }

        if (userNumber < 3 || userNumber > 18) {
            cout << "Invalid number. Please enter a number between 3 and 18." << endl;
            continue;
        }

        double sumCount = 0;
        for (int i = 0; i < TOSS_COUNT; ++i) {
            
            dice1.toss();
            dice2.toss();
            dice3.toss();
            int sum = dice1.getSideUp() + dice2.getSideUp() + dice3.getSideUp();
            if (sum == userNumber) {
                ++sumCount;
            }
        }

        cout << "Ratio of outcomes with sum " << userNumber << ": " << sumCount / TOSS_COUNT << endl;

    } while (userNumber != 0);

    // Create an array of dice
    Dice dice[NUM_DICE] = {dice1, dice2, dice3};

    // Display the probabilities and histogram
    srand(static_cast<unsigned int>(time(NULL))); // Seed based on current time
    display_probabilities_and_histogram(dice, NUM_DICE);
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*

ryanreagle@MacBookPro output % ./"main"
The initial side-up values of the three dice are: 6, 5, 5
The theoretical probability of 3 dice tosses with the same number = 0.02777
The experimental probability of 3 dice tosses with the same number = 0.028093
Enter a number between 3 and 18 (or 0 to exit): -1
Invalid number. Please enter a number between 3 and 18.
Enter a number between 3 and 18 (or 0 to exit): 19
Invalid number. Please enter a number between 3 and 18.
Enter a number between 3 and 18 (or 0 to exit): 1
Invalid number. Please enter a number between 3 and 18.
Enter a number between 3 and 18 (or 0 to exit): 5
Ratio of outcomes with sum 5: 0.027709
Enter a number between 3 and 18 (or 0 to exit): 18
Ratio of outcomes with sum 18: 0.004542
Enter a number between 3 and 18 (or 0 to exit): 0
Outcome Probability  Outcome Count   Distribution Histogram
======= ===========  =============   =====================
      3   0.0047600       1          *
      4   0.0137190       3          **
      5   0.0280570       6          ****
      6   0.0462660      10          ******
      7   0.0690270      15          **********
      8   0.0975970      21          **************
      9   0.1158740      25          *****************
     10   0.1257070      27          ******************
     11   0.1258290      27          ******************
     12   0.1162470      25          *****************
     13   0.0967030      21          **************
     14   0.0694100      15          **********
     15   0.0464910      10          ******
     16   0.0277080       6          ****
     17   0.0139180       3          **
     18   0.0047730       1          *
ryanreagle@MacBookPro output % 

*/
