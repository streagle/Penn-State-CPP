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



 
// Define the structure for a node in the linked list

struct Node {
    int data;
    Node* next;
};

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data) {
    if (!prev_node) {
        cout << "Previous node cannot be NULL\n";
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;
    if (!*head_ref) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next) last = last->next;
    last->next = new_node;
}

void deleteNode(Node** head_ref, int key) {
    Node *temp = *head_ref, *prev = nullptr;
    if (temp && temp->data == key) {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp) {
        prev->next = temp->next;
        delete temp;
    }
}

void insertAfterNumber(Node** head_ref, int number, int new_data) {
    Node* temp = *head_ref;
    while (temp) {
        if (temp->data == number) {
            insertAfter(temp, new_data);
            return;
        }
        temp = temp->next;
    }
    cout << "Number " << number << " not found\n";
}

void displayList(Node* n) {
    while (n) {
        cout << n->data << " -> " << (n->next ? to_string(n->next->data) : "NULL") << endl;
        n = n->next;
    }
}

void insertBeforeNumber(Node** head_ref, int number, int new_data) {
    Node *temp = *head_ref, *prev = nullptr;
    while (temp) {
        if (temp->data == number) {
            if (!prev) push(head_ref, new_data);
            else insertAfter(prev, new_data);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Number " << number << " not found\n";
}

void insertAfterPosition(Node** head_ref, int position, int new_data) {
    Node* temp = *head_ref;
    for (int i = 1; temp && i < position; i++) temp = temp->next;
    if (!temp) {
        cout << "Position " << position << " not found\n";
        return;
    }
    insertAfter(temp, new_data);
}


void options(){
    cout << "1. Insert a node at the beginning of the linked list" << endl;
    cout << "2. Insert a node after a given number" << endl;
    cout << "3. Insert a node at the end of the linked list" << endl;
    cout << "4. Delete a node from the linked list" << endl;
    cout << "5. Insert a node before a given number" << endl;
    cout << "6. Display each list and fill in the next pointer with what its pointing to in a new line" << endl;
    cout << "7. Exit" << endl;
    cout << "8. Insert a node after a given position" << endl;
}

int main(){
    int deleteNumber;
    int insertAfterNum;
    int insertNumber;
    bool loop = true;

    /* ------------------------------ creating list ----------------------------- */

    Node* head = NULL; // Start with the empty list
    append(&head, 6); // Insert 6 at the end
    push(&head, 7); // Insert 7 at the beginning [6 -> 7]
    push(&head, 1); // Insert 1 at the beginning [1 -> 6 -> 7]
    append(&head, 4); // Insert 4 at the end [1 -> 6 -> 7 -> 4]
    insertAfter(head->next, 8); // Insert 8 after the second node [1 -> 6 -> 8 -> 7 -> 4]



    /* -------------------------- end of creating list -------------------------- */


    /* ----------------------------- start of output ---------------------------- */

    cout << "Created linked list is: ";
    printList(head); //
    cout << endl;


    while(loop){
        int choice;
        options();
        
        cout << "--------------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the number you want to insert at the beginning: ";
                cin >> insertNumber;
                push(&head, insertNumber);
                cout << "Updated linked list is: ";
                printList(head);
                cout << endl;
                break;
            case 2:
                cout << "Enter the number you want to insert after: ";
                cin >> insertAfterNum;
                cout << "Enter the number you want to insert: ";
                cin >> insertNumber;
                insertAfterNumber(&head, insertAfterNum, insertNumber);
                cout << "Updated linked list is: ";
                printList(head);
                cout << endl;
                break;
            case 3:
                cout << "Enter the number you want to insert at the end: ";
                cin >> insertNumber;
                append(&head, insertNumber);
                cout << "Updated linked list is: ";
                printList(head);
                cout << endl;
                break;
            case 4:
                cout << "Enter the number you want to delete: ";
                cin >> deleteNumber;
                deleteNode(&head, deleteNumber);
                cout << "Updated linked list is: ";
                printList(head);
                cout << endl;
                break;
            case 5:
                cout << "Enter the number you want to insert before: ";
                cin >> insertAfterNum;
                cout << "Enter the number you want to insert: ";
                cin >> insertNumber;
                insertBeforeNumber(&head, insertAfterNum, insertNumber);
                cout << "Updated linked list is: ";
                printList(head);
                cout << endl;
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                loop = false;
                break;
            case 8:
                int position;
                cout << "Enter the position you want to insert after: ";
                cin >> position;
                cout << "Enter the number you want to insert: ";
                cin >> insertNumber;
                insertAfterPosition(&head, position, insertNumber);
                cout << "Updated linked list is: ";
                printList(head);
                cout << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        cout << "--------------------------------" << endl;
        
        
    }




    /* ------------------------------ end of output ----------------------------- */
    //clear memory
    Node* temp = head;
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}

