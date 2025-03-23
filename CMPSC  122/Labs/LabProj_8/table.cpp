#include <iostream>
#include <string>
#include <queue>

using namespace std;

/* -------------------------------------------------------------------------- */
/*                              USING STL QUEUES                              */
/* -------------------------------------------------------------------------- */

/* ---------------------- new large <name of customer> ---------------------- */
/*
The user uses this command when there is a new customer that requests a large table. If there is a seat
available, the program should show the screen that the new customer will take the empty seat, and the
program should update the availability information of tables. If there is no seat available for this
customer, the customer should be put into the waiting line.
*/

/* ------------------------- logic for above command: ------------------------ */
/*
- If there is a large table available, the program should output to the screen that the new customer will
take the empty seat and update the availability information of tables.
- If there is no large table available, the customer should be put into the waiting line.

Enter Command: checkout large
No customer occupied any large table!

Enter Command: new large Edison
New customer Edison takes an available large table.

Enter Command: new large Luke
New customer Luke enters the large waiting line.
*/

/* ---------------------- new small <name of customer> ---------------------- */
/*
The user uses this command when there is a new customer that requests a small table. This is similar to
the above command.
*/

/* ------------------------ logic for above command: ------------------------ */
/*
- If there is a small table available, the program should output to the screen that the new customer will
take the empty seat and update the availability information of tables.

- If there is no small table available, the customer should be put into the waiting line.
*/

/* ----------------------------- checkout large ----------------------------- */
/*
The user uses this command when there is a large new table available from a customer checking out. If
there is a customer in the waiting line who should take this seat, the program should output to the screen
which customer will take the seat and update the availability information of tables and waiting lines.
*/

/* ------------------------ logic for above command: ------------------------ */
/*
- If there is a customer in the waiting line who should take this seat, the program should output to the
screen which customer will take the seat and update the availability information of tables and waiting
lines.

-Order is check large table waiting line first, if empty then check small table waiting line.

- If there is no customer in the waiting line, the program should output to the screen that the seat is
empty and update the availability information of tables.

Enter Command: checkout large
New large table seat(s) is available.
Next customer Luke takes an available large table.

Enter Command: checkout large
New large table seat(s) is available.
*/

/* ----------------------------- checkout small ----------------------------- */
/*
The user uses this command when there is a small new table available from a customer checking out.
Similar to the command above.
*/

/* ------------------------ logic for above command: ------------------------ */
/*
- If there is a customer in the waiting line who should take this seat, the program should output to the
screen which customer will take the seat and update the availability information of tables and waiting
lines.

- If there is no customer in the waiting line, the program should output to the screen that the seat is
empty and update the availability information of tables.
*/

/* ---------------------------------- info ---------------------------------- */
/*
The user uses this command to show on the screen the following information:
- The number of small/large tables currently taken.

- The number of customers in both the small/large table waiting line.
*/

/* ------------------------ logic for above command: ------------------------ */
/*
- The program should output to the screen the number of small/large tables currently taken and the
number of customers in both the small/large table waiting line.

Small tables: 0 / 3
Large tables: 2 / 2
0 customer(s) waiting for small table.
1 customer(s) waiting for large table.
*/

void handleNewCustomer(queue<string> &tableQueue, queue<string> &waitingLine, int &availableTables, const string &name, const string &tableType)
{
    if (availableTables > 0)
    {
        cout << "New customer " << name << " takes an available " << tableType << " table." << endl;
        availableTables--;
        tableQueue.push(name);
    }
    else
    {
        cout << "New customer " << name << " enters the " << tableType << " waiting line." << endl;
        waitingLine.push(name);
    }
}

