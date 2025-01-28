#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>
#include <sstream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

atomic<bool> keepRunning(true); // Control the background task
mutex mtx;

int tempPoints = 0;

void diceRoller(int diceSides)
{
    int diceRoll;
    srand(static_cast<unsigned int>(time(NULL)));
    diceRoll = rand() % diceSides + 1; // Roll the dice
    cout << "You rolled a " << diceRoll << endl;
    tempPoints += diceRoll; // Add roll result to points
    cout << "Your points: " << tempPoints << endl;
    cout << endl;
}
int autoDiceRoller(int diceSides)
{
    int diceRoll;
    srand(static_cast<unsigned int>(time(NULL)));
    diceRoll = rand() % diceSides + 1; // Roll the dice
    cout << "Auto Roller rolled a " << diceRoll << endl;
    tempPoints += diceRoll; // Add roll result to points

    cout << endl;
    return tempPoints;
}

void backgroundTask()
{
    int diceSides = 6;
    string label, line;

    ifstream file("../dicegame.txt");
    getline(file, line);
    stringstream ss1(line);
    getline(ss1, label, ':'); // Extract the label (e.g., "Sides")
    ss1 >> diceSides;
    file.close();

    while (keepRunning)
    {
        this_thread::sleep_for(chrono::seconds(5)); // Simulate the dice rolling every 5 seconds

        // Lock the mutex while updating the shared counter (avoid race conditions)
        {
            lock_guard<mutex> lock(mtx);
            tempPoints += autoDiceRoller(diceSides);
        }
    }
}

int main()
{
    // Read the file and extract values
    ifstream file("../dicegame.txt");

    if (!file.is_open())
    {
        cerr << "Unable to open file\n";
        return 1;
    }

    // Variables

    int choice;
    int points = 0;
    int diceSides = 6; // Default value in case of error reading from file

    double multiplier = 1.2;
    double cost = 100; // Default cost for dice upgrade
    string label, line;
    int autoRollStatus = 0;

    // Read "Sides: X" and parse the number after the colon
    getline(file, line);
    stringstream ss1(line);
    getline(ss1, label, ':'); // Extract the label (e.g., "Sides")
    ss1 >> diceSides;         // Extract the number after the colon (no ignore needed)

    // Read "Points: X" and parse the number after the colon
    getline(file, line);
    stringstream ss2(line);
    getline(ss2, label, ':'); // Extract the label (e.g., "Points")
    ss2 >> points;            // Extract the number after the colon (no ignore needed)

    getline(file, line); // Read cost line
    stringstream ss3(line);
    getline(ss3, label, ':'); // Extract the label (e.g., "Cost")
    ss3 >> cost;              // Extract the number after the colon (no ignore needed)

    file.close();

    // Output the extracted values for debugging
    cout << "sides: " << diceSides << endl;
    cout << "points: " << points << endl;

    cout << "Welcome to the dice game!" << endl;
    // Processes
    do
    {

        cout << "1. Roll the dice" << endl;
        cout << "2. Shop" << endl;
        cout << "3. Enable/dissable Auto Roller" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Rolling the dice
            {
                diceRoller(diceSides);
            }
            break;

        case 2:
            // Shop functionality
            {
                cout << "Welcome to the shop!" << endl;
                cout << "Would you like to upgrade your dice? (Costs " << cost << " points)" << endl;
                cout << "Current points: " << points << endl;

                cout << "Current sides: " << diceSides << " | Current points: " << points << endl;
                if (points >= cost)
                {
                    diceSides += 1; // Increase dice sides
                    points -= cost;
                    cost = ceil(cost * multiplier); // Increase cost for next upgrade and rounds to the nearest integer
                    cout << "You upgraded your dice to " << diceSides << " sides!" << endl;
                }
                else
                {
                    cout << "Not enough points!" << endl;
                }
            }
            break;

        case 3:
        {
            if (autoRollStatus == 1)
            {
                cout << "Auto Roller is enabled. Disabling..." << endl;
                autoRollStatus = 0;
                points += tempPoints;
                keepRunning = false; // Stop the background task
                // Wait for the background task to finish
                this_thread::sleep_for(chrono::seconds(5));
                cout << "You rolled a total of " << tempPoints << " points in the background task" << endl;
                tempPoints = 0;
            }
            else
            {
                cout << "Auto Roller is disabled. Enabling..." << endl;
                tempPoints = 0;
                autoRollStatus = 1;
                keepRunning = true; // Start the background task
                thread bgThread(backgroundTask);
                bgThread.detach();
            }
        }
        break;

        case 4:
            // Write the updated values back to the file
            {
                ofstream outFile("../dicegame.txt");
                outFile << "Sides: " << diceSides << endl;
                outFile << "Points: " << points << endl;
                outFile << "Cost: " << cost << endl;
                outFile.close();
                cout << "Game progress saved. Goodbye!" << endl;
                break;
            }
        default:
            cout << "Invalid choice" << endl;
            choice = 4; // Exit the loop, breaks the inf loop if a char is entered
            break;
        }
    } while (choice != 4);

    return 0;
}