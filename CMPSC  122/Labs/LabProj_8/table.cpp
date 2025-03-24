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
// Assignment: LabProj 08
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class TableManager {
    private:
        int totalTables;
        int availableTables;
        queue<string> tableQueue;
        queue<string> waitingLine;
        string tableType;
        TableManager* backupManager; // Pointer to backup manager (e.g., large tables for small tables)
    
    public:
        // Constructor
        TableManager(int total, const string& type) : totalTables(total), availableTables(total), tableType(type), backupManager(nullptr) {}
    
        // Set backup manager
        void setBackupManager(TableManager* backup) {
            backupManager = backup;
        }
    
        // Handle a new customer
        void handleNewCustomer(const string& name) {
            if (availableTables > 0) {
                cout << "New customer " << name << " takes an available " << tableType << " table." << endl;
                availableTables--;
                tableQueue.push(name);
            } else if (backupManager && backupManager->hasAvailableTables()) {
                backupManager->handleNewCustomer(name);
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
    
        // Check if there are available tables
        bool hasAvailableTables() const {
            return availableTables > 0;
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

    // Set backup manager for small tables
    smallTableManager.setBackupManager(&largeTableManager);

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
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"table"
Welcome to the Restaurant Table Management System.
Enter the total number of large tables: 2
Enter the total number of small tables: 3
Enter Command: checkout large
No customer occupied any large table!
Enter Command: checkout small
No customer occupied any small table!
Enter Command: new large Edison
New customer Edison takes an available large table.
Enter Command: new large Matt
New customer Matt takes an available large table.
Enter Command: new large Luke
New customer Luke enters the large waiting line.
Enter Command: info
large tables: 2 / 2
1 customer(s) waiting for large table.
small tables: 0 / 3
0 customer(s) waiting for small table.
Enter Command: checkout large
Customer Edison has checked out from a large table.
Next customer Luke takes an available large table.
Enter Command: checkout large
Customer Matt has checked out from a large table.
Enter Command: info     
large tables: 1 / 2
0 customer(s) waiting for large table.
small tables: 0 / 3
0 customer(s) waiting for small table.
Enter Command: checkout large
Customer Luke has checked out from a large table.
Enter Command: checkout large
No customer occupied any large table!
Enter Command: New large Todd
Invalid command!
Enter Command: new small Andy
New customer Andy takes an available small table.
Enter Command: new small Ken
New customer Ken takes an available small table.
Enter Command: new small Dan
New customer Dan takes an available small table.
Enter Command: new small Frank
New customer Frank takes an available large table.
Enter Command: new small Will
New customer Will takes an available large table.
Enter Command: info
large tables: 2 / 2
0 customer(s) waiting for large table.
small tables: 3 / 3
0 customer(s) waiting for small table.
Enter Command: new small Smith
New customer Smith enters the small waiting line.
Enter Command: new large Marry
New customer Marry enters the large waiting line.
Enter Command: info
large tables: 2 / 2
1 customer(s) waiting for large table.
small tables: 3 / 3
1 customer(s) waiting for small table.
Enter Command: testing invalid command
Invalid command!
Enter Command: checkout Large
Invalid command!
Enter Command: exit
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/