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
// Assignment: InLab_7
//

#include <iostream>

using namespace std;

typedef int Type;

class Node
{
public:
    Type data;
    Node *next;
};

void insert(Node *&first, unsigned position, Type data);
int GetLength(Node *first);
bool GetElement(Node *first, int position, Type &data);
void InsertToSortedLinkedList(Node *&first, Type data);
/* -------------------------------------------------------------------------- */
/*                                     NEW                                    */
/* -------------------------------------------------------------------------- */
int GetLength(Node *first)
{
    int length = 0;
    Node *cur = first;
    while (cur != NULL)
    {
        length++;
        cur = cur->next;
    }
    return length;
}

bool GetElement(Node *first, int position, Type &data)
{
    if (position < 0)
    {
        return false;
    }
    Node *cur = first;
    int currentIndex = 0;
    while (cur != NULL)
    {
        if (currentIndex == position)
        {
            data = cur->data;
            return true;
        }
        cur = cur->next;
        currentIndex++;
    }
    return false;
}

void InsertToSortedLinkedList(Node *&first, Type data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL)
    {
        first = newNode;
        return;
    }

    if (data < first->data)
    {
        newNode->next = first;
        first = newNode;
        return;
    }

    Node *prev = first;
    Node *cur = first->next;
    while (cur != NULL)
    {
        if (data < cur->data)
        {
            prev->next = newNode;
            newNode->next = cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = newNode;
}

/* -------------------------------------------------------------------------- */
/*                                    GIVEN                                   */
/* -------------------------------------------------------------------------- */

void insert(Node *&first, unsigned position, Type data)
{
    if (position == 0)
    {
        Node *temp = first;
        first = new Node;
        first->data = data;
        first->next = temp;
    }
    else
    {
        Node *prev = first;
        int currentIndex = 1;
        while (currentIndex < position)
        {
            prev = prev->next;
            currentIndex++;
        }
        Node *temp = prev->next;
        prev->next = new Node;
        prev->next->data = data;
        prev->next->next = temp;
    }
}

void display(Node *first)
{
    Node *cur = first;
    while (cur != NULL)
    {
        cout << (cur->data) << " ";
        cur = cur->next;
    }
    cout << endl;
}

void remove(Node *&first, unsigned position)
{
    if (position == 0)
    {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
    else
    {
        Node *prev = first;
        int currentIndex = 1;
        while (currentIndex < position)
        {
            prev = prev->next;
            currentIndex++;
        }
        Node *temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }
}

Node *NewLinkedList(Type *arr, unsigned size)
{
    Node *first = NULL;
    for (int i = size - 1; i >= 0; i--)
    {
        insert(first, 0, arr[i]);
    }

    return first;
}

int main()
{
    Type data;
    {
        cout << "Given linked list: ";
        Type arr[] = {10, 4, 2, 6, 42, 50};
        Node *first = NewLinkedList(arr, 6);

        display(first);
        cout << "The length is " << GetLength(first) << endl;
        if (GetElement(first, 3, data))
            cout << "Element at position " << 3 << " is " << data << endl;
        else
            cout << "Failed to find data at position 3" << endl;
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = {5, 2, 6, 4, 6};
        Node *first = NewLinkedList(arr, 5);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        if (GetElement(first, 0, data))
            cout << "Element at position " << 0 << " is " << data << endl;
        else
            cout << "Failed to find data at position 0" << endl;
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = {1, 3, 5, 7, 9, 11, 53, 70};
        Node *first = NewLinkedList(arr, 8);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        if (GetElement(first, 7, data))
            cout << "Element at position " << 7 << " is " << data << endl;
        else
            cout << "Failed to find data at position 7" << endl;
        cout << endl;

        if (GetElement(first, 8, data))
            cout << "Element at position " << 8 << " is " << data << endl;
        else
            cout << "Failed to find data at position 8" << endl;
        cout << endl;

        cout << "Try to insert 8 into this linked list, the list becomes:" << endl;
        InsertToSortedLinkedList(first, 8);
        display(first);
        cout << endl;

        cout << "Try to insert 0 into this linked list, the list becomes:" << endl;
        InsertToSortedLinkedList(first, 0);
        display(first);
        cout << endl;

        cout << "Try to insert 100 into this linked list, the list becomes:" << endl;
        InsertToSortedLinkedList(first, 100);
        display(first);
        cout << endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"llist"
Given linked list: 10 4 2 6 42 50
The length is 6
Element at position 3 is 6

Given linked list: 5 2 6 4 6
The length is 5
Element at position 0 is 5

Given linked list: 1 3 5 7 9 11 53 70
The length is 8
Element at position 7 is 70

Failed to find data at position 8

Try to insert 8 into this linked list, the list becomes:
1 3 5 7 8 9 11 53 70

Try to insert 0 into this linked list, the list becomes:
0 1 3 5 7 8 9 11 53 70

Try to insert 100 into this linked list, the list becomes:
0 1 3 5 7 8 9 11 53 70 100

ryanreagle@Ryans-MacBook-Pro-2 output %
*/