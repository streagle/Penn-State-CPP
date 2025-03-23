#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

using namespace std;

int main() {
    stack<int> s;
    queue<int> q;
    int choice;
    int number;
    bool loop = true;

    while (loop) {
        cout << "1. Push a number to the stack" << endl;
        cout << "2. Pop a number from the stack" << endl;
        cout << "3. Enqueue a number to the queue" << endl;
        cout << "4. Dequeue a number from the queue" << endl;
        cout << "5. Display the stack and queue" << endl;
        cout << "6. Exit" << endl;
        cout << "--------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number you want to push to the stack: ";
                cin >> number;
                s.push(number);
                cout << "Updated Stack is: ";
                {
                    stack<int> tempStack = s; // Create a copy of the stack
                    while (!tempStack.empty()) {
                        cout << tempStack.top() << " ";
                        tempStack.pop();
                    }
                }
                cout << endl;
                break;
            case 2:
                if (s.empty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Popped number is: " << s.top() << endl;
                    s.pop();
                }
                break;
            case 3:
                cout << "Enter the number you want to enqueue to the queue: ";
                cin >> number;
                q.push(number);
                break;
            case 4:
                if (q.empty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Dequeued number is: " << q.front() << endl;
                    q.pop();
                }
                break;
            case 5:
                // Display stack
                cout << "Stack is: ";
                {
                    stack<int> tempStack = s; // Create a copy of the stack
                    while (!tempStack.empty()) {
                        cout << tempStack.top() << " ";
                        tempStack.pop();
                    }
                }
                cout << endl;

                // Display queue
                cout << "Queue is: ";
                {
                    queue<int> tempQueue = q; // Create a copy of the queue
                    while (!tempQueue.empty()) {
                        cout << tempQueue.front() << " ";
                        tempQueue.pop();
                    }
                }
                cout << endl;
                break;
            case 6:
                loop = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << "--------------------------------" << endl;
    }

    return 0;
}
