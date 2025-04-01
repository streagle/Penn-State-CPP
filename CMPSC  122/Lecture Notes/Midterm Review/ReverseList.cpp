#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while(current != nullptr){
        next = current->next; //Update next to point to the next node
        current->next = prev; //Update the current node to point to the previous node
        prev=current; //Move prev to the current node
        current=next; //Move current to the next node
    }
    return prev;
}

int main(){

    Node* head = nullptr;
    Node* tail = nullptr;

    int values[] = {2, 6, 8, 10, 5, 9};
    for (int value : values) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }



    Node* reversed = reverseList(head);

    while(reversed != nullptr){
        cout << reversed->data << " ";
        reversed = reversed->next;
    }

    return 0;


}