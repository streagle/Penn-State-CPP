#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

using namespace std;

//This could work for the dice game and i can use the option autoRollStatus to check the total points collected from the auto roll.

atomic<bool> keepRunning(true);   // Control the background task
mutex mtx;                        // Mutex to protect shared data

// Shared resource (could be used by the background task)
int backgroundCounter = 0;

// Background task (runs independently, but without interfering with the menu)
void backgroundTask() {
    while (keepRunning) {
        this_thread::sleep_for(chrono::seconds(5));  // Simulate some background work every 5 seconds

        // Lock the mutex while updating the shared counter (avoid race conditions)
        {
            lock_guard<mutex> lock(mtx);
            backgroundCounter++;  // Increment the counter as background work
        }

        // You can optionally log this information or display it periodically
        // to a file or another part of the UI, but we suppress it to avoid interfering
    }
}

// Function for menu interaction
void displayMenu() {
    int choice;
    do {
        // Display the menu
        cout << "\n--- Menu ---" << endl;
        cout << "1. Do something" << endl;
        cout << "2. Show background task progress" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "You chose to do something!" << endl;
                break;
            case 2:
                // Show background task progress safely
                {
                    lock_guard<mutex> lock(mtx);
                    cout << "Background task has updated the counter to: " << backgroundCounter << endl;
                }
                break;
            case 3:
                cout << "Exiting the program..." << endl;
                keepRunning = false;  // Stop the background task
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 3);
}

int main() {
    // Start the background task in a separate thread
    thread bgThread(backgroundTask);

    // Run the menu on the main thread
    displayMenu();

    // Wait for the background task to finish before exiting
    if (bgThread.joinable()) {
        bgThread.join();
    }

    cout << "Program has exited." << endl;
    return 0;
}
