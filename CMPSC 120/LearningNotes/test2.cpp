#include <iostream> // Include the iostream library for input and output

using namespace std; // Use the standard namespace

int main() // Main function where the execution starts
{
    int num; // Declare an integer variable to store the user's input number
    do // Start of the do-while loop
    {
        cout << "Enter a number to search for its multiples (1-30): "; // Prompt the user to enter a number
        cin >> num; // Read the user's input and store it in the variable 'num'
        if (num <= 0 || num > 30) // Check if the number is not in the valid range (1-30)
            cout << "The number is not valid" << endl; // Print an error message if the number is not valid
    } while (num <= 0 || num > 30); // Repeat the loop until a valid number is entered

    cout << "The output: "; // Print the output message
    for (int i = 20; i <= 30; i++) // Loop through the numbers from 20 to 30
        if (i % num == 0) // Check if the current number is a multiple of the user's input number
            cout << i << " "; // Print the number if it is a multiple

    return 0; // Return 0 to indicate successful execution
}
