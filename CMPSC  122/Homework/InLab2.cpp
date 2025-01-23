#include <iostream>
#include <iomanip> // For fixed and setprecision
#include <algorithm> // For sort
using namespace std;

// Function prototypes
void sortScores(double* scores, int size);
double calculateAverage(double* scores, int size);
void dropLowestAndRecalculate(double* scores, int size);

int main() {
    int numScores;

    // Prompt the user for the number of test scores
    cout << "Please enter the number of test scores: ";
    cin >> numScores;

    // Input validation for number of test scores
    while (numScores <= 0) {
        cout << "Number of test scores must be greater than 0. Try again: ";
        cin >> numScores;
    }

    // Dynamically allocate an array for test scores
    double* scores = new double[numScores];

    // Input test scores
    for (int i = 0; i < numScores; ++i) {
        cout << "Enter test score " << i + 1 << ": ";
        cin >> *(scores + i);

        // Input validation for scores
        while (*(scores + i) < 0) {
            cout << "Test scores cannot be negative. Re-enter test score " << i + 1 << ": ";
            cin >> *(scores + i);
        }
    }

    // Sort scores
    sortScores(scores, numScores);

    // Display sorted scores
    cout << "\nThe test scores ascending order:\n";
    cout << "================================\n";
    for (int i = 0; i < numScores; ++i) {
        cout << *(scores + i) << endl;
    }

    // Calculate and display average
    double average = calculateAverage(scores, numScores);
    cout << fixed << setprecision(2);
    cout << "\nThe average score is " << average << "\n";

    // Drop the lowest score and recalculate the average
    dropLowestAndRecalculate(scores, numScores);

    // Deallocate memory
    delete[] scores;
    return 0;
}

// Function to sort scores in ascending order
void sortScores(double* scores, int size) {
    sort(scores, scores + size);
}

// Function to calculate the average of scores
double calculateAverage(double* scores, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += *(scores + i);
    }
    return sum / size;
}

// Function to drop the lowest score and recalculate the average
void dropLowestAndRecalculate(double* scores, int size) {
    if (size <= 1) {
        cout << "\nNot enough scores to drop the lowest one.\n";
        return;
    }

    // Create a new array excluding the lowest score
    double* newScores = new double[size - 1];
    for (int i = 1; i < size; ++i) {
        *(newScores + i - 1) = *(scores + i);
    }

    // Display scores after dropping the lowest
    cout << "\nThe test scores (dropping lowest):\n";
    cout << "==================================\n";
    for (int i = 0; i < size - 1; ++i) {
        cout << *(newScores + i) << endl;
    }

    // Calculate and display the new average
    double newAverage = calculateAverage(newScores, size - 1);
    cout << "\nThe average score is " << newAverage << "\n";

    // Deallocate memory for the new array
    delete[] newScores;
}

//OUTPUT
/*

Please enter the number of test scores: -1
Number of test scores must be greater than 0. Try again: 5 
Enter test score 1: 90
Enter test score 2: 80
Enter test score 3: 60
Enter test score 4: 70
Enter test score 5: 100

The test scores ascending order:
================================
60
70
80
90
100

The average score is 80.00

The test scores (dropping lowest):
==================================
70.00
80.00
90.00
100.00

The average score is 85.00
*/