int main()
{
    cout << "Welcome to the Restaurant Table Management System." << endl;

    int totalLargeTables, totalSmallTables;
    cout << "Enter the total number of large tables: ";
    do {
        cin >> totalLargeTables;
        if (totalLargeTables < 1) {
            cout << "Invalid input! Please enter a number greater than 0." << endl;
        }
    } while (totalLargeTables < 1);
    cout << "Enter the total number of small tables: ";
    do {
        cin >> totalSmallTables;
        if (totalSmallTables < 1) {
            cout << "Invalid input! Please enter a number greater than 0." << endl;
        }
    } while (totalSmallTables < 1);
    cin.ignore(); // To clear the newline character from the input buffer

    queue<string> largeWaitingLine;
    queue<string> smallWaitingLine;
    queue<string> largeTablequeue;
    queue<string> smallTablequeue;

    int largeTables = totalLargeTables;
    int smallTables = totalSmallTables;

    string command;
    while (true)
    {
        cout << "Enter Command: ";
        getline(cin, command);

        /* -------------------------------- NEW LARGE ------------------------------- */

        if (command.substr(0, 10) == "new large ") // Check if command starts with "new large ", checks the first 10 characters 
        {
            string name = command.substr(10); // Extract the name after "new large "
            if (name.empty())
            {
            cout << "Invalid command! Please provide a name after 'new large'." << endl;
            continue;
            }

            handleNewCustomer(largeTablequeue, largeWaitingLine, largeTables, name, "large");
        }
        /* -------------------------------------------------------------------------- */

        /* -------------------------------- NEW SMALL ------------------------------- */
        else if (command.substr(0, 10) == "new small ") // Check if command starts with "new small "
        {
            string name = command.substr(10); // Extract the name after "new small "
            if (name.empty())
            {
            cout << "Invalid command! Please provide a name after 'new small'." << endl;
            continue;
            }

            handleNewCustomer(smallTablequeue, smallWaitingLine, smallTables, name, "small");
        }
        /* -------------------------------------------------------------------------- */

        /* ----------------------------- CHECKOUT LARGE ----------------------------- */
        else if (command == "checkout large") // Check if command is "checkout large"
        {
            if (largeTablequeue.empty())
            {
            cout << "No customer occupied any large table!" << endl;
            largeTables++;
            }
            else
            {
            string currentCustomer = largeTablequeue.front();
            cout << "Customer " << currentCustomer << " has checked out from a large table." << endl;
            largeTablequeue.pop();

            if (!largeWaitingLine.empty())
            {
                string nextCustomer = largeWaitingLine.front();
                largeWaitingLine.pop();
                largeTablequeue.push(nextCustomer);
                cout << "Next customer " << nextCustomer << " takes an available large table." << endl;
            }
            else if (!smallWaitingLine.empty())
            {
                string nextCustomer = smallWaitingLine.front();
                smallWaitingLine.pop();
                largeTablequeue.push(nextCustomer);
                cout << "Next customer " << nextCustomer << " takes an available large table." << endl;
            }
            else
            {
                largeTables++;
            }
            }
        }
        /* -------------------------------------------------------------------------- */

        /* ----------------------------- CHECKOUT SMALL ----------------------------- */
        else if (command == "checkout small") // Check if command is "checkout small"
        {
            if (smallTablequeue.empty())
            {
            cout << "No customer occupied any small table!" << endl;
            smallTables++;
            }
            else
            {
            string currentCustomer = smallTablequeue.front();
            cout << "Customer " << currentCustomer << " has checked out from a small table." << endl;
            smallTablequeue.pop();

            if (!smallWaitingLine.empty())
            {
                string nextCustomer = smallWaitingLine.front();
                smallWaitingLine.pop();
                smallTablequeue.push(nextCustomer);
                cout << "Next customer " << nextCustomer << " takes an available small table." << endl;
            }
            else
            {
                smallTables++;
            }
            }
        }
        /* -------------------------------------------------------------------------- */

        /* ---------------------------------- INFO ---------------------------------- */
        else if (command == "info")
        {
            cout << "Small tables: " << totalSmallTables - smallTables << " / " << totalSmallTables << endl;
            cout << "Large tables: " << totalLargeTables - largeTables << " / " << totalLargeTables << endl;
            cout << smallWaitingLine.size() << " customer(s) waiting for small table." << endl;
            cout << largeWaitingLine.size() << " customer(s) waiting for large table." << endl;
        } /* ---------------------------------- EXIT ---------------------------------- */
        else if (command == "exit")
        {
            break;
        }
         /* -------------------------------------------------------------------------- */
        else
        {
            cout << "Invalid command!" << endl;
        }
        /* -------------------------------------------------------------------------- */

       
       
    }
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */
