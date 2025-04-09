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
// Assignment: InLab 10
//
#include <iostream>
#include <stack>

using namespace std;

/******************************************************************************
 * Node class declaration.
 * DO NOT modify.
******************************************************************************/

class Node {
public:
    int data;
    Node* next;
};

/******************************************************************************
* Function you have to implement
******************************************************************************/
//Recursion
bool testIncreasing(Node* first) {
    if (first == NULL || first->next == NULL) {
        return true;
    }
    if (first->data > first->next->data) {
        return false;
    }
    return testIncreasing(first->next);
}


/******************************************************************************
 * Functions that used by the driver.
 * DO NOT modify these functions.
******************************************************************************/

Node* CreateList(int* arr, int len) {
    if (len <= 0 || arr == NULL) {
        return NULL;
    }
    Node* head = new Node();
    head->data = arr[len - 1];
    head->next = NULL;
    for (int i = 1; i < len; i++) {
        Node* temp = new Node();
        temp->next = head;
        temp->data = arr[len - i - 1];
        head = temp;
    }
    return head;
}

void ShowList(Node* llist) {
    if (llist == NULL) {
        cout << "<<Empty Linked List>>" << endl;
        return;
    }
    Node* cur = llist;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void TestFunction(int* arr, int size) {
    cout << endl;
    cout << "Testing the Linked List:" << endl;
    Node* llist = CreateList(arr, size);
    ShowList(llist);
    bool testResult = testIncreasing(llist);
    if (testResult == true) {
        cout << "YES. The linked list is in increasing order." << endl;
    }
    else {
        cout << "NO. The linked list is NOT in increasing order." << endl;
    }

    cout << endl;
}

/******************************************************************************
 * Test driver main function.
 * Add your own test cases
 ******************************************************************************/

int main() {

    int a1[] = { 1,2,3,4,5,6,7 };
    TestFunction(a1, 7);

    TestFunction(NULL, 0);

    int a2[] = { 10 };
    TestFunction(a2, 1);

    int a3[] = { 10, 20, 25, 60, 100, 1000 };
    TestFunction(a3, 6);

    int a4[] = { 1, 4, 8, 12, 50, 45, 80, 100, 230, 585 };
    TestFunction(a4, 10);
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"LinkedListSkeleton"

Testing the Linked List:
1 2 3 4 5 6 7 
YES. The linked list is in increasing order.


Testing the Linked List:
<<Empty Linked List>>
YES. The linked list is in increasing order.


Testing the Linked List:
10 
YES. The linked list is in increasing order.


Testing the Linked List:
10 20 25 60 100 1000 
YES. The linked list is in increasing order.


Testing the Linked List:
1 4 8 12 50 45 80 100 230 585 
NO. The linked list is NOT in increasing order.

ryanreagle@Ryans-MacBook-Pro-2 output % 
*/
