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

// Template class for a Node in the linked list
template <class T>
class Node {
    public:
    T data;          // Data stored in the node
    Node* next;      // Pointer to the next node
};

// Template class for a LinkedList
template <class T>
class LinkedList {
    public:
    Node<T>* head;   // Pointer to the head of the linked list

    // Constructor to initialize an empty linked list
    LinkedList() {
        head = NULL;
    }

    // Method to append a new node at the end of the linked list
    void append(T data) {
        Node<T>* newNode = new Node<T>(); // Create a new node
        newNode->data = data;             // Set the data
        newNode->next = NULL;             // Set the next pointer to NULL

        if (head == NULL) {               // If the list is empty
            head = newNode;               // Set the new node as the head
        } else {
            Node<T>* last = head;         // Traverse to the last node
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;         // Link the new node at the end
        }
    }

    // Method to push a new node at the beginning of the linked list
    void push(T data) {
        Node<T>* newNode = new Node<T>(); // Create a new node
        newNode->data = data;             // Set the data
        newNode->next = head;             // Link the new node to the current head
        head = newNode;                   // Update the head to the new node
    }

    // Method to insert a new node after a given node
    void insertAfter(Node<T>* prevNode, T data) {
        if (prevNode == NULL) {           // Check if the previous node is NULL
            cout << "Previous node cannot be NULL\n";
            return;
        }
        Node<T>* newNode = new Node<T>(); // Create a new node
        newNode->data = data;             // Set the data
        newNode->next = prevNode->next;   // Link the new node to the next of prevNode
        prevNode->next = newNode;         // Update the next of prevNode to the new node
    }

    // Method to print the linked list
    void printList() {
        Node<T>* n = head;                // Start from the head
        while (n) {                       // Traverse the list
            cout << n->data << " ";       // Print the data of each node
            n = n->next;                  // Move to the next node
        }
    }
};

int main() {
    // Create a linked list of integers
    LinkedList<int> list;


    // Append and push elements to the linked list
    list.append(6);                       // Append 6 to the list
    list.push(7);                         // Push 7 to the beginning of the list
    list.push(1);                         // Push 1 to the beginning of the list
    list.append(4);                       // Append 4 to the list
    list.insertAfter(list.head->next, 8); // Insert 8 after the second node

    // Print the linked list
    list.printList();                     // Output: 1 7 8 6 4

    cout << endl;

    return 0;
}
