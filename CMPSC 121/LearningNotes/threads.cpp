#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;                         // Mutex for synchronizing access
bool numberPrinted = false;        // Flag to check if a number was printed

// Function to print numbers from 1 to 5
void printNumbers() {
    for (int i = 1; i <= 5; ++i) {
        {
            unique_lock<mutex> lock(mtx); // Lock the mutex
            cout << "Number: " << i << endl; // Output the current number
            numberPrinted = true; // Set flag indicating a number has been printed
        } // The lock is released here when it goes out of scope

        this_thread::sleep_for(chrono::milliseconds(500)); // Pause for 0.5 seconds

        // Wait until the letter is printed before printing the next number
        while (numberPrinted) {
            // Use a small sleep to avoid busy waiting
            this_thread::sleep_for(chrono::milliseconds(10)); // Pause briefly
        }
    }
}

// Function to print letters from 'A' to 'E'
void printLetters() {
    for (char c = 'A'; c <= 'E'; ++c) {
        {
            unique_lock<mutex> lock(mtx); // Lock the mutex
            while (!numberPrinted) {
                // Use a small sleep to avoid busy waiting
                lock.unlock(); // Unlock the mutex while waiting
                this_thread::sleep_for(chrono::milliseconds(10)); // Pause briefly
                lock.lock(); // Re-lock the mutex
            }
            cout << "Letter: " << c << endl; // Output the current letter
            numberPrinted = false; // Reset the flag for the next number
        } // The lock is released here when it goes out of scope

        this_thread::sleep_for(chrono::milliseconds(500)); // Pause for 0.5 seconds
    }
}

int main() {
    thread t1(printNumbers); // Create thread for printing numbers
    thread t2(printLetters); // Create thread for printing letters

    t1.join(); // Wait for the numbers thread to finish
    t2.join(); // Wait for the letters thread to finish

    cout << "Both threads finished execution!" << endl; // Final message

    return 0; // Return 0 to indicate the program finished successfully
}
