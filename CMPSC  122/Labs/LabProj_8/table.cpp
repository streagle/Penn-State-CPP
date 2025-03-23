#include <iostream>
#include <string>
#include <queue>

using namespace std;


class TableManager {
    private:
        int totalTables;
        int availableTables;
        queue<string> tableQueue;
        queue<string> waitingLine;
        string tableType;
    
    public:
        // Constructor
        TableManager(int total, const string& type) : totalTables(total), availableTables(total), tableType(type) {}
    
        // Handle a new customer
        void handleNewCustomer(const string& name) {
            if (availableTables > 0) {
                cout << "New customer " << name << " takes an available " << tableType << " table." << endl;
                availableTables--;
                tableQueue.push(name);
            } else {
                cout << "New customer " << name << " enters the " << tableType << " waiting line." << endl;
                waitingLine.push(name);
            }
        }
    
        // Handle a customer checkout
        void handleCheckout() {
            if (tableQueue.empty()) {
                cout << "No customer occupied any " << tableType << " table!" << endl;
                if (availableTables < totalTables) {
                    availableTables++;
                }
            } else {
                string currentCustomer = tableQueue.front();
                cout << "Customer " << currentCustomer << " has checked out from a " << tableType << " table." << endl;
                tableQueue.pop();
    
                if (!waitingLine.empty()) {
                    string nextCustomer = waitingLine.front();
                    waitingLine.pop();
                    tableQueue.push(nextCustomer);
                    cout << "Next customer " << nextCustomer << " takes an available " << tableType << " table." << endl;
                } else {
                    availableTables++;
                }
            }
        }
    
        // Display information about the tables and waiting line
        void displayInfo() const {
            cout << tableType << " tables: " << totalTables - availableTables << " / " << totalTables << endl;
            cout << waitingLine.size() << " customer(s) waiting for " << tableType << " table." << endl;
        }
    };


    int main() {
        cout << "Welcome to the Restaurant Table Management System." << endl;
    
        int totalLargeTables, totalSmallTables;
    
        // Input for large tables
        cout << "Enter the total number of large tables: ";
        do {
            cin >> totalLargeTables;
            if (totalLargeTables < 1) {
                cout << "Invalid input! Please enter a number greater than 0." << endl;
            }
        } while (totalLargeTables < 1);
    
        // Input for small tables
        cout << "Enter the total number of small tables: ";
        do {
            cin >> totalSmallTables;
            if (totalSmallTables < 1) {
                cout << "Invalid input! Please enter a number greater than 0." << endl;
            }
        } while (totalSmallTables < 1);
        cin.ignore(); // Clear the newline character from the input buffer
    
        // Create TableManager objects for small and large tables
        TableManager largeTableManager(totalLargeTables, "large");
        TableManager smallTableManager(totalSmallTables, "small");
    
        string command;
        while (true) {
            cout << "Enter Command: ";
            getline(cin, command);
    
            if (command.substr(0, 10) == "new large ") {
                string name = command.substr(10);
                if (name.empty()) {
                    cout << "Invalid command! Please provide a name after 'new large'." << endl;
                    continue;
                }
                largeTableManager.handleNewCustomer(name);
            } else if (command.substr(0, 10) == "new small ") {
                string name = command.substr(10);
                if (name.empty()) {
                    cout << "Invalid command! Please provide a name after 'new small'." << endl;
                    continue;
                }
                smallTableManager.handleNewCustomer(name);
            } else if (command == "checkout large") {
                largeTableManager.handleCheckout();
            } else if (command == "checkout small") {
                smallTableManager.handleCheckout();
            } else if (command == "info") {
                largeTableManager.displayInfo();
                smallTableManager.displayInfo();
            } else if (command == "exit") {
                break;
            } else {
                cout << "Invalid command!" << endl;
            }
        }
    
        return 0;
    }


/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */
